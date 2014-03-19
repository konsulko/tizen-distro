DESCRIPTION = "Library to control OAL APIs"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdevice-node 
PROVIDES += "libdevice-node"
RPROVIDES_libdevice-node += "libdevice-node"

#PROVIDES by libdevice-node-devel 
PROVIDES += "libdevice-node-devel"
RPROVIDES_libdevice-node-devel += "libdevice-node-devel"
RPROVIDES_libdevice-node-devel += "libdevice-node-dev"

RDEPENDS = ""
#RDEPENDS of libdevice-node-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libdevice-node"


DEPENDS = ""
#DEPENDS of libdevice-node 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libdevice-node.manifest .
 
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
PACKAGES += "libdevice-node"
PACKAGES += "libdevice-node-devel"

libdevice-node_files = ""
libdevice-node_files += "/usr/lib/*.so.*"
libdevice-node_files += "libdevice-node.manifest"

libdevice-node-devel_files = ""
libdevice-node-devel_files += "/usr/include/device-node/*.h"
libdevice-node-devel_files += "/usr/lib/*.so"
libdevice-node-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libdevice-node_files}"
FILES_${PN}-devel = "${libdevice-node-devel_files}"

PKG_libdevice-node= "libdevice-node"
PKG_libdevice-node-devel= "libdevice-node-devel"

require libdevice-node-extraconf.inc
