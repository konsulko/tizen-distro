DESCRIPTION = "GStreamer Streaming-Media Framework Plug-Ins"
HOMEPAGE = "http://gstreamer.freedesktop.org/"
SECTION = "Multimedia/Audio"
LICENSE = "GPL-2.0+ and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gst-plugins-bad 
PROVIDES += "gst-plugins-bad"
RPROVIDES_gst-plugins-bad += "gst-plugins-bad"

#PROVIDES by libgsturidownloader 
PROVIDES += "libgsturidownloader"
RPROVIDES_libgsturidownloader += "libgsturidownloader"

#PROVIDES by libgstvdp 
PROVIDES += "libgstvdp"
RPROVIDES_libgstvdp += "libgstvdp"

#PROVIDES by libgstmpegts 
PROVIDES += "libgstmpegts"
RPROVIDES_libgstmpegts += "libgstmpegts"

#PROVIDES by libgstbasecamerabinsrc 
PROVIDES += "libgstbasecamerabinsrc"
RPROVIDES_libgstbasecamerabinsrc += "libgstbasecamerabinsrc"

#PROVIDES by libgstphotography 
PROVIDES += "libgstphotography"
RPROVIDES_libgstphotography += "libgstphotography"

#PROVIDES by libgstinsertbin 
PROVIDES += "libgstinsertbin"
RPROVIDES_libgstinsertbin += "libgstinsertbin"

#PROVIDES by libgstcodecparsers 
PROVIDES += "libgstcodecparsers"
RPROVIDES_libgstcodecparsers += "libgstcodecparsers"

#PROVIDES by gst-plugins-bad-locale  
PROVIDES += "gst-plugins-bad-locale "
RPROVIDES_gst-plugins-bad-locale  += "gst-plugins-bad-locale "
# the PROVIDES rules is ignore "gst-plugins-bad-lang-all = 1.2.0"
PROVIDES += "gst-plugins-bad-lang-all"
RPROVIDES_gst-plugins-bad-locale  += "gst-plugins-bad-lang-all"

#PROVIDES by libgstegl 
PROVIDES += "libgstegl"
RPROVIDES_libgstegl += "libgstegl"

#PROVIDES by gst-plugins-bad-devel 
PROVIDES += "gst-plugins-bad-devel"
RPROVIDES_gst-plugins-bad-devel += "gst-plugins-bad-devel"
RPROVIDES_gst-plugins-bad-devel += "gst-plugins-bad-dev"

RDEPENDS = ""
#RDEPENDS of gst-plugins-bad (${PN})
RDEPENDS_${PN} += "gstreamer"
RDEPENDS_${PN} += "glib2-tools"

#RDEPENDS of gst-plugins-bad-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "gst-plugins-bad"

#RDEPENDS of gst-plugins-bad-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libgstphotography"
RDEPENDS_${PN}-devel += "libgstmpegts"
RDEPENDS_${PN}-devel += "libgstinsertbin"
RDEPENDS_${PN}-devel += "libgsturidownloader"
RDEPENDS_${PN}-devel += "gstreamer-dev"
RDEPENDS_${PN}-devel += "libgstbasecamerabinsrc"
RDEPENDS_${PN}-devel += "libgstcodecparsers"
RDEPENDS_${PN}-devel += "libgstegl"


DEPENDS = ""
#DEPENDS of gst-plugins-bad 
DEPENDS += "glib"
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "xsltproc"
inherit pythonnative
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(libcrypto)"
DEPENDS += "pkgconfig(orc-0.4)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(sndfile)"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "gstreamer-devel"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "SDL"
DEPENDS += "gst-plugins-base-devel"
DEPENDS += "autoconf-native"
DEPENDS += "pkgconfig(wayland-client)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gst-plugins-bad-1.2.0
 #extracte source 100 
 pushd ${S}
 unp ${S}/packaging/common.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -T -D -a 100
 cp ${S}/packaging/gst-plugins-bad.manifest .
 
 
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
 
 export V=1
 NOCONFIGURE=1 ./autogen.sh
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info\
     --disable-static\
     --disable-examples\
     --enable-experimental\
     --disable-gtk-doc 
 oe_runmake -j16 V=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gst-plugins-bad-1.0
 mv gst-plugins-bad-1.0.lang gst-plugins-bad.lang
 
 
 
}

PACKAGES = ""
PACKAGES += "gst-plugins-bad"
PACKAGES += "libgstphotography"
PACKAGES += "libgstmpegts"
PACKAGES += "libgstinsertbin"
PACKAGES += "libgsturidownloader"
PACKAGES += "libgstbasecamerabinsrc"
PACKAGES += "gst-plugins-bad-locale"
PACKAGES += "libgstcodecparsers"
PACKAGES += "libgstegl"
PACKAGES += "gst-plugins-bad-devel"

