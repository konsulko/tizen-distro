DESCRIPTION = "DB Utility"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Database"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libslp-db-util-devel 
PROVIDES += "libslp-db-util-devel"
RPROVIDES_libslp-db-util-devel += "libslp-db-util-devel"
RPROVIDES_libslp-db-util-devel += "libslp-db-util-dev"

#PROVIDES by libslp-db-util 
PROVIDES += "libslp-db-util"
RPROVIDES_libslp-db-util += "libslp-db-util"

RDEPENDS = ""
#RDEPENDS of libslp-db-util-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libslp-db-util"


DEPENDS = ""
#DEPENDS of libslp-db-util 
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libslp-db-util.manifest ${S}/packaging/libslp-db-util-devel.manifest .
 
 
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
PACKAGES += "libslp-db-util-devel"
PACKAGES += "libslp-db-util"

libslp-db-util-devel_files = ""
libslp-db-util-devel_files += "libslp-db-util-devel.manifest"
libslp-db-util-devel_files += "/usr/include/db-util"
libslp-db-util-devel_files += "/usr/include/db-util/*.h"
libslp-db-util-devel_files += "/usr/lib/pkgconfig/db-util.pc"
libslp-db-util-devel_files += "/usr/lib/libSLP-db-util.so"

libslp-db-util_files = ""
libslp-db-util_files += "libslp-db-util.manifest"
libslp-db-util_files += "/usr/lib/libSLP-db-util.so.0"
libslp-db-util_files += "/usr/lib/libSLP-db-util.so.0.1.0"

FILES_${PN}-devel = "${libslp-db-util-devel_files}"
FILES_${PN} = "${libslp-db-util_files}"

PKG_libslp-db-util-devel= "libslp-db-util-devel"
PKG_libslp-db-util= "libslp-db-util"

require libslp-db-util-extraconf.inc
