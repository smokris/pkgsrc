# $NetBSD: Makefile,v 1.71 2021/09/29 19:01:26 adam Exp $

DISTNAME=		elinks-0.12pre6
PKGNAME=		${DISTNAME:S/pre/rc/}
PKGREVISION=		18
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
MASTER_SITES+=		http://ftp.icm.edu.pl/packages/elinks/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ARGS+=	--enable-utf-8
CONFIGURE_ARGS+=	--without-lzma
CONFIGURE_ARGS+=	--without-lua

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
