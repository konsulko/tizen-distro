DESCRIPTION = "Common header files of Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-base-common-dev


#PROVIDES by capi-base-common


RDEPENDS = ""
#RDEPENDS of capi-base-common-dev (capi-base-${PN}-dev)
RDEPENDS_capi-base-${PN}-dev += "capi-base-common"


DEPENDS = ""
#DEPENDS of capi-base-common
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-base-common.manifest .
 
 
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

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-base-common-dev "
PACKAGES += " capi-base-common "

capi-base-common-dev_files = ""
capi-base-common-dev_files += "capi-base-common.manifest"
capi-base-common-dev_files += "${prefix}/include/*.h"
capi-base-common-dev_files += "${prefix}/lib/pkgconfig/capi-base-common.pc"

capi-base-common_files = ""
capi-base-common_files += "capi-base-common.manifest"

FILES_capi-base-${PN}-dev = "${capi-base-common-dev_files}"
FILES_capi-base-${PN} = "${capi-base-common_files}"

PKG_capi-base-common-dev= "capi-base-common-dev"
PKG_capi-base-common= "capi-base-common"

require common-extraconf.inc

