# $NetBSD: buildlink3.mk,v 1.17 2021/09/29 19:00:15 adam Exp $

BUILDLINK_TREE+=	source-highlight

.if !defined(SOURCE_HIGHLIGHT_BUILDLINK3_MK)
SOURCE_HIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.source-highlight+=	source-highlight>=3.1.7nb2
BUILDLINK_ABI_DEPENDS.source-highlight?=	source-highlight>=3.1.9nb3
BUILDLINK_PKGSRCDIR.source-highlight?=		../../textproc/source-highlight

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# SOURCE_HIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-source-highlight
