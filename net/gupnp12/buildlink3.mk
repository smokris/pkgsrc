# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:27 adam Exp $

BUILDLINK_TREE+=	gupnp12

.if !defined(GUPNP12_BUILDLINK3_MK)
GUPNP12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp12+=	gupnp12>=1.2
BUILDLINK_ABI_DEPENDS.gupnp12?=	gupnp12>=1.2.2nb7
BUILDLINK_PKGSRCDIR.gupnp12?=	../../net/gupnp12

.include "../../mk/bsd.fast.prefs.mk"
.if (!empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin") && (!defined(USE_INTERNAL_UUID) || empty(USE_INTERNAL_UUID:M[Yy][Ee][Ss]))
pre-configure:
	if ! ${TEST} -e ${BUILDLINK_DIR}/lib/pkgconfig/uuid.pc; then cp ${BUILDLINK_PKGSRCDIR.gupnp12}/files/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/uuid.pc; fi
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/gssdp12/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GUPNP12_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp12
