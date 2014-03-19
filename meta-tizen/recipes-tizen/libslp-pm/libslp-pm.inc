DESCRIPTION = "Power manager library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "TO BE FILLED IN"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libslp-pm 
PROVIDES += "libslp-pm"
RPROVIDES_libslp-pm += "libslp-pm"

#PROVIDES by libslp-pm-devel 
PROVIDES += "libslp-pm-devel"
RPROVIDES_libslp-pm-devel += "libslp-pm-devel"
RPROVIDES_libslp-pm-devel += "libslp-pm-dev"

RDEPENDS = ""
#RDEPENDS of libslp-pm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libslp-pm"


DEPENDS = ""
#DEPENDS of libslp-pm 
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/libslp-pm.manifest .
 
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 
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
PACKAGES += "libslp-pm"
PACKAGES += "libslp-pm-devel"

libslp-pm_files = ""
libslp-pm_files += "libslp-pm.manifest"
libslp-pm_files += "libslp-pm.manifest"
libslp-pm_files += "/usr/lib/libpmapi.so.1.2"

libslp-pm-devel_files = ""
libslp-pm-devel_files += "libslp-pm.manifest"
libslp-pm-devel_files += "/usr/include/pmapi.h"
libslp-pm-devel_files += "/usr/include/pmapi_managed.h"
libslp-pm-devel_files += "/usr/include/SLP_pm_PG.h"
libslp-pm-devel_files += "/usr/lib/pkgconfig/pmapi.pc"
libslp-pm-devel_files += "/usr/lib/libpmapi.so"

FILES_${PN} = "${libslp-pm_files}"
FILES_${PN}-devel = "${libslp-pm-devel_files}"

PKG_libslp-pm= "libslp-pm"
PKG_libslp-pm-devel= "libslp-pm-devel"

require libslp-pm-extraconf.inc
