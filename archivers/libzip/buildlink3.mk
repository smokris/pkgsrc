# $NetBSD: buildlink3.mk,v 1.27 2021/09/29 19:00:02 adam Exp $

BUILDLINK_TREE+=	libzip

.if !defined(LIBZIP_BUILDLINK3_MK)
LIBZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.3.1
BUILDLINK_ABI_DEPENDS.libzip+=	libzip>=1.8.0nb1
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip

BUILDLINK_FILES.libzip+=	bin/zipcmp
BUILDLINK_FILES.libzip+=	bin/zipmerge
BUILDLINK_FILES.libzip+=	bin/ziptool

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"
pkgbase := libzip
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libzip:Mgnutls}
.include "../../security/gnutls/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libzip:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # LIBZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzip
