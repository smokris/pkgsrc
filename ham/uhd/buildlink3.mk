# $NetBSD: buildlink3.mk,v 1.5 2021/12/11 17:39:56 tnn Exp $

BUILDLINK_TREE+=	uhd

.if !defined(UHD_BUILDLINK3_MK)
UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhd+=	uhd>=2.22
BUILDLINK_ABI_DEPENDS.uhd?=	uhd>=4.1.0.4
BUILDLINK_PKGSRCDIR.uhd?=	../../ham/uhd

# gnuradio-uhd FindUHD.cmake uses this env var as a hint for finding uhd
CONFIGURE_ENV+=		UHD_DIR=${BUILDLINK_DIR}

.endif # UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhd
