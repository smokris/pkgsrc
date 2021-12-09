# $NetBSD: buildlink3.mk,v 1.48 2021/12/08 16:02:26 adam Exp $

BUILDLINK_TREE+=	avahi

.if !defined(AVAHI_BUILDLINK3_MK)
AVAHI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avahi+=	avahi>=0.6.23
BUILDLINK_ABI_DEPENDS.avahi+=	avahi>=0.8nb4
BUILDLINK_PKGSRCDIR.avahi?=	../../net/avahi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # AVAHI_BUILDLINK3_MK

BUILDLINK_TREE+=	-avahi
