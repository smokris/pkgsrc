# $NetBSD: Makefile,v 1.11 2021/08/05 08:44:17 pin Exp $

DISTNAME=	phetch-1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=xvxx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/xvxx/phetch/
COMMENT=	Quick lil gopher client for your terminal
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/phetch ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/phetch.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
