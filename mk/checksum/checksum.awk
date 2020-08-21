#!/usr/bin/awk -f
#
# $NetBSD$
#
###########################################################################
#
# NAME
#	checksum.awk -- checksum files
#
# SYNOPSIS
#	checksum.awk [options] distinfo [file ...]
#
# DESCRIPTION
#	checksum will verify the checksums in the distinfo file for each
#	of the files specified.
#
#	The checksum utility exits with one of the following values:
#
#	0	All of the file checksums verify.
#
#	1	At least one of the file checksums did not match.
#
#	2	At least one of the files is missing any checksum.
#
#	>2	An error occurred.
#
# OPTIONS
#	-a algorithm	Only verify checksums for the specified algorithm.
#
#	-p		The specified files are patches, so strip out any
#			lines containing NetBSD RCS ID tags before
#			computing the checksums for verification.
#
#	-s suffix	Strip the specified suffix from the file names
#			when searching for the checksum.
#
#
# BUGS
#	The flow of this program is not performed in the most optimal way
#	possible, as it was deemed important to retain output compatibility
#	with the previous shell script implementation.
#

BEGIN {
	DIGEST = ENVIRON["DIGEST"] ? ENVIRON["DIGEST"] : "digest"
	SED = ENVIRON["SED"] ? ENVIRON["SED"] : "sed"

	# Retain output compatible with previous "checksum" shell script
	self = "checksum"

	a_flag = ""
	distinfo = ""
	exitcode = 0
	patch = 0
	suffix = ""

	for (arg = 1; arg < ARGC; arg++) {
		opt = ARGV[arg]
		if (opt == "-a") {
			a_flag = ARGV[++arg]
		} else if (opt == "-p") {
			patch = 1
		} else if (opt == "-s") {
			suffix = ARGV[++arg]
		} else if (opt == "--") {
			arg++
			break
		} else if (match(opt, /^-.*/) != 0) {
			opt = substr(opt, RSTART + 1, RLENGTH)
			print self ": unknown option -- " opt > "/dev/stderr"
			usage()
			exit 1
		} else {
			break
		}
	}

	if (arg > ARGC) {
		print self ": missing distinfo"
		usage()
		exit 1
	}

	distinfo = ARGV[arg++]
	cmd = "test -f " distinfo
	if (system(cmd) != 0) {
		print self ": " distinfo " not found"
		usage()
		exit 128
	}

	#
	# Initialise list of files to check, passed on the command line.  In
	# order to keep things simple, distfiles[] is also used when operating
	# in patch mode (-p).
	#
	while (arg < ARGC) {
		distfile = ARGV[arg++]
		sfile = distfile
		if (suffix) {
			sub(suffix "$", "", sfile)
		}
		if (patch) {
			gsub(/.*\//, "", sfile)
		}

		#
		# Have we seen this file in distinfo?  Used later to verify
		# that all checksums have been recorded.
		#
		seen[sfile] = 0

		#
		# Store the filename to be checked in the distinfo file.  The
		# -s flag allows temporary download files to be tested instead,
		# where the suffix will be stripped to match distinfo.
		#
		distfiles[sfile] = distfile
	}

	#
	# Parse the distinfo file for checksums that must be verified.  We're
	# only interested in lines of the format:
	#
	#	algorithm (distfile) = checksum
	#
	while (getline < distinfo) {
		if (NF != 4) {
			continue
		}
		if ($0 ~ /^(\#|\$|Size)/) {
			continue
		}

		algorithm = $1
		distfile = substr($2, 2, (length($2) - 2)) # strip ()
		checksum = $4

		# Skip IGNORE lines (likely legacy at this point).
		if (checksum == "IGNORE") {
			continue
		}

		# If -a is set then skip non-matching algorithms.
		if (a_flag && tolower(algorithm) != tolower(a_flag)) {
			continue
		}

		# Skip if file not in distfiles.
		if (!(distfile in distfiles)) {
			continue
		}

		#
		# Handle patch files inline.  As they need to be modified (by
		# removing the $NetBSD$) they are parsed individually by
		# digest(1), and so we calculate the checksums now rather than
		# saving for later processing to simplify things.
		#
		if (patch) {
			patchfile = distfiles[distfile]
			cmd = SED " -e '/[$]NetBSD.*/d' " patchfile " | " \
			    DIGEST " " algorithm
			while ((cmd | getline) > 0) {
				checksums[algorithm, distfile] = $1
			}
			close(cmd)
			continue
		}

		#
		# If not a patch file, then we're handling a distfile, where we
		# want to build a list of input files to digest(1) so they can
		# all be calculated in one go.
		#
		distsums[algorithm] = distsums[algorithm] " " distfiles[distfile]
	}
	close(distinfo)

	#
	# We now have a list of distfiles to be checked for each algorithm,
	# pass them all to a single digest(1) command and parse the checksums
	# to be compared against distinfo.
	#
	for (algorithm in distsums) {
		cmd = DIGEST " " algorithm " " distsums[algorithm]
		while ((cmd | getline) > 0) {
			# Should be unnecessary, but just in case.  If we want
			# to be really paranoid then test that $1 == algorithm.
			if (NF != 4) {
				continue
			}
			distfile = substr($2, 2, length($2) - 2)
			checksums[$1, distfile] = $4
		}
		close(cmd)
	}

	#
	# Now that we have computed all the necessary checksums for all of the
	# files listed on the command line, go back through distinfo and verify
	# that they all match.
	#
	while (getline < distinfo) {
		if (NF != 4) {
			continue
		}
		if ($0 ~ /^(\#|\$|Size)/) {
			continue
		}

		algorithm = $1
		distfile = substr($2, 2, (length($2) - 2)) # strip ()
		checksum = $4

		# If -a is set then skip non-matching algorithms.
		if (a_flag && tolower(algorithm) != tolower(a_flag)) {
			continue
		}

		# Skip if file not in distfiles.
		if (!(distfile in distfiles)) {
			continue
		}

		# This is likely very legacy at this point.
		if (checksum == "IGNORE") {
			print self ": Ignoring checksum for " distfile
			continue
		}

		if (checksums[algorithm,distfile] == checksum) {
			print "=> Checksum " algorithm " OK for " distfile
			seen[distfile] = 1
		} else {
			print self ": Checksum " algorithm " mismatch for " distfile >"/dev/stderr"
			exit 1
		}
	}
	close(distinfo)

	#
	# Check that all distfiles supplied on the command line have at least
	# one matching checksum.
	#
	for (distfile in distfiles) {
		if (seen[distfile] == 0) {
			if (a_flag) {
				print self ": No " a_flag \
				    " checksum recorded for " distfile \
				    > "/dev/stderr"
			} else {
				print self ": No checksum recorded for " \
				    distfile > "/dev/stderr"
			}
			exitcode = 2
		}
	}

	exit(exitcode)
}

function usage() {
	print "usage: " self \
	     " -- [-a algorithm] [-p] [-s suffix] distinfo [file ...]" \
	     > "/dev/stderr"
}
