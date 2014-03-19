DESCRIPTION = "GStreamer plugins from the "ugly" set"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Audio"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gst-plugins-ugly 
PROVIDES += "gst-plugins-ugly"
RPROVIDES_gst-plugins-ugly += "gst-plugins-ugly"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of gst-plugins-ugly 
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(opencore-amrwb)"
DEPENDS += "which"
DEPENDS += "pkgconfig(opencore-amrnb)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 #extracte source 100 
 pushd ${S}
 unp ${S}/packaging/common.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -T -D -a 100
 cp ${S}/packaging/gst-plugins-ugly.manifest .
 
 
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
         --infodir=/usr/share/info \
  --disable-static\
  --disable-nls\
  --with-html-dir=/tmp/dump\
  --disable-examples\
  --disable-dvdlpcmdec\
  --disable-dvdsub\
  --disable-iec958\
  --disable-mpegstream\
  --disable-synaesthesia\
  --disable-a52dec\
  --disable-cdio\
  --disable-dvdread\
  --disable-dvdnav\
  --disable-mad\
  --disable-mpeg2dec\
  --disable-sidplay\
  --disable-twolame\
  --disable-x264
 
 make -j16
 
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "gst-plugins-ugly"

gst-plugins-ugly_files = ""
gst-plugins-ugly_files += "gst-plugins-ugly.manifest"
gst-plugins-ugly_files += "/usr/lib/gstreamer-1.0/libgstasf.so"
gst-plugins-ugly_files += "/usr/lib/gstreamer-1.0/libgstxingmux.so"
gst-plugins-ugly_files += "/usr/lib/gstreamer-1.0/libgstamrnb.so"
gst-plugins-ugly_files += "/usr/lib/gstreamer-1.0/libgstamrwbdec.so"
gst-plugins-ugly_files += "/usr/lib/gstreamer-1.0/libgstrmdemux.so"

FILES_${PN} = "${gst-plugins-ugly_files}"

PKG_gst-plugins-ugly= "gst-plugins-ugly"

require gst-plugins-ugly-extraconf.inc
