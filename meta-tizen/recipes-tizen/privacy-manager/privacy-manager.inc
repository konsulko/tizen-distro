DESCRIPTION = "Privacy Management"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by privacy-manager-client 


#PROVIDES by privacy-manager-server 


#PROVIDES by privacy-manager-server-dev 


#PROVIDES by capi-security-privacy-manager 


#PROVIDES by privacy-manager-client-dev 


#PROVIDES by capi-security-privacy-manager-dev 


RDEPENDS = ""
#RDEPENDS of privacy-manager-client (${PN}-client)
RDEPENDS_${PN}-client += "privacy-manager-server"

#RDEPENDS of privacy-manager-server (${PN}-server)
RDEPENDS_${PN}-server += "eglibc"

#RDEPENDS of privacy-manager-server-dev (${PN}-server-dev)
RDEPENDS_${PN}-server-dev += "privacy-manager-server"

#RDEPENDS of capi-security-privacy-manager (capi-security-${PN})
RDEPENDS_capi-security-${PN} += "privacy-manager-client"

#RDEPENDS of privacy-manager-client-dev (${PN}-client-dev)
RDEPENDS_${PN}-client-dev += "privacy-manager-client"

#RDEPENDS of capi-security-privacy-manager-dev (capi-security-${PN}-dev)
RDEPENDS_capi-security-${PN}-dev += "capi-security-privacy-manager"


DEPENDS = ""
#DEPENDS of privacy-manager-server 
DEPENDS += "pkgmgr-info"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "libxml2"
DEPENDS += "dbus"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "system-info"
DEPENDS += "common"
DEPENDS += "sqlite3"
DEPENDS += "libslp-db-util"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/privacy-manager-server.manifest .
 cp ${S}/packaging/privacy-manager-server-devel.manifest .
 cp ${S}/packaging/privacy-manager-client.manifest .
 cp ${S}/packaging/privacy-manager-client-devel.manifest .
 cp ${S}/packaging/capi-security-privacy-manager.manifest .
 cp ${S}/packaging/capi-security-privacy-manager-devel.manifest .
 
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON . -DPREFIX=${prefix} \
         -DEXEC_PREFIX=${prefix} \
         -DLIBDIR=${prefix}/lib \
         -DINCLUDEDIR=${prefix}/include \
         -DCMAKE_BUILD_TYPE="Release" \
         -DVERSION=0.0.4 \
         -DFILTER_LISTED_PKG=ON \
         -DPRIVACY_POPUP=OFF
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
 
 mkdir -p ${D}${prefix}/bin
 cp res/usr/bin/* ${D}${prefix}/bin/
 mkdir -p ${D}/opt/dbspace
 cp res/opt/dbspace/.privacylist.db /${D}/opt/dbspace/
 mkdir -p ${D}${prefix}/share/privacy-manager/
 cp res/usr/share/privacy-manager/privacy-filter-list.ini ${D}${prefix}/share/privacy-manager/
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}${prefix}/lib/systemd/system/multi-user.target.wants
 #install -m 0644 ${S}/packaging/privacy-manager-server.service ${D}${prefix}/lib/systemd/system/privacy-manager-server.service
 #ln -sf /usr/lib/systemd/system/privacy-manager-server.service ${D}${prefix}/lib/systemd/system/multi-user.target.wants/privacy-manager-server.service
 
 
 
}

PACKAGES += " privacy-manager-client "
PACKAGES += " privacy-manager-server "
PACKAGES += " privacy-manager-server-dev "
PACKAGES += " capi-security-privacy-manager "
PACKAGES += " privacy-manager-client-dev "
PACKAGES += " capi-security-privacy-manager-dev "

privacy-manager-client_files = ""
privacy-manager-client_files += "privacy-manager-client.manifest"
privacy-manager-client_files += "${prefix}/lib/libprivacy-manager-client.so*"
privacy-manager-client_files += "${prefix}/share/privacy-manager/privacy-filter-list.ini"
privacy-manager-client_files += "${sysconfdir}/package-manager/parserlib/libprivileges.so"

privacy-manager-server_files = ""
privacy-manager-server_files += "privacy-manager-server.manifest"
privacy-manager-server_files += "${prefix}/lib/libprivacy-manager-server.so*"
privacy-manager-server_files += "/opt/dbspace/.privacylist.db"
privacy-manager-server_files += "/usr/bin/*"

privacy-manager-server-dev_files = ""
privacy-manager-server-dev_files += "${prefix}/include/privacy_manager/server/privacy_manager_daemon.h"
privacy-manager-server-dev_files += "${prefix}/lib/pkgconfig/privacy-manager-server.pc"

capi-security-privacy-manager_files = ""
capi-security-privacy-manager_files += "${prefix}/lib/libcapi-security-privacy-manager.so.*"
capi-security-privacy-manager_files += "capi-security-privacy-manager.manifest"

privacy-manager-client-dev_files = ""
privacy-manager-client-dev_files += "privacy-manager-client-devel.manifest"
privacy-manager-client-dev_files += "${prefix}/include/*"
privacy-manager-client-dev_files += "${prefix}/lib/pkgconfig/privacy-manager-client.pc"

capi-security-privacy-manager-dev_files = ""
capi-security-privacy-manager-dev_files += "capi-security-privacy-manager-devel.manifest"
capi-security-privacy-manager-dev_files += "${prefix}/include/privacymgr/*.h"
capi-security-privacy-manager-dev_files += "${prefix}/lib/libcapi-security-privacy-manager.so"
capi-security-privacy-manager-dev_files += "${prefix}/lib/pkgconfig/capi-security-privacy-manager.pc"

FILES_privacy-manager-client = "${privacy-manager-client_files}"
FILES_${PN} = "${privacy-manager-server_files}"
FILES_${PN}-dev = "${privacy-manager-server-dev_files}"
FILES_capi-security-privacy-manager = "${capi-security-privacy-manager_files}"
FILES_privacy-manager-client-dev = "${privacy-manager-client-dev_files}"
FILES_capi-security-privacy-manager-dev = "${capi-security-privacy-manager-dev_files}"

PKG_privacy-manager-client= "privacy-manager-client"
PKG_privacy-manager-server= "privacy-manager-server"
PKG_privacy-manager-server-dev= "privacy-manager-server-dev"
PKG_capi-security-privacy-manager= "capi-security-privacy-manager"
PKG_privacy-manager-client-dev= "privacy-manager-client-dev"
PKG_capi-security-privacy-manager-dev= "capi-security-privacy-manager-dev"

require privacy-manager-extraconf.inc

