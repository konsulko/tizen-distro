DESCRIPTION = "A Library for Accessing Compressed Text Files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libzio-devel 
PROVIDES += "libzio-devel"
RPROVIDES_libzio-devel += "libzio-devel"
RPROVIDES_libzio-devel += "libzio-dev"

#PROVIDES by libzio 
PROVIDES += "libzio"
RPROVIDES_libzio += "libzio"

RDEPENDS = ""
#RDEPENDS of libzio-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libzio"


DEPENDS = ""
#DEPENDS of libzio 
DEPENDS += "xz"
DEPENDS += "zlib-devel"
DEPENDS += "bzip2"
DEPENDS += "xz-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libzio.manifest .
 
 
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
 
 make -j16 noweak
 
 exit 0
 make testt
 make tests
 for comp in gzip bzip2 lzma xz
 do
     $comp -c < fzopen.3.in > fzopen.test
     ./testt fzopen.test | cmp fzopen.3.in -
     cat fzopen.test | ./tests ${comp:0:1} | cmp fzopen.3.in -
 done
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D} install libdir=/usr/lib mandir=/usr/share/man
 
 
}

PACKAGES = ""
PACKAGES += "libzio-devel"
PACKAGES += "libzio"

libzio-devel_files = ""
libzio-devel_files += "libzio.manifest"
libzio-devel_files += "README COPYING"
libzio-devel_files += "/usr/lib/libzio.a"
libzio-devel_files += "/usr/lib/libzio.so"
libzio-devel_files += "/usr/share/man/man3/fzopen.3*"
libzio-devel_files += "/usr/include/zio.h"

libzio_files = ""
libzio_files += "libzio.manifest"
libzio_files += "/usr/lib/libzio.so.0"
libzio_files += "/usr/lib/libzio.so.0.99"

FILES_${PN}-devel = "${libzio-devel_files}"
FILES_${PN} = "${libzio_files}"

PKG_libzio-devel= "libzio-devel"
PKG_libzio= "libzio"

require libzio-extraconf.inc
