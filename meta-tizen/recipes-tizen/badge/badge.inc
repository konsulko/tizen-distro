DESCRIPTION = "badge library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libbadge 
PROVIDES += "libbadge"
RPROVIDES_libbadge += "libbadge"

#PROVIDES by badge-devel 
PROVIDES += "badge-devel"
RPROVIDES_badge-devel += "badge-devel"
RPROVIDES_badge-devel += "badge-dev"

#PROVIDES by badge 
PROVIDES += "badge"
RPROVIDES_badge += "badge"

RDEPENDS = ""
#RDEPENDS of libbadge (lib${PN})
RDEPENDS_lib${PN} += "badge"

#RDEPENDS of badge-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libbadge"

#RDEPENDS of badge (${PN})
RDEPENDS_${PN} += "libbadge"


DEPENDS = ""
#DEPENDS of badge 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(com-core)"
DEPENDS += "sqlite3"
DEPENDS += "pkgconfig(dlog)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/badge.manifest .
 
 
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
 mkdir -p ${D}/opt/dbspace
 sqlite3 ${D}/opt/dbspace/.badge.db < badge.sql
 
 
}

PACKAGES = ""
PACKAGES += "libbadge"
PACKAGES += "badge-devel"
PACKAGES += "badge"

libbadge_files = ""
libbadge_files += "badge.manifest"
libbadge_files += "badge.manifest"
libbadge_files += "/usr/lib/libbadge.so.*"

badge-devel_files = ""
badge-devel_files += "badge.manifest"
badge-devel_files += "/usr/include/badge/*.h"
badge-devel_files += "/usr/lib/libbadge.so"
badge-devel_files += "/usr/lib/pkgconfig/badge.pc"

badge_files = ""
badge_files += "badge.manifest"

FILES_lib${PN} = "${libbadge_files}"
FILES_${PN}-devel = "${badge-devel_files}"
FILES_${PN} = "${badge_files}"

PKG_libbadge= "libbadge"
PKG_badge-devel= "badge-devel"
PKG_badge= "badge"

require badge-extraconf.inc
