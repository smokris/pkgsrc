# $NetBSD: buildlink3.mk,v 1.19 2021/12/08 16:03:03 adam Exp $

BUILDLINK_TREE+=	vte3

.if !defined(VTE3_BUILDLINK3_MK)
VTE3_BUILDLINK3_MK:=

# for c++17
GCC_REQD+=		7

BUILDLINK_API_DEPENDS.vte3+=	vte3>=0.52.2
BUILDLINK_ABI_DEPENDS.vte3+=	vte3>=0.60.3nb12
BUILDLINK_PKGSRCDIR.vte3?=	../../x11/vte3

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # VTE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte3
