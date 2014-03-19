DESCRIPTION = "Memo DB interface library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Libraries"
LICENSE = "Flora"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libslp-memo 
PROVIDES += "libslp-memo"
RPROVIDES_libslp-memo += "libslp-memo"

#PROVIDES by libslp-memo-devel 
PROVIDES += "libslp-memo-devel"
RPROVIDES_libslp-memo-devel += "libslp-memo-devel"
RPROVIDES_libslp-memo-devel += "libslp-memo-dev"

RDEPENDS = ""
#RDEPENDS of libslp-memo (${PN})
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of libslp-memo-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libslp-memo"


DEPENDS = ""
#DEPENDS of libslp-memo 
DEPENDS += "heynoti"
DEPENDS += "cmake"
DEPENDS += "libslp-db-util"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libslp-memo.manifest .
 
 
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
 
 export LDFLAGS+=" -Wl,--rpath=/usr/lib -Wl,--as-needed -Wl,--hash-style=both"
 
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
PACKAGES += "libslp-memo"
PACKAGES += "libslp-memo-devel"

libslp-memo_files = ""
libslp-memo_files += "libslp-memo.manifest"
libslp-memo_files += "libslp-memo.manifest"
libslp-memo_files += "/usr/lib/*.so.*"

libslp-memo-devel_files = ""
libslp-memo-devel_files += "libslp-memo.manifest"
libslp-memo-devel_files += "/usr/lib/*.so"
libslp-memo-devel_files += "/usr/lib/pkgconfig/memo.pc"
libslp-memo-devel_files += "/usr/include/*.h"

FILES_${PN} = "${libslp-memo_files}"
FILES_${PN}-devel = "${libslp-memo-devel_files}"

PKG_libslp-memo= "libslp-memo"
PKG_libslp-memo-devel= "libslp-memo-devel"

require libslp-memo-extraconf.inc
