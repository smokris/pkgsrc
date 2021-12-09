# $NetBSD: buildlink3.mk,v 1.25 2021/12/08 16:02:33 adam Exp $

BUILDLINK_TREE+=	kauth

.if !defined(KAUTH_BUILDLINK3_MK)
KAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kauth+=	kauth>=5.19.0
BUILDLINK_ABI_DEPENDS.kauth?=	kauth>=5.80.0nb3
BUILDLINK_PKGSRCDIR.kauth?=	../../security/kauth

BUILDLINK_FILES.kauth+=		libexec/kauth/*
BUILDLINK_FILES.kauth+=		share/kf5/kauth/dbus*.stub

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-kauth
