DESCRIPTION = "Network Serial Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-network-serial-devel 
PROVIDES += "capi-network-serial-devel"
RPROVIDES_capi-network-serial-devel += "capi-network-serial-devel"
RPROVIDES_capi-network-serial-devel += "capi-network-serial-dev"

#PROVIDES by capi-network-serial 
PROVIDES += "capi-network-serial"
RPROVIDES_capi-network-serial += "capi-network-serial"

RDEPENDS = ""
#RDEPENDS of capi-network-serial-devel (capi-network-${PN}-devel)
RDEPENDS_capi-network-${PN}-devel += "capi-network-serial"


DEPENDS = ""
#DEPENDS of capi-network-serial 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "dbus-glib"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-serial.manifest .
 
 
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
 
 MAJORVER=`echo 0.0.7 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.0.7 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-network-serial-devel"
PACKAGES += "capi-network-serial"

capi-network-serial-devel_files = ""
capi-network-serial-devel_files += "capi-network-serial.manifest"
capi-network-serial-devel_files += "/usr/include/network/serial.h"
capi-network-serial-devel_files += "/usr/lib/pkgconfig/capi-network-serial.pc"
capi-network-serial-devel_files += "/usr/lib/libcapi-network-serial.so"

capi-network-serial_files = ""
capi-network-serial_files += "capi-network-serial.manifest"
capi-network-serial_files += "/usr/lib/libcapi-network-serial.so.*"

FILES_${PN}-devel = "${capi-network-serial-devel_files}"
FILES_${PN} = "${capi-network-serial_files}"

PKG_capi-network-serial-devel= "capi-network-serial-devel"
PKG_capi-network-serial= "capi-network-serial"

require serial-extraconf.inc
