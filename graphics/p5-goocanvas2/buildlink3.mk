# $NetBSD: buildlink3.mk,v 1.2 2021/12/08 16:02:13 adam Exp $

BUILDLINK_TREE+=	p5-goocanvas2

.if !defined(P5_GOOCANVAS2_BUILDLINK3_MK)
P5_GOOCANVAS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-goocanvas2+=	p5-goocanvas2>=0.06
BUILDLINK_ABI_DEPENDS.p5-goocanvas2?=	p5-goocanvas2>=0.06
BUILDLINK_PKGSRCDIR.p5-goocanvas2?=	../../graphics/p5-goocanvas2

.include "../../graphics/goocanvas2/buildlink3.mk"
.endif	# P5_GOOCANVAS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-goocanvas2
