DESCRIPTION = "A USB accessory library in TIZEN C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-usb-accessory-devel 
PROVIDES += "capi-system-usb-accessory-devel"
RPROVIDES_capi-system-usb-accessory-devel += "capi-system-usb-accessory-devel"
RPROVIDES_capi-system-usb-accessory-devel += "capi-system-usb-accessory-dev"

#PROVIDES by capi-system-usb-accessory 
PROVIDES += "capi-system-usb-accessory"
RPROVIDES_capi-system-usb-accessory += "capi-system-usb-accessory"

RDEPENDS = ""
#RDEPENDS of capi-system-usb-accessory-devel (capi-system-${PN}-devel)
RDEPENDS_capi-system-${PN}-devel += "capi-system-usb-accessory"


DEPENDS = ""
#DEPENDS of capi-system-usb-accessory 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cp ${S}/packaging/capi-system-usb-accessory.manifest .
 MAJORVER=`echo 0.0.9 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.0.9 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-system-usb-accessory-devel"
PACKAGES += "capi-system-usb-accessory"

capi-system-usb-accessory-devel_files = ""
capi-system-usb-accessory-devel_files += "capi-system-usb-accessory.manifest"
capi-system-usb-accessory-devel_files += "/usr/include/system/usb_accessory.h"
capi-system-usb-accessory-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-usb-accessory-devel_files += "/usr/lib/libcapi-system-usb-accessory.so"

capi-system-usb-accessory_files = ""
capi-system-usb-accessory_files += "capi-system-usb-accessory.manifest"
capi-system-usb-accessory_files += "capi-system-usb-accessory.manifest"
capi-system-usb-accessory_files += "/usr/lib/libcapi-system-usb-accessory.so.*"

FILES_${PN}-devel = "${capi-system-usb-accessory-devel_files}"
FILES_${PN} = "${capi-system-usb-accessory_files}"

PKG_capi-system-usb-accessory-devel= "capi-system-usb-accessory-devel"
PKG_capi-system-usb-accessory= "capi-system-usb-accessory"

require usb-accessory-extraconf.inc
