DESCRIPTION = "Sensor framework common library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Sensor Framework"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsf-common 
PROVIDES += "libsf-common"
RPROVIDES_libsf-common += "libsf-common"

#PROVIDES by libsf-common-devel 
PROVIDES += "libsf-common-devel"
RPROVIDES_libsf-common-devel += "libsf-common-devel"
RPROVIDES_libsf-common-devel += "libsf-common-dev"

RDEPENDS = ""
#RDEPENDS of libsf-common-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsf-common"


DEPENDS = ""
#DEPENDS of libsf-common 
DEPENDS += "cmake"
DEPENDS += "attr"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libsf-common.manifest .
 
 
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
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/libsf-common
 
 
}

PACKAGES = ""
PACKAGES += "libsf-common"
PACKAGES += "libsf-common-devel"

libsf-common_files = ""
libsf-common_files += "libsf-common.manifest"
libsf-common_files += "/usr/lib/libsf_common.so"
libsf-common_files += "/usr/share/license/libsf-common"

libsf-common-devel_files = ""
libsf-common-devel_files += "libsf-common.manifest"
libsf-common-devel_files += "/usr/include/sf_common/*.h"
libsf-common-devel_files += "/usr/lib/pkgconfig/sf_common.pc"

FILES_${PN} = "${libsf-common_files}"
FILES_${PN}-devel = "${libsf-common-devel_files}"

PKG_libsf-common= "libsf-common"
PKG_libsf-common-devel= "libsf-common-devel"

require libsf-common-extraconf.inc
