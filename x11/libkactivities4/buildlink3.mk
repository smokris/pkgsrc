# $NetBSD: buildlink3.mk,v 1.24 2021/09/29 19:00:16 adam Exp $

BUILDLINK_TREE+=	libkactivities4

.if !defined(LIBKACTIVITIES4_BUILDLINK3_MK)
LIBKACTIVITIES4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkactivities4+=	libkactivities4>=4.7.95
BUILDLINK_ABI_DEPENDS.libkactivities4+=	libkactivities4>=4.13.3nb24
BUILDLINK_PKGSRCDIR.libkactivities4?=	../../x11/libkactivities4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # LIBKACTIVITIES4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkactivities4
