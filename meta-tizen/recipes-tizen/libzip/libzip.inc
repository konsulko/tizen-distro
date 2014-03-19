DESCRIPTION = "C library for reading, creating, and modifying zip archives"
HOMEPAGE = "http://www.nih.at/libzip"
SECTION = "Development/Libraries/C and C++"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libzip-util 
PROVIDES += "libzip-util"
RPROVIDES_libzip-util += "libzip-util"

#PROVIDES by libzip 
PROVIDES += "libzip"
RPROVIDES_libzip += "libzip"

#PROVIDES by libzip-devel 
PROVIDES += "libzip-devel"
RPROVIDES_libzip-devel += "libzip-devel"
RPROVIDES_libzip-devel += "libzip-dev"

RDEPENDS = ""
#RDEPENDS of libzip-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libzip"


DEPENDS = ""
#DEPENDS of libzip 
DEPENDS += "zlib-devel"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libzip.manifest .
 
 
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
 
 autoreconf -fiv
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --disable-static --with-pic
 make -j16
 
 exit 0
 make -j16 check VERBOSE=1
 
 
 
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
 cp lib/zipconf.h ${D}//usr/include/zipconf.h
 
 
}

PACKAGES = ""
PACKAGES += "libzip"
PACKAGES += "libzip-util"
PACKAGES += "libzip-devel"

libzip_files = ""
libzip_files += "libzip.manifest"
libzip_files += "/usr/lib/libzip.so.*"

libzip-util_files = ""
libzip-util_files += "libzip.manifest"
libzip-util_files += "/usr/bin/ziptorrent"
libzip-util_files += "/usr/bin/zipcmp"
libzip-util_files += "/usr/bin/zipmerge"
libzip-util_files += "/usr/share/man/man1/*.1*"

libzip-devel_files = ""
libzip-devel_files += "libzip.manifest"
libzip-devel_files += "/usr/lib/libzip.so"
libzip-devel_files += "/usr/include/zip.h"
libzip-devel_files += "/usr/include/zipconf.h"
libzip-devel_files += "/usr/lib/libzip/"
libzip-devel_files += "/usr/lib/pkgconfig/libzip.pc"
libzip-devel_files += "/usr/share/man/man3/*.3*"

FILES_${PN} = "${libzip_files}"
FILES_${PN}-util = "${libzip-util_files}"
FILES_${PN}-devel = "${libzip-devel_files}"

PKG_libzip= "libzip"
PKG_libzip-util= "libzip-util"
PKG_libzip-devel= "libzip-devel"

require libzip-extraconf.inc
