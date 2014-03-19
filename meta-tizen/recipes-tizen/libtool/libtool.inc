DESCRIPTION = "A Tool to Build Shared Libraries"
HOMEPAGE = "http://www.gnu.org/software/libtool/"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libltdl 
PROVIDES += "libltdl"
RPROVIDES_libltdl += "libltdl"

#PROVIDES by libtool 
PROVIDES += "libtool"
RPROVIDES_libtool += "libtool"
# the PROVIDES rules is ignore "libltdl-devel  "
PROVIDES += "libltdl-devel"
RPROVIDES_libtool += "libltdl-devel"
RPROVIDES_libtool += "libltdl-dev"
# the PROVIDES rules is ignore "libtool-ltdl-devel  "
PROVIDES += "libtool-ltdl-devel"
RPROVIDES_libtool += "libtool-ltdl-devel"
RPROVIDES_libtool += "libtool-ltdl-dev"

RDEPENDS = ""
#RDEPENDS of libtool (${PN})
RDEPENDS_${PN} += "libltdl"
RDEPENDS_${PN} += "tar"
RDEPENDS_${PN} += "automake"


DEPENDS = ""
#DEPENDS of libtool 
DEPENDS += "lzma"
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "makeinfo"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libtool-2.4.2
 cp ${S}/packaging/libtool.manifest .
 
 
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
 
 ./configure CFLAGS="$RPM_OPT_FLAGS" \
    --prefix=/usr --infodir=/usr/share/info --libdir=/usr/lib
 # force rebuild with non-broken makeinfo
 rm -f doc/libtool.info
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 
 
}

PACKAGES = ""
PACKAGES += "libltdl"
PACKAGES += "libtool"

libltdl_files = ""
libltdl_files += "libtool.manifest"
libltdl_files += "/usr/lib/libltdl.so.*"

libtool_files = ""
libtool_files += "libtool.manifest"
libtool_files += "/usr/bin/libtool"
libtool_files += "/usr/bin/libtoolize"
libtool_files += "/usr/include/libltdl"
libtool_files += "/usr/include/ltdl.h"
libtool_files += "/usr/lib/libltdl.a"
libtool_files += "/usr/lib/libltdl.so"
libtool_files += "/usr/share/aclocal/*.m4"
libtool_files += "/usr/share/info/libtool.info*"
libtool_files += "/usr/share/man/man1/libtool.1.gz"
libtool_files += "/usr/share/man/man1/libtoolize.1.gz"
libtool_files += "/usr/share/libtool"

FILES_libltdl = "${libltdl_files}"
FILES_${PN} = "${libtool_files}"

PKG_libltdl= "libltdl"
PKG_libtool= "libtool"

require libtool-extraconf.inc
