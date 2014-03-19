DESCRIPTION = "Feedback library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libfeedback-devel 
PROVIDES += "libfeedback-devel"
RPROVIDES_libfeedback-devel += "libfeedback-devel"
RPROVIDES_libfeedback-devel += "libfeedback-dev"

#PROVIDES by libsvi 
PROVIDES += "libsvi"
RPROVIDES_libsvi += "libsvi"

#PROVIDES by libsvi-devel 
PROVIDES += "libsvi-devel"
RPROVIDES_libsvi-devel += "libsvi-devel"
RPROVIDES_libsvi-devel += "libsvi-dev"

#PROVIDES by svi-data 
PROVIDES += "svi-data"
RPROVIDES_svi-data += "svi-data"

#PROVIDES by libfeedback 
PROVIDES += "libfeedback"
RPROVIDES_libfeedback += "libfeedback"

RDEPENDS = ""
#RDEPENDS of libfeedback-devel (libfeedback-devel)
RDEPENDS_libfeedback-devel += "libfeedback"

#RDEPENDS of libsvi (${PN})
RDEPENDS_${PN} += "libfeedback"

#RDEPENDS of libfeedback (libfeedback)
RDEPENDS_libfeedback += "/sbin/ldconfig"

#RDEPENDS of libsvi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsvi"


DEPENDS = ""
#DEPENDS of libfeedback 
DEPENDS += "libhaptic"
DEPENDS += "libmm-sound"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 
 
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
 
 cp ${S}/packaging/libsvi.manifest .
 cp ${S}/packaging/libfeedback.manifest .
 cp ${S}/packaging/svi-data-sdk.manifest .
 
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
 make
 
 
 
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
 
 mkdir -p ${D}/opt/share/svi/sound/touch
 mkdir -p ${D}/opt/share/svi/sound/operation
 mkdir -p ${D}/opt/share/svi/haptic/default
 mkdir -p ${D}/opt/share/svi/haptic/touch
 
 
}

PACKAGES = ""
PACKAGES += "libfeedback-devel"
PACKAGES += "svi-data"
PACKAGES += "libfeedback"
PACKAGES += "libsvi-devel"
PACKAGES += "libsvi"

libfeedback-devel_files = ""
libfeedback-devel_files += "libfeedback.manifest"
libfeedback-devel_files += "/usr/include/feedback/*.h"
libfeedback-devel_files += "/usr/lib/libfeedback.so"
libfeedback-devel_files += "/usr/lib/pkgconfig/feedback.pc"

svi-data_files = ""
svi-data_files += "libfeedback.manifest"
svi-data_files += "/usr/share/svi/*"
svi-data_files += "/opt/share/svi/sound/touch"
svi-data_files += "/opt/share/svi/sound/operation"
svi-data_files += "/opt/share/svi/haptic/default"
svi-data_files += "/opt/share/svi/haptic/touch"

libfeedback_files = ""
libfeedback_files += "libfeedback.manifest"
libfeedback_files += "/usr/lib/libfeedback.so.*"

libsvi-devel_files = ""
libsvi-devel_files += "libfeedback.manifest"
libsvi-devel_files += "/usr/include/svi/*.h"
libsvi-devel_files += "/usr/lib/libsvi.so"
libsvi-devel_files += "/usr/lib/pkgconfig/svi.pc"

libsvi_files = ""
libsvi_files += "libfeedback.manifest"
libsvi_files += "/usr/lib/libsvi.so.*"

FILES_${PN}-devel = "${libfeedback-devel_files}"
FILES_svi-data = "${svi-data_files}"
FILES_${PN} = "${libfeedback_files}"
FILES_libsvi-devel = "${libsvi-devel_files}"
FILES_libsvi = "${libsvi_files}"

PKG_libfeedback-devel= "libfeedback-devel"
PKG_svi-data= "svi-data"
PKG_libfeedback= "libfeedback"
PKG_libsvi-devel= "libsvi-devel"
PKG_libsvi= "libsvi"

require libsvi-extraconf.inc
