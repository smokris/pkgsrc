# $NetBSD: buildlink3.mk,v 1.36 2021/12/08 16:02:18 adam Exp $

BUILDLINK_TREE+=	akonadi

.if !defined(AKONADI_BUILDLINK3_MK)
AKONADI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=0.82.0
BUILDLINK_ABI_DEPENDS.akonadi+=	akonadi>=1.13.0nb40
BUILDLINK_PKGSRCDIR.akonadi?=	../../mail/akonadi

BUILDLINK_FILES.akonadi+=	lib/cmake/Akonadi/* \
				share/config/akonadi/*.conf \
				share/dbus-1/interfaces/org.freedesktop.Akonadi* \
				share/dbus-1/services/org.freedesktop.Akonadi* \
				share/mime/packages/akonadi*

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # AKONADI_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi
