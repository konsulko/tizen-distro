DESCRIPTION = "Minicontrol Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Core Applications"
LICENSE = "Flora"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by minicontrol 
PROVIDES += "minicontrol"
RPROVIDES_minicontrol += "minicontrol"

#PROVIDES by minicontrol-devel 
PROVIDES += "minicontrol-devel"
RPROVIDES_minicontrol-devel += "minicontrol-devel"
RPROVIDES_minicontrol-devel += "minicontrol-dev"

RDEPENDS = ""
#RDEPENDS of minicontrol-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "minicontrol"


DEPENDS = ""
#DEPENDS of minicontrol 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(ecore-evas)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/minicontrol.manifest .
 
 
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
 
 CFLAGS="$CFLAGS -fPIC"
 
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
PACKAGES += "minicontrol"
PACKAGES += "minicontrol-devel"

minicontrol_files = ""
minicontrol_files += "minicontrol.manifest"
minicontrol_files += "/usr/lib/libminicontrol-provider.so*"
minicontrol_files += "/usr/lib/libminicontrol-viewer.so*"
minicontrol_files += "/usr/lib/libminicontrol-monitor.so*"

minicontrol-devel_files = ""
minicontrol-devel_files += "minicontrol.manifest"
minicontrol-devel_files += "/usr/include/minicontrol/*.h"
minicontrol-devel_files += "/usr/lib/pkgconfig/minicontrol-provider.pc"
minicontrol-devel_files += "/usr/lib/pkgconfig/minicontrol-monitor.pc"
minicontrol-devel_files += "/usr/lib/pkgconfig/minicontrol-viewer.pc"

FILES_${PN} = "${minicontrol_files}"
FILES_${PN}-devel = "${minicontrol-devel_files}"

PKG_minicontrol= "minicontrol"
PKG_minicontrol-devel= "minicontrol-devel"

require minicontrol-extraconf.inc
