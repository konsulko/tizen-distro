DESCRIPTION = "A Radio library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-radio 
PROVIDES += "capi-media-radio"
RPROVIDES_capi-media-radio += "capi-media-radio"

#PROVIDES by capi-media-radio-devel 
PROVIDES += "capi-media-radio-devel"
RPROVIDES_capi-media-radio-devel += "capi-media-radio-devel"
RPROVIDES_capi-media-radio-devel += "capi-media-radio-dev"

RDEPENDS = ""
#RDEPENDS of capi-media-radio-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-radio"


DEPENDS = ""
#DEPENDS of capi-media-radio 
DEPENDS += "cmake"
DEPENDS += "dlog"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libmm-radio"
DEPENDS += "common"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-radio.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .  -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-media-radio"
PACKAGES += "capi-media-radio-devel"

capi-media-radio_files = ""
capi-media-radio_files += "capi-media-radio.manifest"
capi-media-radio_files += "/usr/lib/libcapi-media-radio.so.*"

capi-media-radio-devel_files = ""
capi-media-radio-devel_files += "capi-media-radio.manifest"
capi-media-radio-devel_files += "/usr/include/media/radio.h"
capi-media-radio-devel_files += "/usr/lib/pkgconfig/capi-media-radio.pc"
capi-media-radio-devel_files += "/usr/lib/libcapi-media-radio.so"

FILES_${PN} = "${capi-media-radio_files}"
FILES_${PN}-devel = "${capi-media-radio-devel_files}"

PKG_capi-media-radio= "capi-media-radio"
PKG_capi-media-radio-devel= "capi-media-radio-devel"

require radio-extraconf.inc
