# $NetBSD: buildlink3.mk,v 1.22 2021/12/08 16:02:39 adam Exp $

BUILDLINK_TREE+=	kdbusaddons

.if !defined(KDBUSADDONS_BUILDLINK3_MK)
KDBUSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdbusaddons+=	kdbusaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kdbusaddons?=	kdbusaddons>=5.80.0nb3
BUILDLINK_PKGSRCDIR.kdbusaddons?=	../../sysutils/kdbusaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KDBUSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdbusaddons
