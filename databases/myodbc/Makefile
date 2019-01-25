# $NetBSD: Makefile,v 1.41 2017/09/03 08:53:05 wiz Exp $

DISTNAME=	mysql-connector-odbc-5.3.11-src
PKGNAME=	${DISTNAME:S/mysql-connector-odbc/myodbc/:S/-src$//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-ODBC/5.3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mysql.com/
COMMENT=	ODBC driver (server side) for MySQL
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS=	-Wno-dev
CMAKE_ARGS+=	-DMYSQLCLIENT_STATIC_LINKING=TRUE

INSTALLATION_DIRS=	share/doc/mysql-connector-odbc
INSTALLATION_DIRS+=	share/mysql-connector-odbc/test

.include "options.mk"

# The source is fussy about which version it links against, but as we link
# statically we can ensure it's only a build dependency so the package can
# be used against other versions.
MYSQL_VERSIONS_ACCEPTED=		57
BUILDLINK_DEPMETHOD.mysql-client=	build

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
