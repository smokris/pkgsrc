# $NetBSD: Makefile,v 1.2 2021/08/03 08:53:47 pin Exp $

DISTNAME=	deckster-0.2.1
CATEGORIES=	misc
MASTER_SITES=	https://gitlab.com/prince_bett/deckster/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/prince_bett/deckster/
COMMENT=	TUI to study flashcards in the terminal
LICENSE=	mit

WRKSRC=		${WRKDIR}/deckster-v0.2.1-36735a7ca9698e48541da981ef5ccc8978fe9f58

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/deckster ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
