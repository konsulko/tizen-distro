DESCRIPTION = "The GNU MP Library"
HOMEPAGE = "http://gmplib.org/"
SECTION = "System/Libraries"
LICENSE = "GPL-3.0+  LGPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgmp 
PROVIDES += "libgmp"
RPROVIDES_libgmp += "libgmp"

#PROVIDES by gmp 
PROVIDES += "gmp"
RPROVIDES_gmp += "gmp"

#PROVIDES by gmp-devel 
PROVIDES += "gmp-devel"
RPROVIDES_gmp-devel += "gmp-devel"
RPROVIDES_gmp-devel += "gmp-dev"

#PROVIDES by libgmpxx 
PROVIDES += "libgmpxx"
RPROVIDES_libgmpxx += "libgmpxx"

RDEPENDS = ""
#RDEPENDS of gmp-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libgmp"
RDEPENDS_${PN}-devel += "libgmpxx"

#RDEPENDS of libgmpxx (lib${PN}xx)
RDEPENDS_lib${PN}xx += "libgmp"


DEPENDS = ""
#DEPENDS of gmp 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gmp.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fexceptions";
 
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
         --infodir=/usr/share/info \
          --enable-mpbsd --enable-cxx
 make -j16
 
 exit 0
 # do not disable "make check", FIX THE BUGS!
 make check
 
 
 
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
   
 
 
}

PACKAGES = ""
PACKAGES += "libgmp"
PACKAGES += "gmp"
PACKAGES += "gmp-devel"
PACKAGES += "libgmpxx"

libgmp_files = ""
libgmp_files += "gmp.manifest"
libgmp_files += "/usr/lib/libgmp.so.10*"

gmp_files = ""
gmp_files += "gmp.manifest"
gmp_files += "GPL-3.0+ ; LGPL-3.0+ COPYING"
gmp_files += "AUTHORS README NEWS"

gmp-devel_files = ""
gmp-devel_files += "gmp.manifest"
gmp-devel_files += "AUTHORS README NEWS"
gmp-devel_files += "/usr/share/info/gmp.info*.gz"
gmp-devel_files += "/usr/lib/libgmp.a"
gmp-devel_files += "/usr/lib/libgmpxx.a"
gmp-devel_files += "/usr/lib/libgmp.so"
gmp-devel_files += "/usr/lib/libgmpxx.so"
gmp-devel_files += "/usr/lib/pkgconfig/gmp.pc"
gmp-devel_files += "/usr/include/gmp.h"
gmp-devel_files += "/usr/include/gmpxx.h"

libgmpxx_files = ""
libgmpxx_files += "gmp.manifest"
libgmpxx_files += "/usr/lib/libgmpxx.so.4*"

FILES_lib${PN} = "${libgmp_files}"
FILES_${PN} = "${gmp_files}"
FILES_${PN}-devel = "${gmp-devel_files}"
FILES_lib${PN}xx = "${libgmpxx_files}"

PKG_libgmp= "libgmp"
PKG_gmp= "gmp"
PKG_gmp-devel= "gmp-devel"
PKG_libgmpxx= "libgmpxx"

require gmp-extraconf.inc
