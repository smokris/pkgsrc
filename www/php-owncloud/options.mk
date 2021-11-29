# $NetBSD: options.mk,v 1.9 2021/03/04 16:42:44 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-owncloud

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite3 pgsql

PKG_SUGGESTED_OPTIONS=	sqlite3

.include "../../mk/bsd.options.mk"

###
### Use mysql, pgsql, or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.0:../../databases/php-pdo_mysql
.elif !empty(PKG_OPTIONS:Msqlite3)
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite3>=5.4.0:../../databases/php-sqlite3
# php-pdo_sqlite provides sqlite3.  An owncloud instance that was
# installed as version 2 and upgraded to 3 and then 4
# complained/failed that PDO was not present.
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.4.0:../../databases/php-pdo_sqlite
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql*-[0-9]*:../../databases/php-pdo_pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql*-[0-9]*:../../databases/php-pgsql
.endif
