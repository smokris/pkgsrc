# $NetBSD: options.mk,v 1.1 2021/12/06 15:33:27 abs Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.unifi
PKG_OPTIONS_GROUP.mongodb=	mongodb3 mongodb4
PKG_OPTIONS_REQUIRED_GROUPS=	mongodb
PKG_SUGGESTED_OPTIONS=		mongodb3

.include "../../mk/bsd.options.mk"

# Upstream recommends 3.6, but 3.4.4 is the last version before the
# switch to server-side-public-license, and works fine
.if !empty(PKG_OPTIONS:Mmongodb3)
DEPENDS+=		mongodb>=3.4.4:../../databases/mongodb3
.endif

# For those happy with server-side-public-license
# Note a backup/restore is required when switching versions
.if !empty(PKG_OPTIONS:Mmongodb4)
DEPENDS+=		mongodb>=4.0:../../databases/mongodb
.endif
