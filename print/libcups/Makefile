# $NetBSD: Makefile,v 1.12 2021/09/29 19:00:12 adam Exp $

PKGREVISION= 2
.include "../../print/cups/Makefile.common"

PKGNAME=	libcups-${CUPS_VERS}
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}

MAINTAINER=	sbd@NetBSD.org
COMMENT=	Common UNIX Printing System library

DISTINFO_FILE?=	${.CURDIR}/../../print/cups-base/distinfo
PATCHDIR?=	${.CURDIR}/../../print/cups-base/patches

GITHUB_PROJECT=	cups
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

CONFLICTS+=	LPRng-[0-9]* LPRng-core-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
UNLIMIT_RESOURCES=	datasize memorysize
USE_LANGUAGES=		c c++	# pdftops is a C++ application
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-cachedir=${CUPS_CACHE:Q}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/cups
CONFIGURE_ARGS+=	--with-serverbindir=${PREFIX}/libexec/cups
CONFIGURE_ARGS+=	--with-components=libcups
CONFIGURE_ARGS+=	--enable-libpaper
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+=	--disable-cdsassl
CONFIGURE_ARGS+=	--with-exe-file-perm=0755

CONFIGURE_ENV+=		DSOFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILD_DEFS+=		VARBASE

# Explicitly disable epoll on illumos, it is provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_create=no

LIBS+=			${BUILDLINK_LDADD.iconv}

# Avoid the following error when compiling with clang.
# /usr/local/bin/ld: /usr/lib/crt1.o: relocation R_X86_64_32 against `_DYNAMIC'
# can not be used when making a shared object; recompile with -fPIC
BUILDLINK_TRANSFORM.FreeBSD+=	rm:-Wl,-pie

PKG_SYSCONFSUBDIR=	cups
CUPS_CACHE=		${VARBASE}/cache/cups

.if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == powerpc
SUBST_CLASSES+=		piefix
SUBST_FILES.piefix=	Makedefs.in
SUBST_MESSAGE.piefix=	Removing PIE flags
SUBST_SED.piefix=	-e 's|@PIEFLAGS@||g'
SUBST_STAGE.piefix=	pre-configure
.endif

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
