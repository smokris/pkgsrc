# $NetBSD: Makefile,v 1.16 2021/09/29 19:01:06 adam Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-freetds/}
COMMENT=	Free RADIUS FreeTDS support

CONFIGURE_ARGS+=	--with-rlm_sql_freetds
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
