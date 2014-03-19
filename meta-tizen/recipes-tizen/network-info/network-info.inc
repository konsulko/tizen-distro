DESCRIPTION = "A Telephony Network Information library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-telephony-network-info 
PROVIDES += "capi-telephony-network-info"
RPROVIDES_capi-telephony-network-info += "capi-telephony-network-info"

#PROVIDES by capi-telephony-network-info-devel 
PROVIDES += "capi-telephony-network-info-devel"
RPROVIDES_capi-telephony-network-info-devel += "capi-telephony-network-info-devel"
RPROVIDES_capi-telephony-network-info-devel += "capi-telephony-network-info-dev"

RDEPENDS = ""
#RDEPENDS of capi-telephony-network-info-devel (capi-telephony-${PN}-devel)
RDEPENDS_capi-telephony-${PN}-devel += "capi-telephony-network-info"


DEPENDS = ""
#DEPENDS of capi-telephony-network-info 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-telephony-network-info.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
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
PACKAGES += "capi-telephony-network-info"
PACKAGES += "capi-telephony-network-info-devel"

capi-telephony-network-info_files = ""
capi-telephony-network-info_files += "capi-telephony-network-info.manifest"
capi-telephony-network-info_files += "/usr/lib/libcapi-telephony-network-info.so.*"

capi-telephony-network-info-devel_files = ""
capi-telephony-network-info-devel_files += "capi-telephony-network-info.manifest"
capi-telephony-network-info-devel_files += "/usr/include/telephony/*.h"
capi-telephony-network-info-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-telephony-network-info-devel_files += "/usr/lib/libcapi-telephony-network-info.so"

FILES_${PN} = "${capi-telephony-network-info_files}"
FILES_${PN}-devel = "${capi-telephony-network-info-devel_files}"

PKG_capi-telephony-network-info= "capi-telephony-network-info"
PKG_capi-telephony-network-info-devel= "capi-telephony-network-info-devel"

require network-info-extraconf.inc
