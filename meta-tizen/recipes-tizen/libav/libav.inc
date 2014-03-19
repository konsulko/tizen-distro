DESCRIPTION = "AV codec lib"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libavutil 
PROVIDES += "libavutil"
RPROVIDES_libavutil += "libavutil"

#PROVIDES by libavfilter-devel 
PROVIDES += "libavfilter-devel"
RPROVIDES_libavfilter-devel += "libavfilter-devel"
RPROVIDES_libavfilter-devel += "libavfilter-dev"

#PROVIDES by libavformat 
PROVIDES += "libavformat"
RPROVIDES_libavformat += "libavformat"

#PROVIDES by libavtools 
PROVIDES += "libavtools"
RPROVIDES_libavtools += "libavtools"

#PROVIDES by libavcodec 
PROVIDES += "libavcodec"
RPROVIDES_libavcodec += "libavcodec"

#PROVIDES by libavfilter 
PROVIDES += "libavfilter"
RPROVIDES_libavfilter += "libavfilter"

#PROVIDES by libswscale-devel 
PROVIDES += "libswscale-devel"
RPROVIDES_libswscale-devel += "libswscale-devel"
RPROVIDES_libswscale-devel += "libswscale-dev"

#PROVIDES by libavcodec-devel 
PROVIDES += "libavcodec-devel"
RPROVIDES_libavcodec-devel += "libavcodec-devel"
RPROVIDES_libavcodec-devel += "libavcodec-dev"

#PROVIDES by libavutil-devel 
PROVIDES += "libavutil-devel"
RPROVIDES_libavutil-devel += "libavutil-devel"
RPROVIDES_libavutil-devel += "libavutil-dev"

#PROVIDES by libswscale 
PROVIDES += "libswscale"
RPROVIDES_libswscale += "libswscale"

#PROVIDES by libav 
PROVIDES += "libav"
RPROVIDES_libav += "libav"

#PROVIDES by libavformat-devel 
PROVIDES += "libavformat-devel"
RPROVIDES_libavformat-devel += "libavformat-devel"
RPROVIDES_libavformat-devel += "libavformat-dev"

RDEPENDS = ""
#RDEPENDS of libavfilter-devel (${PN}filter-devel)
RDEPENDS_${PN}filter-devel += "libavfilter"

#RDEPENDS of libswscale-devel (libswscale-devel)
RDEPENDS_libswscale-devel += "libswscale"

#RDEPENDS of libavcodec-devel (${PN}codec-devel)
RDEPENDS_${PN}codec-devel += "libavcodec"

#RDEPENDS of libavutil-devel (${PN}util-devel)
RDEPENDS_${PN}util-devel += "libavutil"

#RDEPENDS of libavformat-devel (${PN}format-devel)
RDEPENDS_${PN}format-devel += "libavformat"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 export CONFIGURE_OPTIONS="--enable-shared    --disable-static   \
 --disable-version3  --disable-devices   --disable-nonfree --disable-gpl --disable-doc \
 --disable-zlib    --disable-network \
 --disable-avdevice \
 --disable-bsfs      --disable-filters \
 --enable-filter=buffer  --enable-filter=buffersink      --enable-filter=crop \
 --enable-filter=hflip   --enable-filter=lut     --enable-filter=lutyuv \
 --enable-filter=lutrgb  --enable-filter=overlay --enable-filter=scale \
 --enable-filter=transpose       --enable-filter=unsharp --enable-filter=vflip \
 --disable-protocols \
 --disable-avresample \
 --enable-protocol=file \
 --disable-encoders \
 --disable-muxers \
 --disable-parsers \
 --enable-parser=aac     --enable-parser=h264            --enable-parser=mpegaudio \
 --enable-parser=h263    --enable-parser=mpeg4video      --enable-parser=mpegvideo \
 --disable-demuxers \
 --enable-demuxer=aac    --enable-demuxer=h264   --enable-demuxer=mpegts \
 --enable-demuxer=amr    --enable-demuxer=m4v    --enable-demuxer=mpegtsraw \
 --enable-demuxer=asf    --enable-demuxer=mmf    --enable-demuxer=mpegvideo \
 --enable-demuxer=avi    --enable-demuxer=mov    --enable-demuxer=ogg \
 --enable-demuxer=flac   --enable-demuxer=mp3    --enable-demuxer=wav \
 --enable-demuxer=h263   --enable-demuxer=mpegps --enable-demuxer=matroska \
 --enable-demuxer=dv	--enable-demuxer=flv \
 --disable-decoders \
 --enable-decoder=alac   --enable-decoder=h264           --enable-decoder=wmv1 \
 --enable-decoder=flac   --enable-decoder=mpeg4          --enable-decoder=wmv2 \
 --enable-decoder=h263   --enable-decoder=mpegvideo      --enable-decoder=wmv3 \
 --enable-decoder=vc1	--enable-decoder=flv \
 --enable-decoder=h263i  --enable-decoder=theora  \
 --enable-decoder=pcm_alaw  --enable-decoder=pcm_mulaw  \
 --enable-encoder=h263   --enable-encoder=h263p  --enable-encoder=mpeg4   \
 --enable-decoder=bmp  --enable-encoder=bmp       \
 --enable-decoder=tiff \
 --enable-decoder=mp3  --enable-decoder=amrnb    \
 --enable-encoder=aac  --enable-decoder=aac      \
 --enable-swscale        --disable-yasm	 \
 --enable-fft    --enable-rdft   --enable-mdct   --enable-neon \
 "
 
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fPIC -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" "; export CFLAGS
 
 ./configure --prefix=/usr --shlibdir=/usr/lib --libdir=/usr/lib  $CONFIGURE_OPTIONS
 
 
}

