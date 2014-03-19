DESCRIPTION = "Network Wi-Fi library in TIZEN C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Network"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-network-wifi-devel 
PROVIDES += "capi-network-wifi-devel"
RPROVIDES_capi-network-wifi-devel += "capi-network-wifi-devel"
RPROVIDES_capi-network-wifi-devel += "capi-network-wifi-dev"

#PROVIDES by capi-network-wifi 
PROVIDES += "capi-network-wifi"
RPROVIDES_capi-network-wifi += "capi-network-wifi"

RDEPENDS = ""
#RDEPENDS of capi-network-wifi-devel (capi-network-${PN}-devel)
RDEPENDS_capi-network-${PN}-devel += "capi-network-wifi"


DEPENDS = ""
#DEPENDS of capi-network-wifi 
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libnet-client"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-wifi.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.2_18 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.2_18 -DMAJORVER=${MAJORVER}
 
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
 
 #License
 mkdir -p ${D}/usr/share/license
 cp LICENSE.APLv2 ${D}/usr/share/license/capi-network-wifi
 
 
}

PACKAGES = ""
PACKAGES += "capi-network-wifi-devel"
PACKAGES += "capi-network-wifi"

capi-network-wifi-devel_files = ""
capi-network-wifi-devel_files += "capi-network-wifi.manifest"
capi-network-wifi-devel_files += "/usr/include/network/*.h"
capi-network-wifi-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-network-wifi-devel_files += "/usr/lib/libcapi-network-wifi.so"

capi-network-wifi_files = ""
capi-network-wifi_files += "capi-network-wifi.manifest"
capi-network-wifi_files += "/usr/share/license/capi-network-wifi"

FILES_${PN}-devel = "${capi-network-wifi-devel_files}"
FILES_${PN} = "${capi-network-wifi_files}"

PKG_capi-network-wifi-devel= "capi-network-wifi-devel"
PKG_capi-network-wifi= "capi-network-wifi"

require wifi-extraconf.inc
