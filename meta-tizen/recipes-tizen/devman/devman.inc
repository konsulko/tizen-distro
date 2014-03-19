DESCRIPTION = "Device manager library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdevman-devel 
PROVIDES += "libdevman-devel"
RPROVIDES_libdevman-devel += "libdevman-devel"
RPROVIDES_libdevman-devel += "libdevman-dev"

#PROVIDES by libdevman-haptic-devel 
PROVIDES += "libdevman-haptic-devel"
RPROVIDES_libdevman-haptic-devel += "libdevman-haptic-devel"
RPROVIDES_libdevman-haptic-devel += "libdevman-haptic-dev"

#PROVIDES by devman 
PROVIDES += "devman"
RPROVIDES_devman += "devman"

#PROVIDES by libdevman 
PROVIDES += "libdevman"
RPROVIDES_libdevman += "libdevman"

RDEPENDS = ""
#RDEPENDS of libdevman-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libdevman"

#RDEPENDS of libdevman-haptic-devel (lib${PN}-haptic-devel)
RDEPENDS_lib${PN}-haptic-devel += "libdevman-dev"


DEPENDS = ""
#DEPENDS of devman 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(device-node)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(heynoti)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(haptic)"

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
 
 cp ${S}/packaging/devman.manifest .
 
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
PACKAGES += "libdevman-devel"
PACKAGES += "libdevman-haptic-devel"
PACKAGES += "libdevman"

libdevman-devel_files = ""
libdevman-devel_files += "devman.manifest"
libdevman-devel_files += "/usr/include/devman/devman.h"
libdevman-devel_files += "/usr/include/devman/devman_managed.h"
libdevman-devel_files += "/usr/include/devman/devman_image.h"
libdevman-devel_files += "/usr/include/devman/devman_haptic.h"
libdevman-devel_files += "/usr/lib/pkgconfig/devman.pc"
libdevman-devel_files += "/usr/lib/libdevman.so"

libdevman-haptic-devel_files = ""
libdevman-haptic-devel_files += "devman.manifest"
libdevman-haptic-devel_files += "/usr/include/devman/devman_haptic_ext.h"
libdevman-haptic-devel_files += "/usr/include/devman/devman_haptic_ext_core.h"
libdevman-haptic-devel_files += "/usr/lib/pkgconfig/devman_haptic.pc"

libdevman_files = ""
libdevman_files += "devman.manifest"
libdevman_files += "/usr/bin/display_wd"
libdevman_files += "/usr/lib/libdevman.so.*"

FILES_lib${PN}-devel = "${libdevman-devel_files}"
FILES_lib${PN}-haptic-devel = "${libdevman-haptic-devel_files}"
FILES_lib${PN} = "${libdevman_files}"

PKG_libdevman-devel= "libdevman-devel"
PKG_libdevman-haptic-devel= "libdevman-haptic-devel"
PKG_libdevman= "libdevman"

require devman-extraconf.inc
