DESCRIPTION = "Haptic library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libhaptic 
PROVIDES += "libhaptic"
RPROVIDES_libhaptic += "libhaptic"

#PROVIDES by libhaptic-devel 
PROVIDES += "libhaptic-devel"
RPROVIDES_libhaptic-devel += "libhaptic-devel"
RPROVIDES_libhaptic-devel += "libhaptic-dev"

#PROVIDES by libhaptic-plugin-devel 
PROVIDES += "libhaptic-plugin-devel"
RPROVIDES_libhaptic-plugin-devel += "libhaptic-plugin-devel"
RPROVIDES_libhaptic-plugin-devel += "libhaptic-plugin-dev"

RDEPENDS = ""
#RDEPENDS of libhaptic-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libhaptic"


DEPENDS = ""
#DEPENDS of libhaptic 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"
DEPENDS += "common"

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
 
 cp ${S}/packaging/libhaptic.manifest .
 
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
 
 mkdir -p ${D}/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "libhaptic"
PACKAGES += "libhaptic-devel"
PACKAGES += "libhaptic-plugin-devel"

libhaptic_files = ""
libhaptic_files += "libhaptic.manifest"
libhaptic_files += "/usr/lib/libhaptic.so.*"
libhaptic_files += "/usr/share/license/haptic"

libhaptic-devel_files = ""
libhaptic-devel_files += "libhaptic.manifest"
libhaptic-devel_files += "/usr/include/haptic/haptic.h"
libhaptic-devel_files += "/usr/include/haptic/SLP_HAPTIC_PG.h"
libhaptic-devel_files += "/usr/lib/libhaptic.so"
libhaptic-devel_files += "/usr/lib/pkgconfig/haptic.pc"

libhaptic-plugin-devel_files = ""
libhaptic-plugin-devel_files += "libhaptic.manifest"
libhaptic-plugin-devel_files += "/usr/include/haptic/haptic_module.h"
libhaptic-plugin-devel_files += "/usr/include/haptic/haptic_plugin_intf.h"
libhaptic-plugin-devel_files += "/usr/lib/pkgconfig/haptic-plugin.pc"

FILES_${PN} = "${libhaptic_files}"
FILES_${PN}-devel = "${libhaptic-devel_files}"
FILES_${PN}-plugin-devel = "${libhaptic-plugin-devel_files}"

PKG_libhaptic= "libhaptic"
PKG_libhaptic-devel= "libhaptic-devel"
PKG_libhaptic-plugin-devel= "libhaptic-plugin-devel"

require libhaptic-extraconf.inc
