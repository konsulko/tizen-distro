DESCRIPTION = "Library for the light-weight IPC"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/IPC"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcom-core 
PROVIDES += "libcom-core"
RPROVIDES_libcom-core += "libcom-core"

#PROVIDES by libcom-core-devel 
PROVIDES += "libcom-core-devel"
RPROVIDES_libcom-core-devel += "libcom-core-devel"
RPROVIDES_libcom-core-devel += "libcom-core-dev"

RDEPENDS = ""
#RDEPENDS of libcom-core-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libcom-core"


DEPENDS = ""
#DEPENDS of libcom-core 
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(dlog)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libcom-core.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}//usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "libcom-core"
PACKAGES += "libcom-core-devel"

libcom-core_files = ""
libcom-core_files += "libcom-core.manifest"
libcom-core_files += "/usr/lib/*.so*"
libcom-core_files += "/usr/share/license/*"

libcom-core-devel_files = ""
libcom-core-devel_files += "libcom-core.manifest"
libcom-core-devel_files += "/usr/include/com-core/com-core.h"
libcom-core-devel_files += "/usr/include/com-core/packet.h"
libcom-core-devel_files += "/usr/include/com-core/com-core_packet.h"
libcom-core-devel_files += "/usr/include/com-core/com-core_thread.h"
libcom-core-devel_files += "/usr/include/com-core/secure_socket.h"
libcom-core-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libcom-core_files}"
FILES_${PN}-devel = "${libcom-core-devel_files}"

PKG_libcom-core= "libcom-core"
PKG_libcom-core-devel= "libcom-core-devel"

require com-core-extraconf.inc
