DESCRIPTION = "A System Information library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-info-devel 
PROVIDES += "capi-system-info-devel"
RPROVIDES_capi-system-info-devel += "capi-system-info-devel"
RPROVIDES_capi-system-info-devel += "capi-system-info-dev"

#PROVIDES by capi-system-info 
PROVIDES += "capi-system-info"
RPROVIDES_capi-system-info += "capi-system-info"

RDEPENDS = ""
#RDEPENDS of capi-system-info-devel (capi-${PN}-devel)
RDEPENDS_capi-${PN}-devel += "capi-system-info"


DEPENDS = ""
#DEPENDS of capi-system-info 
DEPENDS += "pkgconfig(ecore-wayland)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "common"
DEPENDS += "pkgconfig(capi-media-sound-manager)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-system-info.manifest .
 
 
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
 
 MAJORVER=`echo 0.2.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.2.0 -DMAJORVER=${MAJORVER} -DENABLE_WAYLAND=TRUE
 
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
 mkdir -p ${D}/etc
 cp -f script/make_info_file.sh ${D}/etc/make_info_file.sh
 
 
}

PACKAGES = ""
PACKAGES += "capi-system-info-devel"
PACKAGES += "capi-system-info"

capi-system-info-devel_files = ""
capi-system-info-devel_files += "capi-system-info.manifest"
capi-system-info-devel_files += "/usr/include/system/system_info.h"
capi-system-info-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-info-devel_files += "/usr/lib/libcapi-system-info.so"

capi-system-info_files = ""
capi-system-info_files += "capi-system-info.manifest"
capi-system-info_files += "/usr/lib/libcapi-system-info.so.*"
capi-system-info_files += "system-info.manifest"

FILES_${PN}-devel = "${capi-system-info-devel_files}"
FILES_${PN} = "${capi-system-info_files}"

PKG_capi-system-info-devel= "capi-system-info-devel"
PKG_capi-system-info= "capi-system-info"

require system-info-extraconf.inc
