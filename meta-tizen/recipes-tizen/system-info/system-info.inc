DESCRIPTION = "A System Information library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by capi-system-info-dev 


#PROVIDES by capi-system-info 


RDEPENDS = ""
#RDEPENDS of capi-system-info-dev (capi-${PN}-dev)
RDEPENDS_capi-${PN}-dev += "capi-system-info"


DEPENDS = ""
#DEPENDS of capi-system-info 
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "libxml2"
DEPENDS += "iniparser"
DEPENDS += "common"
DEPENDS += "ecore"
DEPENDS += "sound-manager"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-system-info.manifest .
 
 
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
 
 MAJORVER=`echo 0.2.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.2.0 -DMAJORVER=${MAJORVER} -DENABLE_WAYLAND=TRUE
 
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
 mkdir -p ${D}/etc
 cp -f script/make_info_file.sh ${D}${sysconfdir}/make_info_file.sh
 
 
}

PACKAGES += " capi-system-info-dev "
PACKAGES += " capi-system-info "

capi-system-info-dev_files = ""
capi-system-info-dev_files += "capi-system-info.manifest"
capi-system-info-dev_files += "${prefix}/include/system/system_info.h"
capi-system-info-dev_files += "${prefix}/lib/pkgconfig/*.pc"
capi-system-info-dev_files += "${prefix}/lib/libcapi-system-info.so"

capi-system-info_files = ""
capi-system-info_files += "capi-system-info.manifest"
capi-system-info_files += "${prefix}/lib/libcapi-system-info.so.*"
capi-system-info_files += "${sysconfdir}/make_info_file.sh"
capi-system-info_files += "system-info.manifest"

FILES_${PN}-dev = "${capi-system-info-dev_files}"
FILES_${PN} = "${capi-system-info_files}"

PKG_capi-system-info-dev= "capi-system-info-dev"
PKG_capi-system-info= "capi-system-info"

require system-info-extraconf.inc

