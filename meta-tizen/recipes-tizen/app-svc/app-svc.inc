DESCRIPTION = "Application Service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by app-svc 


#PROVIDES by app-svc-dev 


RDEPENDS = ""
#RDEPENDS of app-svc (${PN})
RDEPENDS_${PN} += "eglibc"

#RDEPENDS of app-svc-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "app-svc"


DEPENDS = ""
#DEPENDS of app-svc 
DEPENDS += "pkgmgr-info"
DEPENDS += "aul-1"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "iniparser"
DEPENDS += "dbus"
DEPENDS += "bundle"
DEPENDS += "xdgmime"
DEPENDS += "ail"
DEPENDS += "dlog"
DEPENDS += "libsoup-2.4"
DEPENDS += "sqlite3"
DEPENDS += "ecore"
DEPENDS += "libprivilege-control"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/app-svc.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON . \
 -Dwith_wayland=TRUE
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # Create database
 mkdir -p ${D}/opt/dbspace
 sqlite3 ${D}/opt/dbspace/.appsvc.db < data/appsvc_db.sql
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/app-svc
 
 
}


app-svc_files = ""
app-svc_files += "app-svc.manifest"
app-svc_files += "%verify(not md5 mtime size) %attr(664,root,app) /opt/dbspace/.appsvc.db"
app-svc_files += "%verify(not md5 mtime size) %attr(664,root,app) /opt/dbspace/.appsvc.db-journal"
app-svc_files += "/usr/bin/appsvc_test"
app-svc_files += "${prefix}/lib/libappsvc.so.0"
app-svc_files += "${prefix}/lib/libappsvc.so.0.1.0"
app-svc_files += "/usr/share/license/app-svc"

app-svc-dev_files = ""
app-svc-dev_files += "app-svc.manifest"
app-svc-dev_files += "${prefix}/lib/pkgconfig/appsvc.pc"
app-svc-dev_files += "${prefix}/lib/libappsvc.so"
app-svc-dev_files += "${prefix}/include/appsvc/appsvc.h"

FILES_${PN} = "${app-svc_files}"
FILES_${PN}-dev = "${app-svc-dev_files}"

PKG_app-svc= "app-svc"
PKG_app-svc-dev= "app-svc-dev"

require app-svc-extraconf.inc

