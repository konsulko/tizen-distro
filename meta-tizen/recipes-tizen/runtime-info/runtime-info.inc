DESCRIPTION = "A Runtime Information library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-runtime-info-devel 
PROVIDES += "capi-system-runtime-info-devel"
RPROVIDES_capi-system-runtime-info-devel += "capi-system-runtime-info-devel"
RPROVIDES_capi-system-runtime-info-devel += "capi-system-runtime-info-dev"

#PROVIDES by capi-system-runtime-info 
PROVIDES += "capi-system-runtime-info"
RPROVIDES_capi-system-runtime-info += "capi-system-runtime-info"

RDEPENDS = ""
#RDEPENDS of capi-system-runtime-info-devel (capi-system-${PN}-devel)
RDEPENDS_capi-system-${PN}-devel += "pkgconfig(capi-base-common)"
RDEPENDS_capi-system-${PN}-devel += "capi-system-runtime-info"


DEPENDS = ""
#DEPENDS of capi-system-runtime-info 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-system-runtime-info.manifest ${S}/packaging/capi-system-runtime-info-devel.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.0.3 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.0.3 -DMAJORVER=${MAJORVER}
 
 
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
PACKAGES += "capi-system-runtime-info-devel"
PACKAGES += "capi-system-runtime-info"

capi-system-runtime-info-devel_files = ""
capi-system-runtime-info-devel_files += "capi-system-runtime-info-devel.manifest"
capi-system-runtime-info-devel_files += "/usr/include/system/*.h"
capi-system-runtime-info-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-runtime-info-devel_files += "/usr/lib/lib*.so"

capi-system-runtime-info_files = ""
capi-system-runtime-info_files += "capi-system-runtime-info.manifest"
capi-system-runtime-info_files += "/usr/lib/lib*.so.*"

FILES_${PN}-devel = "${capi-system-runtime-info-devel_files}"
FILES_${PN} = "${capi-system-runtime-info_files}"

PKG_capi-system-runtime-info-devel= "capi-system-runtime-info-devel"
PKG_capi-system-runtime-info= "capi-system-runtime-info"

require runtime-info-extraconf.inc
