DESCRIPTION = "Location DB controler"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "TBD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by liblocation-appman 
PROVIDES += "liblocation-appman"
RPROVIDES_liblocation-appman += "liblocation-appman"

#PROVIDES by liblocation-appman-devel 
PROVIDES += "liblocation-appman-devel"
RPROVIDES_liblocation-appman-devel += "liblocation-appman-devel"
RPROVIDES_liblocation-appman-devel += "liblocation-appman-dev"

RDEPENDS = ""
#RDEPENDS of liblocation-appman (${PN})
RDEPENDS_${PN} += "sqlite"

#RDEPENDS of liblocation-appman-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "liblocation-appman"


DEPENDS = ""
#DEPENDS of liblocation-appman 
DEPENDS += "pkgconfig(capi-appfw-app-manager)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libgcrypt"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n liblocation-appman-0.1.6
 cp ${S}/packaging/liblocation-appman.manifest .
 
 
 
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
 
 # Call make instruction with smp support
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
 
 
 
}

PACKAGES = ""
PACKAGES += "liblocation-appman"
PACKAGES += "liblocation-appman-devel"

liblocation-appman_files = ""
liblocation-appman_files += "liblocation-appman.manifest"
liblocation-appman_files += "/usr/lib/liblocation-appman.so*"
liblocation-appman_files += "/opt/dbspace/.location-appman.db*"

liblocation-appman-devel_files = ""
liblocation-appman-devel_files += "liblocation-appman.manifest"
liblocation-appman-devel_files += "/usr/include/location-appman/*.h"
liblocation-appman-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${liblocation-appman_files}"
FILES_${PN}-devel = "${liblocation-appman-devel_files}"

PKG_liblocation-appman= "liblocation-appman"
PKG_liblocation-appman-devel= "liblocation-appman-devel"

require liblocation-appman-extraconf.inc
