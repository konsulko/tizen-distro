DESCRIPTION = "Privacy Management"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by privacy-manager-client 
PROVIDES += "privacy-manager-client"
RPROVIDES_privacy-manager-client += "privacy-manager-client"

#PROVIDES by privacy-manager-server 
PROVIDES += "privacy-manager-server"
RPROVIDES_privacy-manager-server += "privacy-manager-server"

#PROVIDES by privacy-manager-server-devel 
PROVIDES += "privacy-manager-server-devel"
RPROVIDES_privacy-manager-server-devel += "privacy-manager-server-devel"
RPROVIDES_privacy-manager-server-devel += "privacy-manager-server-dev"

#PROVIDES by capi-security-privacy-manager 
PROVIDES += "capi-security-privacy-manager"
RPROVIDES_capi-security-privacy-manager += "capi-security-privacy-manager"

#PROVIDES by privacy-manager-client-devel 
PROVIDES += "privacy-manager-client-devel"
RPROVIDES_privacy-manager-client-devel += "privacy-manager-client-devel"
RPROVIDES_privacy-manager-client-devel += "privacy-manager-client-dev"

#PROVIDES by capi-security-privacy-manager-devel 
PROVIDES += "capi-security-privacy-manager-devel"
RPROVIDES_capi-security-privacy-manager-devel += "capi-security-privacy-manager-devel"
RPROVIDES_capi-security-privacy-manager-devel += "capi-security-privacy-manager-dev"

RDEPENDS = ""
#RDEPENDS of privacy-manager-client (${PN}-client)
RDEPENDS_${PN}-client += "privacy-manager-server"

#RDEPENDS of privacy-manager-server (${PN}-server)
RDEPENDS_${PN}-server += "/sbin/ldconfig"

#RDEPENDS of privacy-manager-server-devel (${PN}-server-devel)
RDEPENDS_${PN}-server-devel += "privacy-manager-server"

#RDEPENDS of capi-security-privacy-manager (capi-security-${PN})
RDEPENDS_capi-security-${PN} += "privacy-manager-client"

#RDEPENDS of privacy-manager-client-devel (${PN}-client-devel)
RDEPENDS_${PN}-client-devel += "privacy-manager-client"

#RDEPENDS of capi-security-privacy-manager-devel (capi-security-${PN}-devel)
RDEPENDS_capi-security-${PN}-devel += "capi-security-privacy-manager"


DEPENDS = ""
#DEPENDS of privacy-manager-server 
DEPENDS += "pkgmgr-info"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(capi-system-info)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "libslp-db-util"
DEPENDS += "common"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/privacy-manager-server.manifest .
 cp ${S}/packaging/privacy-manager-server-devel.manifest .
 cp ${S}/packaging/privacy-manager-client.manifest .
 cp ${S}/packaging/privacy-manager-client-devel.manifest .
 cp ${S}/packaging/capi-security-privacy-manager.manifest .
 cp ${S}/packaging/capi-security-privacy-manager-devel.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DPREFIX=/usr \
         -DEXEC_PREFIX=/usr \
         -DLIBDIR=/usr/lib \
         -DINCLUDEDIR=/usr/include \
         -DCMAKE_BUILD_TYPE="Release" \
         -DVERSION=0.0.4 \
         -DFILTER_LISTED_PKG=ON \
         -DPRIVACY_POPUP=OFF
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 cp res/usr/bin/* ${D}/usr/bin/
 mkdir -p ${D}/opt/dbspace
 cp res/opt/dbspace/.privacylist.db /${D}/opt/dbspace/
 mkdir -p ${D}/usr/share/privacy-manager/
 cp res/usr/share/privacy-manager/privacy-filter-list.ini ${D}/usr/share/privacy-manager/
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 #install -m 0644 ${S}/packaging/privacy-manager-server.service ${D}/usr/lib/systemd/system/privacy-manager-server.service
 #ln -sf /usr/lib/systemd/system/privacy-manager-server.service ${D}/usr/lib/systemd/system/multi-user.target.wants/privacy-manager-server.service
 
 
 
}

PACKAGES = ""
PACKAGES += "privacy-manager-client"
PACKAGES += "privacy-manager-server"
PACKAGES += "privacy-manager-server-devel"
PACKAGES += "capi-security-privacy-manager"
PACKAGES += "privacy-manager-client-devel"
PACKAGES += "capi-security-privacy-manager-devel"

privacy-manager-client_files = ""
privacy-manager-client_files += "privacy-manager-client.manifest"
privacy-manager-client_files += "/usr/lib/libprivacy-manager-client.so*"
privacy-manager-client_files += "/usr/share/privacy-manager/privacy-filter-list.ini"
privacy-manager-client_files += "/etc/package-manager/parserlib/libprivileges.so"

privacy-manager-server_files = ""
privacy-manager-server_files += "privacy-manager-server.manifest"
privacy-manager-server_files += "/usr/lib/libprivacy-manager-server.so*"
privacy-manager-server_files += "/opt/dbspace/.privacylist.db"
privacy-manager-server_files += "/usr/bin/*"

privacy-manager-server-devel_files = ""
privacy-manager-server-devel_files += "/usr/include/privacy_manager/server/privacy_manager_daemon.h"
privacy-manager-server-devel_files += "/usr/lib/pkgconfig/privacy-manager-server.pc"

capi-security-privacy-manager_files = ""
capi-security-privacy-manager_files += "/usr/lib/libcapi-security-privacy-manager.so.*"
capi-security-privacy-manager_files += "capi-security-privacy-manager.manifest"

privacy-manager-client-devel_files = ""
privacy-manager-client-devel_files += "privacy-manager-client-devel.manifest"
privacy-manager-client-devel_files += "/usr/include/*"
privacy-manager-client-devel_files += "/usr/lib/pkgconfig/privacy-manager-client.pc"

capi-security-privacy-manager-devel_files = ""
capi-security-privacy-manager-devel_files += "capi-security-privacy-manager-devel.manifest"
capi-security-privacy-manager-devel_files += "/usr/include/privacymgr/*.h"
capi-security-privacy-manager-devel_files += "/usr/lib/libcapi-security-privacy-manager.so"
capi-security-privacy-manager-devel_files += "/usr/lib/pkgconfig/capi-security-privacy-manager.pc"

FILES_privacy-manager-client = "${privacy-manager-client_files}"
FILES_${PN} = "${privacy-manager-server_files}"
FILES_${PN}-devel = "${privacy-manager-server-devel_files}"
FILES_capi-security-privacy-manager = "${capi-security-privacy-manager_files}"
FILES_privacy-manager-client-devel = "${privacy-manager-client-devel_files}"
FILES_capi-security-privacy-manager-devel = "${capi-security-privacy-manager-devel_files}"

PKG_privacy-manager-client= "privacy-manager-client"
PKG_privacy-manager-server= "privacy-manager-server"
PKG_privacy-manager-server-devel= "privacy-manager-server-devel"
PKG_capi-security-privacy-manager= "capi-security-privacy-manager"
PKG_privacy-manager-client-devel= "privacy-manager-client-devel"
PKG_capi-security-privacy-manager-devel= "capi-security-privacy-manager-devel"

require privacy-manager-extraconf.inc
