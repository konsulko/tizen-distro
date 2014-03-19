DESCRIPTION = "VA-API based plugins for GStreamer and helper libraries"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Multimedia Framework"
LICENSE = "LGPL-2.1+ and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gstreamer-vaapi 
PROVIDES += "gstreamer-vaapi"
RPROVIDES_gstreamer-vaapi += "gstreamer-vaapi"

#PROVIDES by gstreamer-vaapi-devel 
PROVIDES += "gstreamer-vaapi-devel"
RPROVIDES_gstreamer-vaapi-devel += "gstreamer-vaapi-devel"
RPROVIDES_gstreamer-vaapi-devel += "gstreamer-vaapi-dev"

RDEPENDS = ""
#RDEPENDS of gstreamer-vaapi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gstreamer-vaapi"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of gstreamer-vaapi 
DEPENDS += "git"
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "which"
DEPENDS += "pkgconfig(libva)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 #extracte source 2001 
 pushd ${S}
 unp ${S}/packaging/codecparsers.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -T -D -a 2001
 #extracte source 2002 
 pushd ${S}
 unp ${S}/packaging/videoutils.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -T -D -a 2002
 
 
 
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
 
 cp ${S}/packaging/gstreamer-vaapi.manifest .
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info --enable-encoders --with-gstreamer-api=1.2
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
PACKAGES += "gstreamer-vaapi"
PACKAGES += "gstreamer-vaapi-devel"

gstreamer-vaapi_files = ""
gstreamer-vaapi_files += "gstreamer-vaapi.manifest"
gstreamer-vaapi_files += "/usr/lib/*.so.*"
gstreamer-vaapi_files += "/usr/lib/gstreamer-1.0/*.so"

gstreamer-vaapi-devel_files = ""
gstreamer-vaapi-devel_files += "gstreamer-vaapi.manifest"
gstreamer-vaapi-devel_files += "/usr/include/gstreamer-1.2/gst/vaapi"
gstreamer-vaapi-devel_files += "/usr/include/gstreamer-1.2/gst/vaapi/*.h"
gstreamer-vaapi-devel_files += "/usr/lib/*.so"
gstreamer-vaapi-devel_files += "/usr/lib/pkgconfig/gstreamer-vaapi*.pc"

FILES_${PN} = "${gstreamer-vaapi_files}"
FILES_${PN}-devel = "${gstreamer-vaapi-devel_files}"

PKG_gstreamer-vaapi= "gstreamer-vaapi"
PKG_gstreamer-vaapi-devel= "gstreamer-vaapi-devel"

require gstreamer-vaapi-extraconf.inc
