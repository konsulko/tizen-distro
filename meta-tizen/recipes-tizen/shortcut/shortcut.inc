DESCRIPTION = "Shortcut add feature supporting library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Framework"
LICENSE = "Apache License"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libshortcut-devel 
PROVIDES += "libshortcut-devel"
RPROVIDES_libshortcut-devel += "libshortcut-devel"
RPROVIDES_libshortcut-devel += "libshortcut-dev"

#PROVIDES by libshortcut 
PROVIDES += "libshortcut"
RPROVIDES_libshortcut += "libshortcut"

RDEPENDS = ""
#RDEPENDS of libshortcut-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libshortcut"

#RDEPENDS of libshortcut (lib${PN})
RDEPENDS_lib${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of libshortcut 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(com-core)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sqlite3)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libslp-db-util"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libshortcut.manifest .
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/opt/dbspace
 touch ${D}/opt/dbspace/.shortcut_service.db
 touch ${D}/opt/dbspace/.shortcut_service.db-journal
 
 
}

PACKAGES = ""
PACKAGES += "libshortcut-devel"
PACKAGES += "libshortcut"

libshortcut-devel_files = ""
libshortcut-devel_files += "libshortcut.manifest"
libshortcut-devel_files += "/usr/include/shortcut/shortcut_PG.h"
libshortcut-devel_files += "/usr/include/shortcut/shortcut.h"
libshortcut-devel_files += "/usr/lib/pkgconfig/shortcut.pc"

libshortcut_files = ""
libshortcut_files += "libshortcut.manifest"
libshortcut_files += "/usr/lib/*.so*"
libshortcut_files += "/usr/etc/package-manager/parserlib/*"
libshortcut_files += "/usr/share/license/*"

FILES_${PN}-devel = "${libshortcut-devel_files}"
FILES_${PN} = "${libshortcut_files}"

PKG_libshortcut-devel= "libshortcut-devel"
PKG_libshortcut= "libshortcut"

require shortcut-extraconf.inc
