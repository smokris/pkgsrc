# $NetBSD: Makefile,v 1.3 2021/07/28 21:34:03 fcambus Exp $

DISTNAME=	mimalloc-2.0.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/mimalloc/
COMMENT=	General-purpose allocator with excellent performance characteristics
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DMI_INSTALL_TOPLEVEL=ON

INSTALLATION_DIRS+=	lib/cmake/mimalloc

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mimalloc.o
	${MV} ${DESTDIR}${PREFIX}/cmake/*.cmake ${DESTDIR}${PREFIX}/lib/cmake/mimalloc

.include "../../mk/bsd.pkg.mk"
