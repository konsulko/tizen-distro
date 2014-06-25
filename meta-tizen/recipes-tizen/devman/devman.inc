DESCRIPTION = "Device manager library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libdevman-dev


#PROVIDES by libdevman-haptic-dev


#PROVIDES by devman


#PROVIDES by libdevman


RDEPENDS = ""
#RDEPENDS of libdevman-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "libdevman"

#RDEPENDS of libdevman-haptic-dev (lib${PN}-haptic-dev)
RDEPENDS_lib${PN}-haptic-dev += "libdevman-dev"


DEPENDS = ""
#DEPENDS of devman
DEPENDS += "libhaptic"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dlog"
DEPENDS += "libdevice-node"
DEPENDS += "heynoti"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON .
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libdevman-dev "
PACKAGES += " libdevman-haptic-dev "
PACKAGES += " libdevman "

libdevman-dev_files = ""
libdevman-dev_files += "devman.manifest"
libdevman-dev_files += "${prefix}/include/devman/devman.h"
libdevman-dev_files += "${prefix}/include/devman/devman_managed.h"
libdevman-dev_files += "${prefix}/include/devman/devman_image.h"
libdevman-dev_files += "${prefix}/include/devman/devman_haptic.h"
libdevman-dev_files += "${prefix}/lib/pkgconfig/devman.pc"
libdevman-dev_files += "${prefix}/lib/libdevman.so"

libdevman-haptic-dev_files = ""
libdevman-haptic-dev_files += "devman.manifest"
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext.h"
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext_core.h"
libdevman-haptic-dev_files += "${prefix}/lib/pkgconfig/devman_haptic.pc"

libdevman_files = ""
libdevman_files += "devman.manifest"
libdevman_files += "${prefix}/bin/display_wd"
libdevman_files += "${prefix}/lib/libdevman.so.*"

FILES_lib${PN}-dev = "${libdevman-dev_files}"
FILES_lib${PN}-haptic-dev = "${libdevman-haptic-dev_files}"
FILES_lib${PN} = "${libdevman_files}"

PKG_libdevman-dev= "libdevman-dev"
PKG_libdevman-haptic-dev= "libdevman-haptic-dev"
PKG_libdevman= "libdevman"

require devman-extraconf.inc

