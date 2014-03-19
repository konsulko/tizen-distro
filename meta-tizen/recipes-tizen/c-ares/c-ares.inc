DESCRIPTION = "Library for asynchronous name resolves"
HOMEPAGE = "http://daniel.haxx.se/projects/c-ares"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcares-devel 
PROVIDES += "libcares-devel"
RPROVIDES_libcares-devel += "libcares-devel"
RPROVIDES_libcares-devel += "libcares-dev"

#PROVIDES by c-ares 
PROVIDES += "c-ares"
RPROVIDES_c-ares += "c-ares"

#PROVIDES by libcares 
PROVIDES += "libcares"
RPROVIDES_libcares += "libcares"

RDEPENDS = ""
#RDEPENDS of libcares-devel (libcares-devel)
RDEPENDS_libcares-devel += "glibc-dev"
RDEPENDS_libcares-devel += "libcares"


DEPENDS = ""
#DEPENDS of c-ares 
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n c-ares-1.7.5
 cp ${S}/packaging/c-ares.manifest .
 
 
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
         --infodir=/usr/share/info --enable-symbol-hiding --enable-nonblocking --enable-shared --disable-static --with-pic
 sed -i -e 's@-g0@-g@g' Makefile
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
PACKAGES += "libcares-devel"
PACKAGES += "libcares"

libcares-devel_files = ""
libcares-devel_files += "c-ares.manifest"
libcares-devel_files += "/usr/lib/libcares.so"
libcares-devel_files += "/usr/include/*.h"
libcares-devel_files += "/usr/share/man/man3/ares_*"
libcares-devel_files += "/usr/lib/pkgconfig/libcares.pc"

libcares_files = ""
libcares_files += "c-ares.manifest"
libcares_files += "/usr/lib/libcares.so.2*"

FILES_libcares-devel = "${libcares-devel_files}"
FILES_libcares = "${libcares_files}"

PKG_libcares-devel= "libcares-devel"
PKG_libcares= "libcares"

require c-ares-extraconf.inc
