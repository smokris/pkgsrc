# $NetBSD: Makefile,v 1.50 2021/09/12 08:40:44 nia Exp $

DISTNAME=	virt-manager-0.9.4
PKGREVISION=	35
CATEGORIES=	sysutils
MASTER_SITES=	http://virt-manager.org/download/sources/virt-manager/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://virt-manager.org/
COMMENT=	GUI to manage virtual machines
LICENSE=	gnu-gpl-v2

BROKEN+=	"Lack of libvirt Python bindings, needs work"

DEPENDS=	libvirt>=0.9.3:../../sysutils/libvirt
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.24:../../x11/py-gtk2
DEPENDS+=	virtinst>=0.600.3:../../sysutils/virtinst
DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.8.0:../../textproc/py-libxml2
DEPENDS+=	urlgrabber>=3.1.0:../../www/urlgrabber
DEPENDS+=	${PYPKGPREFIX}-dbus>=1.1.1:../../sysutils/py-dbus
DEPENDS+=	gtk-vnc>=0.5.1:../../net/gtk-vnc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libvirt-package-names=libvirt

USE_TOOLS+=		gmake intltool msgfmt
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=	virt-manager.schemas

PYTHON_VERSIONS_ACCEPTED=	27 # py-ORBit via py-gnome2, py-gtk2

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing hard-coded config file paths.
SUBST_FILES.python=	src/virt-manager.in src/virt-manager-tui.in src/virt-manager-launch.in
SUBST_SED.python=	-e 's,@@PYTHONBIN@@,${PYTHONBIN},'

REPLACE_PYTHON=		src/virtManagerTui/startnetwork.py

.include "../../lang/python/application.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
