# $NetBSD: buildlink3.mk,v 1.3 2021/09/29 09:55:43 schmonz Exp $

BUILDLINK_TREE+=	s6-dns

.if !defined(S6_DNS_BUILDLINK3_MK)
S6_DNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.s6-dns+=	s6-dns>=2.3.5.2
BUILDLINK_PKGSRCDIR.s6-dns?=	../../net/s6-dns
BUILDLINK_INCDIRS.s6-dns+=	include/s6-dns
BUILDLINK_LIBDIRS.s6-dns+=	lib/s6-dns
BUILDLINK_DEPMETHOD.s6-dns?=	build
.endif	# S6_DNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-s6-dns
