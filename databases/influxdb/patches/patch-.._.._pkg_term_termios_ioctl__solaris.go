$NetBSD$

Apply SunOS fix from https://github.com/pkg/term/pull/41

--- ../../pkg/term/termios/ioctl_solaris.go.orig	2018-07-30 02:16:39.000000000 +0000
+++ ../../pkg/term/termios/ioctl_solaris.go
@@ -3,5 +3,5 @@ package termios
 import "golang.org/x/sys/unix"
 
 func ioctl(fd, request, argp uintptr) error {
-	return unix.IoctlSetInt(int(fd), int(request), int(argp))
+	return unix.IoctlSetInt(int(fd), uint(request), int(argp))
 }
