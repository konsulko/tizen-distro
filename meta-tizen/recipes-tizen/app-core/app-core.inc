DESCRIPTION = "Application basic"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by app-core-efl


#PROVIDES by app-core-template


#PROVIDES by app-core


#PROVIDES by app-core-common-dev


#PROVIDES by app-core-common


#PROVIDES by app-core-efl-dev


RDEPENDS = ""
#RDEPENDS of app-core-efl (${PN}-efl)
RDEPENDS_${PN}-efl += "eglibc"

#RDEPENDS of app-core-common-dev (${PN}-common-dev)
RDEPENDS_${PN}-common-dev += "elementary"
RDEPENDS_${PN}-common-dev += "app-core-common"
RDEPENDS_${PN}-common-dev += "vconf"
RDEPENDS_${PN}-common-dev += "libslp-sensor"
RDEPENDS_${PN}-common-dev += "aul"

#RDEPENDS of app-core-common (${PN}-common)
RDEPENDS_${PN}-common += "eglibc"

#RDEPENDS of app-core-efl-dev (${PN}-efl-dev)
RDEPENDS_${PN}-efl-dev += "app-core-efl"
RDEPENDS_${PN}-efl-dev += "app-core-common-dev"


DEPENDS = ""
#DEPENDS of app-core
DEPENDS += "librua"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "tizen-platform-config"
DEPENDS += "aul"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "libslp-sensor"
DEPENDS += "elementary"
DEPENDS += "ecore"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/app-core.manifest .
 
 
 
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
         ${EXTRA_OECMAKE} . \
 -Dwith_wayland=TRUE\
 -DENABLE_GTK=OFF
 
 make 
 
 
 
 
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
 install -d ${D}/lib/systemd/user/core-efl.target.wants
 install -m0644 ${S}/packaging/core-efl-wayland.target ${D}/lib/systemd/user/core-efl.target
 
 
 
}

pkg_postinst_app-core-common() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postinst_app-core-efl() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_app-core-efl() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_app-core-common() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " app-core-efl-dev "
PACKAGES += " app-core-efl "
PACKAGES += " app-core-common "
PACKAGES += " app-core-common-dev "

app-core-efl-dev_files = ""
app-core-efl-dev_files += "app-core.manifest"
app-core-efl-dev_files += "${prefix}/include/appcore/appcore-efl.h"
app-core-efl-dev_files += "${prefix}/lib/libappcore-efl.so"
app-core-efl-dev_files += "${prefix}/lib/pkgconfig/appcore-efl.pc"

app-core-efl_files = ""
app-core-efl_files += "app-core.manifest"
app-core-efl_files += "${prefix}/lib/libappcore-efl.so.*"

app-core-common_files = ""
app-core-common_files += "app-core.manifest"
app-core-common_files += "${prefix}/lib/libappcore-common.so.*"
app-core-common_files += "${prefix}/lib/systemd/user/core-efl.target"
app-core-common_files += "${prefix}/lib/systemd/user/core-efl.target.wants/"

app-core-common-dev_files = ""
app-core-common-dev_files += "app-core.manifest"
app-core-common-dev_files += "${prefix}/lib/libappcore-common.so"
app-core-common-dev_files += "${prefix}/lib/pkgconfig/appcore-common.pc"
app-core-common-dev_files += "${prefix}/include/appcore/appcore-common.h"
app-core-common-dev_files += "${prefix}/include/SLP_Appcore_PG.h"

FILES_${PN}-efl-dev = "${app-core-efl-dev_files}"
FILES_${PN}-efl = "${app-core-efl_files}"
FILES_${PN}-common = "${app-core-common_files}"
FILES_${PN}-common-dev = "${app-core-common-dev_files}"

PKG_app-core-efl-dev= "app-core-efl-dev"
PKG_app-core-efl= "app-core-efl"
PKG_app-core-common= "app-core-common"
PKG_app-core-common-dev= "app-core-common-dev"

require app-core-extraconf.inc

