DESCRIPTION = "HEY (ligHt Easy speedy) notification library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by heynoti


#PROVIDES by heynoti-dev


RDEPENDS = ""
#RDEPENDS of heynoti-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "heynoti"


DEPENDS = ""
#DEPENDS of heynoti
DEPENDS += "ecore"
DEPENDS += "tizen-platform-config"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/heynoti.manifest .
 
 
 
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
         ${EXTRA_OECMAKE} . -DCMAKE_BUILD_TYPE="Debug"
 
 
 make ${PARALLEL_MAKE}
 
 
 
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
 
 mkdir -p ${D}${prefix}/share/noti
 mkdir -p ${D}/usr/share/license
 install LICENSE ${D}/usr/share/license/heynoti
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " heynoti "
PACKAGES += " heynoti-dev "

heynoti_files = ""
heynoti_files += "heynoti.manifest"
heynoti_files += "${prefix}/lib/libheynoti.so.0"
heynoti_files += "${prefix}/lib/libheynoti.so.0.0.2"
heynoti_files += "${prefix}/bin/heynotitool"
heynoti_files += "${prefix}/share/noti"
heynoti_files += "/usr/share/license/heynoti"

heynoti-dev_files = ""
heynoti-dev_files += "heynoti.manifest"
heynoti-dev_files += "${prefix}/include/heynoti/SLP_Heynoti_PG.h"
heynoti-dev_files += "${prefix}/include/heynoti/heynoti.h"
heynoti-dev_files += "${prefix}/lib/pkgconfig/heynoti.pc"
heynoti-dev_files += "${prefix}/lib/libheynoti.so"

FILES_${PN} = "${heynoti_files}"
FILES_${PN}-dev = "${heynoti-dev_files}"

PKG_heynoti= "heynoti"
PKG_heynoti-dev= "heynoti-dev"

require heynoti-extraconf.inc

