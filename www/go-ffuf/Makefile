# $NetBSD: Makefile,v 1.18 2021/10/08 18:55:06 bsiegert Exp $

DISTNAME=		go-ffuf-1.2.1
PKGREVISION=		7
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ffuf/}
GITHUB_PROJECT=		ffuf
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ffuf/ffuf/
COMMENT=		Fast web fuzzer
LICENSE=		mit

INSTALLATION_DIRS+=	bin share/doc/go-ffuf

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/ffuf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/go-ffuf

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
