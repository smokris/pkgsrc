# $NetBSD: Makefile,v 1.5 2021/09/29 09:10:32 wiz Exp $

DISTNAME=	libhandy-1.0.1
PKGNAME=	${DISTNAME:S/libhandy/libhandy1/1}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libhandy/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libhandy/
COMMENT=	Building blocks for modern adaptive GNOME apps
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config xgettext

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
# MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libhandy-1.pc

BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
