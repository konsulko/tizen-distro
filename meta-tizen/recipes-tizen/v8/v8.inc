DESCRIPTION = "JavaScript Engine"
HOMEPAGE = "http://code.google.com/p/v8"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by v8 
PROVIDES += "v8"
RPROVIDES_v8 += "v8"

#PROVIDES by v8-devel 
PROVIDES += "v8-devel"
RPROVIDES_v8-devel += "v8-devel"
RPROVIDES_v8-devel += "v8-dev"

#PROVIDES by v8-private-headers-devel 
PROVIDES += "v8-private-headers-devel"
RPROVIDES_v8-private-headers-devel += "v8-private-headers-devel"
RPROVIDES_v8-private-headers-devel += "v8-private-headers-dev"

#PROVIDES by libv8 
PROVIDES += "libv8"
RPROVIDES_libv8 += "libv8"

RDEPENDS = ""
#RDEPENDS of v8-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libv8"

#RDEPENDS of v8-private-headers-devel (${PN}-private-headers-devel)
RDEPENDS_${PN}-private-headers-devel += "v8-dev"


DEPENDS = ""
#DEPENDS of v8 
DEPENDS += "lzma"
inherit pythonnative
DEPENDS += "gcc-cross"
DEPENDS += "readline"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/v8.manifest .
 
 
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
 
 
 env=CCFLAGS:"-fPIC"
 make x64.release -j3 library=shared snapshots=on soname_version=`echo 3.14.5 | cut -f1 -d'.'`
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/include/v8/x64
 mkdir -p ${D}/usr/lib
 install -p include/*.h ${D}/usr/include
 
 install -p src/*.h ${D}/usr/include/v8
 install -p src/x64/*.h ${D}/usr/include/v8/x64
 
 install -p out/x64.release/lib.target/libv8.so* ${D}/usr/lib
 mkdir -p ${D}/usr/bin
 install -p -m0755 out/x64.release/d8 ${D}/usr/bin
 
 pushd ${D}/usr/lib
 ln -sf libv8.so.`echo 3.14.5 | cut -f1 -d'.'` libv8.so
 
 chmod -x ${D}/usr/include/v8*.h
 popd
 
 
}

PACKAGES = ""
PACKAGES += "v8-devel"
PACKAGES += "v8-private-headers-devel"
PACKAGES += "libv8"

v8-devel_files = ""
v8-devel_files += "v8.manifest"
v8-devel_files += "/usr/include/*.h"
v8-devel_files += "/usr/lib/*.so"

v8-private-headers-devel_files = ""
v8-private-headers-devel_files += "v8.manifest"
v8-private-headers-devel_files += "/usr/include/v8/"

libv8_files = ""
libv8_files += "v8.manifest"
libv8_files += "/usr/bin/d8"
libv8_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${v8-devel_files}"
FILES_${PN}-private-headers-devel = "${v8-private-headers-devel_files}"
FILES_lib${PN} = "${libv8_files}"

PKG_v8-devel= "v8-devel"
PKG_v8-private-headers-devel= "v8-private-headers-devel"
PKG_libv8= "libv8"

require v8-extraconf.inc
