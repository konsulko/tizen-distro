DESCRIPTION = "Telephony SIM Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Telephony/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-telephony-sim 
PROVIDES += "capi-telephony-sim"
RPROVIDES_capi-telephony-sim += "capi-telephony-sim"

#PROVIDES by capi-telephony-sim-devel 
PROVIDES += "capi-telephony-sim-devel"
RPROVIDES_capi-telephony-sim-devel += "capi-telephony-sim-devel"
RPROVIDES_capi-telephony-sim-devel += "capi-telephony-sim-dev"

RDEPENDS = ""
#RDEPENDS of capi-telephony-sim-devel (capi-telephony-${PN}-devel)
RDEPENDS_capi-telephony-${PN}-devel += "capi-telephony-sim"


DEPENDS = ""
#DEPENDS of capi-telephony-sim 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-telephony-sim.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.7 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.7 -DMAJORVER=${MAJORVER}
 
 
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
PACKAGES += "capi-telephony-sim"
PACKAGES += "capi-telephony-sim-devel"

capi-telephony-sim_files = ""
capi-telephony-sim_files += "capi-telephony-sim.manifest"
capi-telephony-sim_files += "capi-telephony-sim.manifest"
capi-telephony-sim_files += "/usr/lib/libcapi-telephony-sim.so.*"

capi-telephony-sim-devel_files = ""
capi-telephony-sim-devel_files += "capi-telephony-sim.manifest"
capi-telephony-sim-devel_files += "/usr/include/telephony/sim.h"
capi-telephony-sim-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-telephony-sim-devel_files += "/usr/lib/libcapi-telephony-sim.so"

FILES_${PN} = "${capi-telephony-sim_files}"
FILES_${PN}-devel = "${capi-telephony-sim-devel_files}"

PKG_capi-telephony-sim= "capi-telephony-sim"
PKG_capi-telephony-sim-devel= "capi-telephony-sim-devel"

require sim-extraconf.inc
