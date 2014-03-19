DESCRIPTION = "A Image Utility library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-image-util-devel 
PROVIDES += "capi-media-image-util-devel"
RPROVIDES_capi-media-image-util-devel += "capi-media-image-util-devel"
RPROVIDES_capi-media-image-util-devel += "capi-media-image-util-dev"

#PROVIDES by capi-media-image-util 
PROVIDES += "capi-media-image-util"
RPROVIDES_capi-media-image-util += "capi-media-image-util"

RDEPENDS = ""
#RDEPENDS of capi-media-image-util-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-image-util"
RDEPENDS_capi-media-${PN}-devel += "pkgconfig(capi-base-common)"
RDEPENDS_capi-media-${PN}-devel += "pkgconfig(mmutil-imgp)"
RDEPENDS_capi-media-${PN}-devel += "pkgconfig(mmutil-jpeg)"
RDEPENDS_capi-media-${PN}-devel += "pkgconfig(mm-common)"
RDEPENDS_capi-media-${PN}-devel += "pkgconfig(dlog)"


DEPENDS = ""
#DEPENDS of capi-media-image-util 
DEPENDS += "cmake"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "dlog"
DEPENDS += "pkgconfig(mmutil-imgp)"
DEPENDS += "common"
DEPENDS += "pkgconfig(mmutil-jpeg)"
DEPENDS += "pkgconfig(mm-common)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-image-util.manifest .
 
 
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
PACKAGES += "capi-media-image-util-devel"
PACKAGES += "capi-media-image-util"

capi-media-image-util-devel_files = ""
capi-media-image-util-devel_files += "capi-media-image-util.manifest"
capi-media-image-util-devel_files += "/usr/lib/lib*.so"
capi-media-image-util-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-image-util-devel_files += "/usr/include/media/*.h"

capi-media-image-util_files = ""
capi-media-image-util_files += "capi-media-image-util.manifest"
capi-media-image-util_files += "capi-media-image-util.manifest"
capi-media-image-util_files += "/usr/lib/lib*.so.*"

FILES_${PN}-devel = "${capi-media-image-util-devel_files}"
FILES_${PN} = "${capi-media-image-util_files}"

PKG_capi-media-image-util-devel= "capi-media-image-util-devel"
PKG_capi-media-image-util= "capi-media-image-util"

require image-util-extraconf.inc
