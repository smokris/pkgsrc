# $NetBSD: Makefile,v 1.18 2021/10/09 15:35:08 nia Exp $

PKGNAME=	${DISTNAME:S/ffmpeg/ffplay4/}
PKGREVISION=	3
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ffmpeg.org/
COMMENT=	Simple SDL frontend for FFmpeg

DISTINFO_FILE=		${.CURDIR}/../ffmpeg4/distinfo

USE_LANGUAGES=	c99

CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-ffprobe
CONFIGURE_ARGS+=	--disable-encoders
CONFIGURE_ARGS+=	--disable-decoders
CONFIGURE_ARGS+=	--disable-hwaccels
CONFIGURE_ARGS+=	--disable-muxers
CONFIGURE_ARGS+=	--disable-demuxers
CONFIGURE_ARGS+=	--disable-parsers
CONFIGURE_ARGS+=	--disable-bsfs
CONFIGURE_ARGS+=	--disable-protocols
CONFIGURE_ARGS+=	--disable-devices
CONFIGURE_ARGS+=	--disable-filters
CONFIGURE_ARGS+=	--disable-htmlpages
CONFIGURE_ARGS+=	--disable-podpages
CONFIGURE_ARGS+=	--disable-txtpages
CONFIGURE_ARGS+=	--enable-ffplay
CONFIGURE_ARGS+=	--enable-dct
CONFIGURE_ARGS+=	--enable-mdct
CONFIGURE_ARGS+=	--enable-rdft

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ffplay4 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ffplay4.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/ffmpeg4/Makefile.common"
