DESCRIPTION = "Linux-Native Asynchronous I/O Access Library"
HOMEPAGE = "http://kernel.org/pub/linux/libs/aio/"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libaio 
PROVIDES += "libaio"
RPROVIDES_libaio += "libaio"

#PROVIDES by libaio-devel 
PROVIDES += "libaio-devel"
RPROVIDES_libaio-devel += "libaio-devel"
RPROVIDES_libaio-devel += "libaio-dev"

RDEPENDS = ""
#RDEPENDS of libaio-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libaio"
RDEPENDS_${PN}-devel += "glibc-dev"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libaio.manifest .
 
 
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
 
 make -j16 CC="${HOST_SYS}-gcc" OPTFLAGS="$RPM_OPT_FLAGS"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install prefix=${D}/usr libdir=${D}/lib
 rm -f "${D}//usr/lib"/*.a
 # Strip dumb /usr/src/... off
 t=$(readlink -f "${D}/lib/libaio.so.1")
 ln -fs "${t##*/}" "${D}/lib/libaio.so.1"
 t=$(readlink -f "${D}//usr/lib/libaio.so")
 ln -fs "${t#${D}}" "${D}//usr/lib/libaio.so"
 
 
}

PACKAGES = ""
PACKAGES += "libaio"
PACKAGES += "libaio-devel"

libaio_files = ""
libaio_files += "libaio.manifest"

libaio-devel_files = ""
libaio-devel_files += "libaio.manifest"
libaio-devel_files += "/usr/include/libaio.h"
libaio-devel_files += "/usr/lib/libaio.so"

FILES_${PN} = "${libaio_files}"
FILES_${PN}-devel = "${libaio-devel_files}"

PKG_libaio= "libaio"
PKG_libaio-devel= "libaio-devel"

require libaio-extraconf.inc
