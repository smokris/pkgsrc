# $NetBSD: Makefile,v 1.14 2021/10/12 18:52:58 adam Exp $

DISTNAME=	django-admin-sortable2-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-admin-sortable2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jrief/django-admin-sortable2
COMMENT=	Generic drag-and-drop sorting for Views in the Django Admin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
