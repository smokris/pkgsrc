# $NetBSD: buildlink3.mk,v 1.22 2021/12/08 16:02:54 adam Exp $

BUILDLINK_TREE+=	kwidgetsaddons

.if !defined(KWIDGETSADDONS_BUILDLINK3_MK)
KWIDGETSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwidgetsaddons+=	kwidgetsaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kwidgetsaddons?=	kwidgetsaddons>=5.80.0nb3
BUILDLINK_PKGSRCDIR.kwidgetsaddons?=	../../x11/kwidgetsaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWIDGETSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwidgetsaddons
