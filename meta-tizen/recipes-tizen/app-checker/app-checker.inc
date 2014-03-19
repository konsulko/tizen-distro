DESCRIPTION = "App Checker"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by app-checker-server-devel 
PROVIDES += "app-checker-server-devel"
RPROVIDES_app-checker-server-devel += "app-checker-server-devel"
RPROVIDES_app-checker-server-devel += "app-checker-server-dev"

#PROVIDES by app-checker-devel 
PROVIDES += "app-checker-devel"
RPROVIDES_app-checker-devel += "app-checker-devel"
RPROVIDES_app-checker-devel += "app-checker-dev"

#PROVIDES by app-checker 
PROVIDES += "app-checker"
RPROVIDES_app-checker += "app-checker"

#PROVIDES by app-checker-server 
PROVIDES += "app-checker-server"
RPROVIDES_app-checker-server += "app-checker-server"

RDEPENDS = ""
#RDEPENDS of app-checker-server-devel (${PN}-server-devel)
RDEPENDS_${PN}-server-devel += "app-checker-server"

#RDEPENDS of app-checker-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "app-checker"

#RDEPENDS of app-checker-server (${PN}-server)
RDEPENDS_${PN}-server += "app-checker"


DEPENDS = ""
#DEPENDS of app-checker 
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/app-checker.manifest .
 
 
 
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
 mkdir -p ${D}/usr/lib/ac-plugins
 
 
 
}

PACKAGES = ""
PACKAGES += "app-checker-server-devel"
PACKAGES += "app-checker-server"
PACKAGES += "app-checker"
PACKAGES += "app-checker-devel"

app-checker-server-devel_files = ""
app-checker-server-devel_files += "app-checker.manifest"
app-checker-server-devel_files += "/usr/lib/libapp-checker-server.so"
app-checker-server-devel_files += "/usr/lib/pkgconfig/app-checker-server.pc"
app-checker-server-devel_files += "/usr/include/app-checker/app-checker-server.h"

app-checker-server_files = ""
app-checker-server_files += "app-checker.manifest"
app-checker-server_files += "/usr/lib/libapp-checker-server.so.0"
app-checker-server_files += "/usr/lib/libapp-checker-server.so.0.1.0"

app-checker_files = ""
app-checker_files += "app-checker.manifest"
app-checker_files += "/usr/lib/libapp-checker.so.0"
app-checker_files += "/usr/lib/libapp-checker.so.0.1.0"
app-checker_files += "/usr/lib/ac-plugins"

app-checker-devel_files = ""
app-checker-devel_files += "app-checker.manifest"
app-checker-devel_files += "/usr/lib/libapp-checker.so"
app-checker-devel_files += "/usr/lib/pkgconfig/app-checker.pc"
app-checker-devel_files += "/usr/include/app-checker/app-checker.h"

FILES_${PN}-server-devel = "${app-checker-server-devel_files}"
FILES_${PN}-server = "${app-checker-server_files}"
FILES_${PN} = "${app-checker_files}"
FILES_${PN}-devel = "${app-checker-devel_files}"

PKG_app-checker-server-devel= "app-checker-server-devel"
PKG_app-checker-server= "app-checker-server"
PKG_app-checker= "app-checker"
PKG_app-checker-devel= "app-checker-devel"

require app-checker-extraconf.inc
