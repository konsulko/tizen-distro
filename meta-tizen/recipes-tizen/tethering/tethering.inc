DESCRIPTION = "Tethering Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Connectivity/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-network-tethering-devel 
PROVIDES += "capi-network-tethering-devel"
RPROVIDES_capi-network-tethering-devel += "capi-network-tethering-devel"
RPROVIDES_capi-network-tethering-devel += "capi-network-tethering-dev"

#PROVIDES by capi-network-tethering 
PROVIDES += "capi-network-tethering"
RPROVIDES_capi-network-tethering += "capi-network-tethering"

RDEPENDS = ""
#RDEPENDS of capi-network-tethering-devel (capi-network-${PN}-devel)
RDEPENDS_capi-network-${PN}-devel += "capi-network-tethering"


DEPENDS = ""
#DEPENDS of capi-network-tethering 
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-tethering.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DARCH=i586
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
PACKAGES += "capi-network-tethering-devel"
PACKAGES += "capi-network-tethering"

capi-network-tethering-devel_files = ""
capi-network-tethering-devel_files += "capi-network-tethering.manifest"
capi-network-tethering-devel_files += "/usr/include/network/*.h"
capi-network-tethering-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-network-tethering-devel_files += "/usr/lib/*.so"

capi-network-tethering_files = ""
capi-network-tethering_files += "capi-network-tethering.manifest"
capi-network-tethering_files += "/usr/lib/*.so.*"
capi-network-tethering_files += "/etc/config/connectivity/sysinfo-tethering.xml"

FILES_${PN}-devel = "${capi-network-tethering-devel_files}"
FILES_${PN} = "${capi-network-tethering_files}"

PKG_capi-network-tethering-devel= "capi-network-tethering-devel"
PKG_capi-network-tethering= "capi-network-tethering"

require tethering-extraconf.inc
