DESCRIPTION = "Application Service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by app-svc 
PROVIDES += "app-svc"
RPROVIDES_app-svc += "app-svc"

#PROVIDES by app-svc-devel 
PROVIDES += "app-svc-devel"
RPROVIDES_app-svc-devel += "app-svc-devel"
RPROVIDES_app-svc-devel += "app-svc-dev"

RDEPENDS = ""
#RDEPENDS of app-svc (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of app-svc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "app-svc"


DEPENDS = ""
#DEPENDS of app-svc 
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(ecore)"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(xdgmime)"
DEPENDS += "pkgconfig(libprivilege-control)"
DEPENDS += "ail"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "sqlite3"
DEPENDS += "pkgconfig(bundle)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/app-svc.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . \
 -Dwith_wayland=TRUE
 
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
 
 # Create database
 mkdir -p ${D}/opt/dbspace
 sqlite3 ${D}/opt/dbspace/.appsvc.db < data/appsvc_db.sql
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/app-svc
 
 
}

PACKAGES = ""
PACKAGES += "app-svc"
PACKAGES += "app-svc-devel"

app-svc_files = ""
app-svc_files += "app-svc.manifest"
app-svc_files += "%verify(not md5 mtime size) %attr(664,root,app) /opt/dbspace/.appsvc.db"
app-svc_files += "%verify(not md5 mtime size) %attr(664,root,app) /opt/dbspace/.appsvc.db-journal"
app-svc_files += "/usr/bin/appsvc_test"
app-svc_files += "/usr/lib/libappsvc.so.0"
app-svc_files += "/usr/lib/libappsvc.so.0.1.0"
app-svc_files += "/usr/share/license/app-svc"

app-svc-devel_files = ""
app-svc-devel_files += "app-svc.manifest"
app-svc-devel_files += "/usr/lib/pkgconfig/appsvc.pc"
app-svc-devel_files += "/usr/lib/libappsvc.so"
app-svc-devel_files += "/usr/include/appsvc/appsvc.h"

FILES_${PN} = "${app-svc_files}"
FILES_${PN}-devel = "${app-svc-devel_files}"

PKG_app-svc= "app-svc"
PKG_app-svc-devel= "app-svc-devel"

require app-svc-extraconf.inc
