DESCRIPTION = "Internet bookmark and history API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Web Framework/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-web-favorites 
PROVIDES += "capi-web-favorites"
RPROVIDES_capi-web-favorites += "capi-web-favorites"

#PROVIDES by capi-web-favorites-devel 
PROVIDES += "capi-web-favorites-devel"
RPROVIDES_capi-web-favorites-devel += "capi-web-favorites-devel"
RPROVIDES_capi-web-favorites-devel += "capi-web-favorites-dev"

RDEPENDS = ""
#RDEPENDS of capi-web-favorites (capi-web-${PN})
RDEPENDS_capi-web-${PN} += "/sbin/ldconfig"

#RDEPENDS of capi-web-favorites-devel (capi-web-${PN}-devel)
RDEPENDS_capi-web-${PN}-devel += "capi-web-favorites"


DEPENDS = ""
#DEPENDS of capi-web-favorites 
DEPENDS += "common"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(evas)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-web-favorites.manifest .
 
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "capi-web-favorites"
PACKAGES += "capi-web-favorites-devel"

capi-web-favorites_files = ""
capi-web-favorites_files += "capi-web-favorites.manifest"
capi-web-favorites_files += "/usr/lib/libcapi-web-favorites.so"

capi-web-favorites-devel_files = ""
capi-web-favorites-devel_files += "capi-web-favorites.manifest"
capi-web-favorites-devel_files += "/usr/include/web/*.h"
capi-web-favorites-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${capi-web-favorites_files}"
FILES_${PN}-devel = "${capi-web-favorites-devel_files}"

PKG_capi-web-favorites= "capi-web-favorites"
PKG_capi-web-favorites-devel= "capi-web-favorites-devel"

require favorites-extraconf.inc
