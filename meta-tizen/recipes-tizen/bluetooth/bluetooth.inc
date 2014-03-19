DESCRIPTION = "Network Bluetooth Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Connectivity/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-network-bluetooth-devel 
PROVIDES += "capi-network-bluetooth-devel"
RPROVIDES_capi-network-bluetooth-devel += "capi-network-bluetooth-devel"
RPROVIDES_capi-network-bluetooth-devel += "capi-network-bluetooth-dev"

#PROVIDES by capi-network-bluetooth 
PROVIDES += "capi-network-bluetooth"
RPROVIDES_capi-network-bluetooth += "capi-network-bluetooth"

RDEPENDS = ""
#RDEPENDS of capi-network-bluetooth-devel (capi-network-${PN}-devel)
RDEPENDS_capi-network-${PN}-devel += "capi-network-bluetooth"


DEPENDS = ""
#DEPENDS of capi-network-bluetooth 
DEPENDS += "pkgconfig(bluetooth-api)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(capi-base-common)"
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-bluetooth.manifest ${S}/packaging/capi-network-bluetooth-devel.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.39 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.39 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-network-bluetooth-devel"
PACKAGES += "capi-network-bluetooth"

capi-network-bluetooth-devel_files = ""
capi-network-bluetooth-devel_files += "capi-network-bluetooth-devel.manifest"
capi-network-bluetooth-devel_files += "/usr/include/network/bluetooth.h"
capi-network-bluetooth-devel_files += "/usr/lib/pkgconfig/capi-network-bluetooth.pc"
capi-network-bluetooth-devel_files += "/usr/lib/libcapi-network-bluetooth.so"

capi-network-bluetooth_files = ""
capi-network-bluetooth_files += "capi-network-bluetooth.manifest"
capi-network-bluetooth_files += "/usr/lib/libcapi-network-bluetooth.so.*"

FILES_${PN}-devel = "${capi-network-bluetooth-devel_files}"
FILES_${PN} = "${capi-network-bluetooth_files}"

PKG_capi-network-bluetooth-devel= "capi-network-bluetooth-devel"
PKG_capi-network-bluetooth= "capi-network-bluetooth"

require bluetooth-extraconf.inc
