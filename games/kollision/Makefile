# $NetBSD: Makefile,v 1.47 2021/07/30 12:26:52 ryoon Exp $

DISTNAME=	kollision-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kollision/
COMMENT=	Simple ball dodging game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
