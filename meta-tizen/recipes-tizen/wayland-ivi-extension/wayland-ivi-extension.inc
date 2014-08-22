DESCRIPTION = "GENIVI Shell Plugin-in"
HOMEPAGE = "http://git.projects.genivi.org/wayland-ivi-extension.git"
SECTION = "Graphics & UI Framework/Wayland Window System"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by genivi-shell
PROVIDES += "genivi-shell"


#PROVIDES by genivi-shell-dev
PROVIDES += "genivi-shell-dev"


RDEPENDS = ""
#RDEPENDS of genivi-shell-dev (genivi-shell-dev)
RDEPENDS_genivi-shell-dev += "wayland-ivi-extension"


DEPENDS = ""
#DEPENDS of genivi-shell
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "libxkbcommon"
DEPENDS += "cairo"
DEPENDS += "weston"
DEPENDS += "wayland"
DEPENDS += "libffi"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/genivi-shell.manifest .
 
 /usr/bin/wayland-scanner code < protocol/ivi-controller.xml \
     > protocol/ivi-controller-protocol.c
 
 
 
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
         ${EXTRA_OECMAKE} .
 
 
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
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
 make -j16
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
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
 
 install -d ${D}/${prefix}/share/genivi-shell/protocol/
 
 install -m 644 protocol/ivi-application.xml ${D}/${prefix}/share/genivi-shell/protocol/
 install -m 644 protocol/ivi-controller.xml ${D}/${prefix}/share/genivi-shell/protocol/
 
 install -m 644 protocol/ivi-application-server-protocol.h \
     ${D}/${prefix}/share/genivi-shell/protocol/
 
 install -m 644 protocol/ivi-application-protocol.c \
     ${D}/${prefix}/share/genivi-shell/protocol/
 
 install -m 644 protocol/ivi-controller-server-protocol.h \
     ${D}/${prefix}/share/genivi-shell/protocol/
 
 install -m 644 protocol/ivi-controller-protocol.c \
     ${D}/${prefix}/share/genivi-shell/protocol/
 
 
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
PACKAGES += " genivi-shell "
PACKAGES += " genivi-shell-dev "

genivi-shell_files = ""
genivi-shell_files += "${prefix}/bin/LayerManagerControl"
genivi-shell_files += "${prefix}/bin/EGLWLMockNavigation"
genivi-shell_files += "${prefix}/lib/libilmClient.so.*"
genivi-shell_files += "${prefix}/lib/libilmCommon.so.*"
genivi-shell_files += "${prefix}/lib/libilmControl.so.*"
genivi-shell_files += "${prefix}/lib/weston/ivi-controller.so"
MANIFESTFILES_genivi-shell = "genivi-shell.manifest"

genivi-shell-dev_files = ""
genivi-shell-dev_files += "${prefix}/include/ilm/ilm_client.h"
genivi-shell-dev_files += "${prefix}/include/ilm/ilm_common.h"
genivi-shell-dev_files += "${prefix}/include/ilm/ilm_control.h"
genivi-shell-dev_files += "${prefix}/include/ilm/ilm_platform.h"
genivi-shell-dev_files += "${prefix}/include/ilm/ilm_types.h"
genivi-shell-dev_files += "${prefix}/lib/libilmClient.so"
genivi-shell-dev_files += "${prefix}/lib/libilmCommon.so"
genivi-shell-dev_files += "${prefix}/lib/libilmControl.so"
genivi-shell-dev_files += "${prefix}/share/genivi-shell/protocol/*.xml"
genivi-shell-dev_files += "${prefix}/share/genivi-shell/protocol/*.h"
genivi-shell-dev_files += "${prefix}/share/genivi-shell/protocol/*.c"

FILES_genivi-shell = "${genivi-shell_files}"
FILES_genivi-shell-dev = "${genivi-shell-dev_files}"

PKG_genivi-shell= "genivi-shell"
PKG_genivi-shell-dev= "genivi-shell-dev"

require wayland-ivi-extension-extraconf.inc

