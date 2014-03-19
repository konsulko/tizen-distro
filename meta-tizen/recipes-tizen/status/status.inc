DESCRIPTION = "status library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TBD"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by status 
PROVIDES += "status"
RPROVIDES_status += "status"

#PROVIDES by status-devel 
PROVIDES += "status-devel"
RPROVIDES_status-devel += "status-devel"
RPROVIDES_status-devel += "status-dev"

RDEPENDS = ""
#RDEPENDS of status (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of status-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "status"


DEPENDS = ""
#DEPENDS of status 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/status.manifest .
 
 
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
 
 export LDFLAGS+="-Wl,--rpath=/usr/lib -Wl,--as-needed"
 
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
 
 mkdir -p ${D}/usr/share/license
 cp -f LICENSE ${D}/usr/share/license/status
 
 
 
}

PACKAGES = ""
PACKAGES += "status"
PACKAGES += "status-devel"

status_files = ""
status_files += "status.manifest"
status_files += "/usr/lib/*.so*"
status_files += "/usr/share/license/status"

status-devel_files = ""
status-devel_files += "status.manifest"
status-devel_files += "/usr/include/status/*.h"
status-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${status_files}"
FILES_${PN}-devel = "${status-devel_files}"

PKG_status= "status"
PKG_status-devel= "status-devel"

require status-extraconf.inc
