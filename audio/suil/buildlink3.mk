# $NetBSD: buildlink3.mk,v 1.15 2021/12/08 16:01:45 adam Exp $

BUILDLINK_TREE+=	suil

.if !defined(SUIL_BUILDLINK3_MK)
SUIL_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.suil+=	suil>=0.10.10
BUILDLINK_API_DEPENDS.suil+=	suil>=0.8.2
BUILDLINK_PKGSRCDIR.suil?=	../../audio/suil

.include "../../audio/lv2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# SUIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-suil
