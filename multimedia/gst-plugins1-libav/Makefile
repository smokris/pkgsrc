# $NetBSD: Makefile,v 1.55 2021/10/09 15:35:08 nia Exp $

DISTNAME=	gst-libav-1.16.2
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-system-libav
PKGSRC_MAKE_ENV+=	PERL=${PERL5:Q}

CHECK_PORTABILITY_SKIP=	gst-libs/ext/libav/configure

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.16.2
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
