# $NetBSD: Makefile,v 1.57 2021/08/10 12:03:37 nia Exp $

DISTNAME=	gajim-1.3.2
CATEGORIES=	chat
MASTER_SITES=	https://www.gajim.org/downloads/${PKGVERSION_NOREV:R}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gajim.org/
COMMENT=	XMPP/Jabber chat client written in Python/GTK3
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gettext

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# needs --desktop
TOOLS_PLATFORM.msgfmt=
.endif

MANCOMPRESSED=	yes
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

DEPENDS+=	${PYPKGPREFIX}-cairo>=1.16.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp>=2.0.1:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-precis-i18n-[0-9]*:../../textproc/py-precis-i18n
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
.endif

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
