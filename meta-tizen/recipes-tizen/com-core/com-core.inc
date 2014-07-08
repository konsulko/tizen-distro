DESCRIPTION = "Library for the light-weight IPC"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/IPC"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libcom-core


#PROVIDES by libcom-core-dev


RDEPENDS = ""
#RDEPENDS of libcom-core-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "libcom-core"


DEPENDS = ""
#DEPENDS of libcom-core
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "systemd"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libcom-core.manifest .
 
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON \
         ${EXTRA_OECMAKE} 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/${prefix}/share/license
 
 
}

pkg_postinst_libcom-core() {
    #!/bin/sh -e

    [ "x\$D" != "x" ] && ldconfig
}

pkg_postrm_libcom-core() {
    #!/bin/sh -e

    [ "x\$D" != "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libcom-core "
PACKAGES += " libcom-core-dev "

libcom-core_files = ""
libcom-core_files += "libcom-core.manifest"
libcom-core_files += "${prefix}/lib/*.so*"
libcom-core_files += "${prefix}/share/license/*"

libcom-core-dev_files = ""
libcom-core-dev_files += "libcom-core.manifest"
libcom-core-dev_files += "${prefix}/include/com-core/com-core.h"
libcom-core-dev_files += "${prefix}/include/com-core/packet.h"
libcom-core-dev_files += "${prefix}/include/com-core/com-core_packet.h"
libcom-core-dev_files += "${prefix}/include/com-core/com-core_thread.h"
libcom-core-dev_files += "${prefix}/include/com-core/secure_socket.h"
libcom-core-dev_files += "${prefix}/lib/pkgconfig/*.pc"

FILES_lib${PN} = "${libcom-core_files}"
FILES_lib${PN}-dev = "${libcom-core-dev_files}"

PKG_libcom-core= "libcom-core"
PKG_libcom-core-dev= "libcom-core-dev"

require com-core-extraconf.inc

