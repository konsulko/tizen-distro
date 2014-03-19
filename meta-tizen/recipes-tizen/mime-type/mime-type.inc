DESCRIPTION = "A MIME type library in Tizen C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "APIs"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-content-mime-type 
PROVIDES += "capi-content-mime-type"
RPROVIDES_capi-content-mime-type += "capi-content-mime-type"

#PROVIDES by capi-content-mime-type-devel 
PROVIDES += "capi-content-mime-type-devel"
RPROVIDES_capi-content-mime-type-devel += "capi-content-mime-type-devel"
RPROVIDES_capi-content-mime-type-devel += "capi-content-mime-type-dev"

RDEPENDS = ""
#RDEPENDS of capi-content-mime-type-devel (capi-content-${PN}-devel)
RDEPENDS_capi-content-${PN}-devel += "capi-content-mime-type"
RDEPENDS_capi-content-${PN}-devel += "pkgconfig(capi-base-common)"


DEPENDS = ""
#DEPENDS of capi-content-mime-type 
DEPENDS += "pkgconfig(xdgmime)"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-content-mime-type.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.0.2 | awk 'BEGIN {FS="."}{print $1}'`  
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .  -DFULLVER=0.0.2 -DMAJORVER=${MAJORVER} 
 
 
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
PACKAGES += "capi-content-mime-type"
PACKAGES += "capi-content-mime-type-devel"

capi-content-mime-type_files = ""
capi-content-mime-type_files += "capi-content-mime-type.manifest"
capi-content-mime-type_files += "/usr/lib/lib*.so.*"
capi-content-mime-type_files += "capi-content-mime-type.manifest"

capi-content-mime-type-devel_files = ""
capi-content-mime-type-devel_files += "capi-content-mime-type.manifest"
capi-content-mime-type-devel_files += "/usr/include/content/*.h"
capi-content-mime-type-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-content-mime-type-devel_files += "/usr/lib/lib*.so"

FILES_${PN} = "${capi-content-mime-type_files}"
FILES_${PN}-devel = "${capi-content-mime-type-devel_files}"

PKG_capi-content-mime-type= "capi-content-mime-type"
PKG_capi-content-mime-type-devel= "capi-content-mime-type-devel"

require mime-type-extraconf.inc
