# $NetBSD: Makefile,v 1.63 2021/09/29 19:01:29 adam Exp $

DISTNAME=	snownews-1.8
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=msharov/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msharov/snownews
COMMENT=	Small, curses based RSS feed reader
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake msgfmt pkg-config
HAS_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	wide

LDFLAGS+=	${BUILDLINK_LDADD.curses}

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
