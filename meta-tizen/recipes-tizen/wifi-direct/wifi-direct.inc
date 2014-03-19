DESCRIPTION = "Network WiFi-Direct library in Tizen CAPI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-network-wifi-direct 
PROVIDES += "capi-network-wifi-direct"
RPROVIDES_capi-network-wifi-direct += "capi-network-wifi-direct"

#PROVIDES by capi-network-wifi-direct-devel 
PROVIDES += "capi-network-wifi-direct-devel"
RPROVIDES_capi-network-wifi-direct-devel += "capi-network-wifi-direct-devel"
RPROVIDES_capi-network-wifi-direct-devel += "capi-network-wifi-direct-dev"

RDEPENDS = ""
#RDEPENDS of capi-network-wifi-direct-devel (capi-network-${PN}-devel)
RDEPENDS_capi-network-${PN}-devel += "capi-base-common-dev"


DEPENDS = ""
#DEPENDS of capi-network-wifi-direct 
#DEPENDS of capi-network-wifi-direct-devel 
DEPENDS += "libwifi-direct"
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-wifi-direct.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . 
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
PACKAGES += "capi-network-wifi-direct"
PACKAGES += "capi-network-wifi-direct-devel"

capi-network-wifi-direct_files = ""
capi-network-wifi-direct_files += "capi-network-wifi-direct.manifest"

capi-network-wifi-direct-devel_files = ""
capi-network-wifi-direct-devel_files += "capi-network-wifi-direct.manifest"
capi-network-wifi-direct-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-network-wifi-direct-devel_files += "/usr/include/*/*.h"

FILES_${PN} = "${capi-network-wifi-direct_files}"
FILES_${PN}-devel = "${capi-network-wifi-direct-devel_files}"

PKG_capi-network-wifi-direct= "capi-network-wifi-direct"
PKG_capi-network-wifi-direct-devel= "capi-network-wifi-direct-devel"

require wifi-direct-extraconf.inc
