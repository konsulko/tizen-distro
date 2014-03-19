DESCRIPTION = "Wifi Direct Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Wireless"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libwifi-direct 
PROVIDES += "libwifi-direct"
RPROVIDES_libwifi-direct += "libwifi-direct"

#PROVIDES by libwifi-direct-devel 
PROVIDES += "libwifi-direct-devel"
RPROVIDES_libwifi-direct-devel += "libwifi-direct-devel"
RPROVIDES_libwifi-direct-devel += "libwifi-direct-dev"

RDEPENDS = ""
#RDEPENDS of libwifi-direct-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libwifi-direct"


DEPENDS = ""
#DEPENDS of libwifi-direct 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libwifi-direct.manifest .
 
 export ARCH=i586
 
 
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
 
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/LICENSE.APLv2 ${D}/usr/share/license/libwifi-direct
 
 
 
}

PACKAGES = ""
PACKAGES += "libwifi-direct"
PACKAGES += "libwifi-direct-devel"

libwifi-direct_files = ""
libwifi-direct_files += "libwifi-direct.manifest"
libwifi-direct_files += "/usr/lib/libwifi-direct.so"
libwifi-direct_files += "/usr/lib/libwifi-direct.so.0"
libwifi-direct_files += "/usr/lib/libwifi-direct.so.0.0"
libwifi-direct_files += "/usr/share/license/libwifi-direct"

libwifi-direct-devel_files = ""
libwifi-direct-devel_files += "libwifi-direct.manifest"
libwifi-direct-devel_files += "/usr/lib/pkgconfig/wifi-direct.pc"
libwifi-direct-devel_files += "/usr/include/wifi-direct/wifi-direct.h"
libwifi-direct-devel_files += "/usr/include/wifi-direct/wifi-direct-internal.h"

FILES_${PN} = "${libwifi-direct_files}"
FILES_${PN}-devel = "${libwifi-direct-devel_files}"

PKG_libwifi-direct= "libwifi-direct"
PKG_libwifi-direct-devel= "libwifi-direct-devel"

require libwifi-direct-extraconf.inc
