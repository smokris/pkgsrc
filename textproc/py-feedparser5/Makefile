# $NetBSD: Makefile,v 1.3 2021/12/06 15:11:25 wiz Exp $

DISTNAME=		feedparser-5.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/feedparser/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/feedparser
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

PREV_PKGPATH=		textproc/py-feedparser

USE_LANGUAGES=		#none

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs feedparser/f*py
.endif

do-test:
	cd ${WRKSRC}/feedparser && ${PYTHONBIN} feedparsertest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