gst-plugins-bad_files = ""
gst-plugins-bad_files += "gst-plugins-bad.manifest"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstadpcmdec.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstadpcmenc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstasfmux.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstaudiovisualizers.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstautoconvert.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstbayer.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstcamerabin2.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstcoloreffects.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstcurl.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdataurisrc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdebugutilsbad.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdvb.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdvbsuboverlay.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstfestival.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstgaudieffects.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstgdp.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstgeometrictransform.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstid3tag.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstinter.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstinterlace.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstjpegformat.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstliveadder.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmpegpsdemux.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmpegtsdemux.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmpegtsmux.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstpcapparse.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstpnm.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstrawparse.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstremovesilence.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstsdpelem.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstsegmentclip.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstshm.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstsmooth.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstspeed.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstvideoparsersbad.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgsty4mdec.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdvdspu.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstfieldanalysis.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstfrei0r.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstsiren.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstsubenc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmpegpsmux.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstdecklink.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgsteglglessink.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstaccurip.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstaiff.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstaudiofxbad.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstfbdevsink.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstfreeverb.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstivtc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmfc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmidi.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstmxf.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstrfbsrc.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstvideofiltersbad.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstyadif.so"
gst-plugins-bad_files += "/usr/lib/gstreamer-1.0/libgstwaylandsink.so"

libgstphotography_files = ""
libgstphotography_files += "gst-plugins-bad.manifest"
libgstphotography_files += "/usr/lib/libgstphotography-1.0.so.0*"

libgstmpegts_files = ""
libgstmpegts_files += "gst-plugins-bad.manifest"
libgstmpegts_files += "/usr/lib/libgstmpegts-1.0.so.0*"

libgstinsertbin_files = ""
libgstinsertbin_files += "gst-plugins-bad.manifest"
libgstinsertbin_files += "/usr/lib/libgstinsertbin-1.0.so.0*"

libgsturidownloader_files = ""
libgsturidownloader_files += "gst-plugins-bad.manifest"
libgsturidownloader_files += "/usr/lib/libgsturidownloader-1.0.so.0*"

libgstbasecamerabinsrc_files = ""
libgstbasecamerabinsrc_files += "gst-plugins-bad.manifest"
libgstbasecamerabinsrc_files += "/usr/lib/libgstbasecamerabinsrc-1.0.so.0*"

gst-plugins-bad-locale_files = ""

libgstcodecparsers_files = ""
libgstcodecparsers_files += "gst-plugins-bad.manifest"
libgstcodecparsers_files += "/usr/lib/libgstcodecparsers-1.0.so.0*"

libgstegl_files = ""
libgstegl_files += "gst-plugins-bad.manifest"
libgstegl_files += "/usr/lib/libgstegl-1.0.so.0*"

gst-plugins-bad-devel_files = ""
gst-plugins-bad-devel_files += "gst-plugins-bad.manifest"
gst-plugins-bad-devel_files += "/usr/include/gstreamer-1.0"
gst-plugins-bad-devel_files += "/usr/lib/*.so"
gst-plugins-bad-devel_files += "/usr/lib/pkgconfig/gstreamer-codecparsers-1.0.pc"
gst-plugins-bad-devel_files += "/usr/lib/pkgconfig/gstreamer-plugins-bad-1.0.pc"
gst-plugins-bad-devel_files += "/usr/lib/pkgconfig/gstreamer-egl-1.0.pc"
gst-plugins-bad-devel_files += "/usr/lib/pkgconfig/gstreamer-insertbin-1.0.pc"

FILES_${PN} = "${gst-plugins-bad_files}"
FILES_libgstphotography = "${libgstphotography_files}"
FILES_libgstmpegts = "${libgstmpegts_files}"
FILES_libgstinsertbin = "${libgstinsertbin_files}"
FILES_libgsturidownloader = "${libgsturidownloader_files}"
FILES_libgstbasecamerabinsrc = "${libgstbasecamerabinsrc_files}"
FILES_${PN}-locale = "${gst-plugins-bad-locale_files}"
FILES_libgstcodecparsers = "${libgstcodecparsers_files}"
FILES_libgstegl = "${libgstegl_files}"
FILES_${PN}-devel = "${gst-plugins-bad-devel_files}"

PKG_gst-plugins-bad= "gst-plugins-bad"
PKG_libgstphotography= "libgstphotography"
PKG_libgstmpegts= "libgstmpegts"
PKG_libgstinsertbin= "libgstinsertbin"
PKG_libgsturidownloader= "libgsturidownloader"
PKG_libgstbasecamerabinsrc= "libgstbasecamerabinsrc"
PKG_gst-plugins-bad-locale= "gst-plugins-bad-locale"
PKG_libgstcodecparsers= "libgstcodecparsers"
PKG_libgstegl= "libgstegl"
PKG_gst-plugins-bad-devel= "gst-plugins-bad-devel"

require gst-plugins-bad-extraconf.inc
