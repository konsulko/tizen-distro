DESCRIPTION = "A Location Manager library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Location/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-location-manager-devel 
PROVIDES += "capi-location-manager-devel"
RPROVIDES_capi-location-manager-devel += "capi-location-manager-devel"
RPROVIDES_capi-location-manager-devel += "capi-location-manager-dev"

#PROVIDES by capi-location-manager 
PROVIDES += "capi-location-manager"
RPROVIDES_capi-location-manager += "capi-location-manager"

RDEPENDS = ""
#RDEPENDS of capi-location-manager-devel (capi-${PN}-devel)
RDEPENDS_capi-${PN}-devel += "capi-location-manager"


DEPENDS = ""
#DEPENDS of capi-location-manager 
DEPENDS += "pkgconfig(location)"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-location-manager.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.11 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.11 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-location-manager-devel"
PACKAGES += "capi-location-manager"

capi-location-manager-devel_files = ""
capi-location-manager-devel_files += "capi-location-manager.manifest"
capi-location-manager-devel_files += "/usr/include/location/*.h"
capi-location-manager-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-location-manager-devel_files += "/usr/lib/libcapi-location-manager.so"

capi-location-manager_files = ""
capi-location-manager_files += "capi-location-manager.manifest"
capi-location-manager_files += "capi-location-manager.manifest"
capi-location-manager_files += "/usr/lib/libcapi-location-manager.so.*"

FILES_${PN}-devel = "${capi-location-manager-devel_files}"
FILES_${PN} = "${capi-location-manager_files}"

PKG_capi-location-manager-devel= "capi-location-manager-devel"
PKG_capi-location-manager= "capi-location-manager"

require location-manager-extraconf.inc
