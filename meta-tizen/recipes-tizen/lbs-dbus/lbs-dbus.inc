DESCRIPTION = "Dbus interface for Location based service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Location/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lbs-dbus 
PROVIDES += "lbs-dbus"
RPROVIDES_lbs-dbus += "lbs-dbus"

#PROVIDES by liblbs-dbus-devel 
PROVIDES += "liblbs-dbus-devel"
RPROVIDES_liblbs-dbus-devel += "liblbs-dbus-devel"
RPROVIDES_liblbs-dbus-devel += "liblbs-dbus-dev"

#PROVIDES by liblbs-dbus 
PROVIDES += "liblbs-dbus"
RPROVIDES_liblbs-dbus += "liblbs-dbus"

RDEPENDS = ""
#RDEPENDS of liblbs-dbus-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "liblbs-dbus"


DEPENDS = ""
#DEPENDS of lbs-dbus 
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "cmake"
inherit pythonnative
DEPENDS += "dlog"
DEPENDS += "python-xml"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(gio-unix-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/lbs-dbus.manifest .
 
 
 
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
PACKAGES += "liblbs-dbus-devel"
PACKAGES += "liblbs-dbus"

liblbs-dbus-devel_files = ""
liblbs-dbus-devel_files += "lbs-dbus.manifest"
liblbs-dbus-devel_files += "/usr/include/lbs-dbus/*.h"
liblbs-dbus-devel_files += "/usr/lib/pkgconfig/*.pc"
liblbs-dbus-devel_files += "/usr/lib/*.so"

liblbs-dbus_files = ""
liblbs-dbus_files += "lbs-dbus.manifest"
liblbs-dbus_files += "/usr/lib/*.so.*"
liblbs-dbus_files += "/etc/dbus-1/system.d/*"

FILES_lib${PN}-devel = "${liblbs-dbus-devel_files}"
FILES_lib${PN} = "${liblbs-dbus_files}"

PKG_liblbs-dbus-devel= "liblbs-dbus-devel"
PKG_liblbs-dbus= "liblbs-dbus"

require lbs-dbus-extraconf.inc
