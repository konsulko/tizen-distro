DESCRIPTION = "library for PIMs IPC"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pims-ipc 
PROVIDES += "pims-ipc"
RPROVIDES_pims-ipc += "pims-ipc"

#PROVIDES by pims-ipc-devel 
PROVIDES += "pims-ipc-devel"
RPROVIDES_pims-ipc-devel += "pims-ipc-devel"
RPROVIDES_pims-ipc-devel += "pims-ipc-dev"

RDEPENDS = ""
#RDEPENDS of pims-ipc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pims-ipc"


DEPENDS = ""
#DEPENDS of pims-ipc 
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(libzmq)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pims-ipc.manifest .
 
 
 
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
PACKAGES += "pims-ipc"
PACKAGES += "pims-ipc-devel"

pims-ipc_files = ""
pims-ipc_files += "pims-ipc.manifest"
pims-ipc_files += "/usr/lib/libpims-ipc.so.*"

pims-ipc-devel_files = ""
pims-ipc-devel_files += "pims-ipc.manifest"
pims-ipc-devel_files += "/usr/include/pims-ipc/*.h"
pims-ipc-devel_files += "/usr/lib/*.so"
pims-ipc-devel_files += "/usr/lib/pims_ipc_test"
pims-ipc-devel_files += "/usr/lib/pkgconfig/pims-ipc.pc"

FILES_${PN} = "${pims-ipc_files}"
FILES_${PN}-devel = "${pims-ipc-devel_files}"

PKG_pims-ipc= "pims-ipc"
PKG_pims-ipc-devel= "pims-ipc-devel"

require pims-ipc-extraconf.inc