do_configure() {
}

do_compile() {
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}//usr/share/license
 cp -rf ${WORKDIR}/libav-9.8/COPYING.LGPLv2.1 ${D}//usr/share/license/libavcodec
 cp -rf ${WORKDIR}/libav-9.8/COPYING.LGPLv2.1 ${D}//usr/share/license/libavformat
 cp -rf ${WORKDIR}/libav-9.8/COPYING.LGPLv2.1 ${D}//usr/share/license/libavutil
 cp -rf ${WORKDIR}/libav-9.8/COPYING.LGPLv2.1 ${D}//usr/share/license/libavfilter
 cp -rf ${WORKDIR}/libav-9.8/COPYING.LGPLv2.1 ${D}//usr/share/license/libswscale
 
 
 
}

PACKAGES = ""
PACKAGES += "libavutil"
PACKAGES += "libavfilter-devel"
PACKAGES += "libavformat"
PACKAGES += "libavtools"
PACKAGES += "libavcodec"
PACKAGES += "libavfilter"
PACKAGES += "libswscale-devel"
PACKAGES += "libavcodec-devel"
PACKAGES += "libavutil-devel"
PACKAGES += "libswscale"
PACKAGES += "libavformat-devel"

libavutil_files = ""
libavutil_files += "/usr/lib/libavutil.so.*"
libavutil_files += "/usr/share/license/libavutil"

libavfilter-devel_files = ""
libavfilter-devel_files += "/usr/include/libavfilter/*"
libavfilter-devel_files += "/usr/lib/libavfilter.so"
libavfilter-devel_files += "/usr/lib/pkgconfig/libavfilter.pc"

libavformat_files = ""
libavformat_files += "/usr/lib/libavformat.so.*"
libavformat_files += "/usr/share/license/libavformat"

libavtools_files = ""
libavtools_files += "/usr/bin/av*"
libavtools_files += "/usr/share/avconv/*.avpreset"

libavcodec_files = ""
libavcodec_files += "/usr/lib/libavcodec.so.*"
libavcodec_files += "/usr/share/license/libavcodec"

libavfilter_files = ""
libavfilter_files += "/usr/lib/libavfilter.so.*"
libavfilter_files += "/usr/share/license/libavfilter"

libswscale-devel_files = ""
libswscale-devel_files += "/usr/include/libswscale/*"
libswscale-devel_files += "/usr/lib/libswscale.so"
libswscale-devel_files += "/usr/lib/pkgconfig/libswscale.pc"

libavcodec-devel_files = ""
libavcodec-devel_files += "/usr/include/libavcodec/*"
libavcodec-devel_files += "/usr/lib/libavcodec.so"
libavcodec-devel_files += "/usr/lib/pkgconfig/libavcodec.pc"

libavutil-devel_files = ""
libavutil-devel_files += "/usr/include/libavutil/*"
libavutil-devel_files += "/usr/lib/libavutil.so"
libavutil-devel_files += "/usr/lib/pkgconfig/libavutil.pc"

libswscale_files = ""
libswscale_files += "/usr/lib/libswscale.so.*"
libswscale_files += "/usr/share/license/libswscale"

libavformat-devel_files = ""
libavformat-devel_files += "/usr/include/libavformat/*"
libavformat-devel_files += "/usr/lib/libavformat.so"
libavformat-devel_files += "/usr/lib/pkgconfig/libavformat.pc"

FILES_${PN}util = "${libavutil_files}"
FILES_${PN}filter-devel = "${libavfilter-devel_files}"
FILES_${PN}format = "${libavformat_files}"
FILES_${PN}tools = "${libavtools_files}"
FILES_${PN}codec = "${libavcodec_files}"
FILES_${PN}filter = "${libavfilter_files}"
FILES_libswscale-devel = "${libswscale-devel_files}"
FILES_${PN}codec-devel = "${libavcodec-devel_files}"
FILES_${PN}util-devel = "${libavutil-devel_files}"
FILES_libswscale = "${libswscale_files}"
FILES_${PN}format-devel = "${libavformat-devel_files}"

PKG_libavutil= "libavutil"
PKG_libavfilter-devel= "libavfilter-devel"
PKG_libavformat= "libavformat"
PKG_libavtools= "libavtools"
PKG_libavcodec= "libavcodec"
PKG_libavfilter= "libavfilter"
PKG_libswscale-devel= "libswscale-devel"
PKG_libavcodec-devel= "libavcodec-devel"
PKG_libavutil-devel= "libavutil-devel"
PKG_libswscale= "libswscale"
PKG_libavformat-devel= "libavformat-devel"

require libav-extraconf.inc
