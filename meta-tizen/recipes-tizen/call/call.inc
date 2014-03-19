DESCRIPTION = "Telephony Call Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-telephony-call-devel 
PROVIDES += "capi-telephony-call-devel"
RPROVIDES_capi-telephony-call-devel += "capi-telephony-call-devel"
RPROVIDES_capi-telephony-call-devel += "capi-telephony-call-dev"

#PROVIDES by capi-telephony-call 
PROVIDES += "capi-telephony-call"
RPROVIDES_capi-telephony-call += "capi-telephony-call"

RDEPENDS = ""
#RDEPENDS of capi-telephony-call-devel (capi-telephony-${PN}-devel)
RDEPENDS_capi-telephony-${PN}-devel += "capi-telephony-call"


DEPENDS = ""
#DEPENDS of capi-telephony-call 
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(capi-base-common)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-telephony-call.manifest .
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .  -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-telephony-call-devel"
PACKAGES += "capi-telephony-call"

capi-telephony-call-devel_files = ""
capi-telephony-call-devel_files += "capi-telephony-call.manifest"
capi-telephony-call-devel_files += "/usr/include/telephony/call.h"
capi-telephony-call-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-telephony-call-devel_files += "/usr/lib/libcapi-telephony-call.so"

capi-telephony-call_files = ""
capi-telephony-call_files += "capi-telephony-call.manifest"
capi-telephony-call_files += "/usr/lib/libcapi-telephony-call.so.*"

FILES_${PN}-devel = "${capi-telephony-call-devel_files}"
FILES_${PN} = "${capi-telephony-call_files}"

PKG_capi-telephony-call-devel= "capi-telephony-call-devel"
PKG_capi-telephony-call= "capi-telephony-call"

require call-extraconf.inc
