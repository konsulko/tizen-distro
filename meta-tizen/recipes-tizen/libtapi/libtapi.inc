DESCRIPTION = "Telephony client API library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Telephony/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libtapi3


#PROVIDES by libtapi3-dev


RDEPENDS = ""
#RDEPENDS of libtapi3-dev (${PN}3-dev)
RDEPENDS_${PN}3-dev += "libtapi3"


DEPENDS = ""
#DEPENDS of libtapi3
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
inherit pythonnative
DEPENDS += "security-server"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "python-xml"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtapi.manifest .
 
 
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
         ${EXTRA_OECMAKE} . -DTAPI_VERSION=3.0.1
 
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
PACKAGES += " libtapi3 "
PACKAGES += " libtapi3-dev "

libtapi3_files = ""
libtapi3_files += "libtapi.manifest"
libtapi3_files += "${prefix}/lib/*.so*"
libtapi3_files += "${prefix}/bin/tapitest"

libtapi3-dev_files = ""
libtapi3-dev_files += "libtapi.manifest"
libtapi3-dev_files += "${prefix}/include/tapi-3.0/*.h"
libtapi3-dev_files += "${prefix}/include/tapi-3.0/common/*.h"
libtapi3-dev_files += "${prefix}/include/tapi-3.0/private/*.h"
libtapi3-dev_files += "${prefix}/lib/pkgconfig/*.pc"
libtapi3-dev_files += "${prefix}/lib/*.so"

FILES_${PN}3 = "${libtapi3_files}"
FILES_${PN}3-dev = "${libtapi3-dev_files}"

PKG_libtapi3= "libtapi3"
PKG_libtapi3-dev= "libtapi3-dev"

require libtapi-extraconf.inc

