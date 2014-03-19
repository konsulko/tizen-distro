DESCRIPTION = "Packager Manager client library package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Package Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pkgmgr-client 
PROVIDES += "pkgmgr-client"
RPROVIDES_pkgmgr-client += "pkgmgr-client"

#PROVIDES by pkgmgr 
PROVIDES += "pkgmgr"
RPROVIDES_pkgmgr += "pkgmgr"

#PROVIDES by pkgmgr-server 
PROVIDES += "pkgmgr-server"
RPROVIDES_pkgmgr-server += "pkgmgr-server"

#PROVIDES by pkgmgr-types-devel 
PROVIDES += "pkgmgr-types-devel"
RPROVIDES_pkgmgr-types-devel += "pkgmgr-types-devel"
RPROVIDES_pkgmgr-types-devel += "pkgmgr-types-dev"

#PROVIDES by pkgmgr-client-devel 
PROVIDES += "pkgmgr-client-devel"
RPROVIDES_pkgmgr-client-devel += "pkgmgr-client-devel"
RPROVIDES_pkgmgr-client-devel += "pkgmgr-client-dev"

#PROVIDES by pkgmgr-installer-devel 
PROVIDES += "pkgmgr-installer-devel"
RPROVIDES_pkgmgr-installer-devel += "pkgmgr-installer-devel"
RPROVIDES_pkgmgr-installer-devel += "pkgmgr-installer-dev"

#PROVIDES by pkgmgr-installer 
PROVIDES += "pkgmgr-installer"
RPROVIDES_pkgmgr-installer += "pkgmgr-installer"

RDEPENDS = ""
#RDEPENDS of pkgmgr-client (pkgmgr-client)
RDEPENDS_pkgmgr-client += "shared-mime-info"
RDEPENDS_pkgmgr-client += "pkgmgr"

#RDEPENDS of pkgmgr-server (pkgmgr-server)
RDEPENDS_pkgmgr-server += "pkgmgr"

#RDEPENDS of pkgmgr-types-devel (pkgmgr-types-devel)
RDEPENDS_pkgmgr-types-devel += "pkgmgr"

#RDEPENDS of pkgmgr-client-devel (pkgmgr-client-devel)
RDEPENDS_pkgmgr-client-devel += "pkgmgr"

#RDEPENDS of pkgmgr-installer-devel (pkgmgr-installer-devel)
RDEPENDS_pkgmgr-installer-devel += "pkgmgr"

#RDEPENDS of pkgmgr-installer (pkgmgr-installer)
RDEPENDS_pkgmgr-installer += "pkgmgr"


DEPENDS = ""
#DEPENDS of pkgmgr 
DEPENDS += "bundle"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "unzip"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(dbus-1)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "app-core"
DEPENDS += "pkgmgr-info"
DEPENDS += "ail"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "dlog"
DEPENDS += "ecore"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pkgmgr.manifest ${S}/packaging/pkgmgr-client.manifest ${S}/packaging/pkgmgr-client-devel.manifest ${S}/packaging/pkgmgr-server.manifest ${S}/packaging/pkgmgr-installer.manifest ${S}/packaging/pkgmgr-installer-devel.manifest ${S}/packaging/pkgmgr-types-devel.manifest .
 
 
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
     -DX11_SUPPORT=Off
 
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
 rm -f  ${D}/usr/bin/pkgmgr_backend_sample
 rm -f ${D}/usr/lib/libpkgmgr_backend_lib_sample.so
 rm -f ${D}/usr/lib/libpkgmgr_parser_lib_sample.so
 
 mkdir -p ${D}/etc/package-manager/backend
 mkdir -p ${D}/etc/package-manager/backendlib
 mkdir -p ${D}/etc/opt/upgrade
 
 mkdir -p ${D}/etc/package-manager/server
 
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} package-manager
 
}

PACKAGES = ""
PACKAGES += "pkgmgr-client"
PACKAGES += "pkgmgr"
PACKAGES += "pkgmgr-server"
PACKAGES += "pkgmgr-types-devel"
PACKAGES += "pkgmgr-client-devel"
PACKAGES += "pkgmgr-installer-devel"
PACKAGES += "pkgmgr-installer"

pkgmgr-client_files = ""
pkgmgr-client_files += "pkgmgr-client.manifest"
pkgmgr-client_files += "/etc/package-manager"
pkgmgr-client_files += "/etc/package-manager/pkg_path.conf"
pkgmgr-client_files += "/usr/lib/libpkgmgr-client.so.*"

pkgmgr_files = ""
pkgmgr_files += "pkgmgr.manifest"
pkgmgr_files += "/etc/package-manager/backend"
pkgmgr_files += "/etc/package-manager/backendlib"
pkgmgr_files += "/etc/opt/upgrade"
pkgmgr_files += "/etc/opt/upgrade/pkgmgr.patch.sh"
pkgmgr_files += "/usr/bin/pkgcmd"
pkgmgr_files += "/usr/bin/pkg_initdb"
pkgmgr_files += "/usr/bin/pkg_getsize"
pkgmgr_files += "/usr/bin/pkginfo"
pkgmgr_files += "/usr/bin/pkgmgr-install"
pkgmgr_files += "/usr/share/packages"
pkgmgr_files += "/usr/share/packages/org.tizen.pkgmgr-install.xml"
pkgmgr_files += "/usr/share/mime/packages/mime.wac.xml"
pkgmgr_files += "/usr/share/mime/packages/mime.tpk.xml"

pkgmgr-server_files = ""
pkgmgr-server_files += "pkgmgr-server.manifest"
pkgmgr-server_files += "/usr/share/dbus-1/system-services/org.tizen.slp.pkgmgr.service"
pkgmgr-server_files += "/etc/dbus-1/system.d/org.tizen.slp.pkgmgr.conf"
pkgmgr-server_files += "/usr/bin/pkgmgr-server"
pkgmgr-server_files += "/etc/package-manager/server"

pkgmgr-types-devel_files = ""
pkgmgr-types-devel_files += "pkgmgr-types-devel.manifest"
pkgmgr-types-devel_files += "/usr/include/package-manager-types.h"
pkgmgr-types-devel_files += "/usr/include/package-manager-plugin.h"
pkgmgr-types-devel_files += "/usr/lib/pkgconfig/pkgmgr-types.pc"

pkgmgr-client-devel_files = ""
pkgmgr-client-devel_files += "pkgmgr-client-devel.manifest"
pkgmgr-client-devel_files += "/usr/include/package-manager.h"
pkgmgr-client-devel_files += "/usr/include/pkgmgr-dbinfo.h"
pkgmgr-client-devel_files += "/usr/lib/pkgconfig/pkgmgr.pc"
pkgmgr-client-devel_files += "/usr/lib/libpkgmgr-client.so"

pkgmgr-installer-devel_files = ""
pkgmgr-installer-devel_files += "pkgmgr-installer-devel.manifest"
pkgmgr-installer-devel_files += "/usr/include/pkgmgr"
pkgmgr-installer-devel_files += "/usr/include/pkgmgr/pkgmgr_installer.h"
pkgmgr-installer-devel_files += "/usr/lib/pkgconfig/pkgmgr-installer-status-broadcast-server.pc"
pkgmgr-installer-devel_files += "/usr/lib/pkgconfig/pkgmgr-installer.pc"
pkgmgr-installer-devel_files += "/usr/lib/pkgconfig/pkgmgr-installer-client.pc"
pkgmgr-installer-devel_files += "/usr/lib/libpkgmgr_installer.so"
pkgmgr-installer-devel_files += "/usr/lib/libpkgmgr_installer_client.so"
pkgmgr-installer-devel_files += "/usr/lib/libpkgmgr_installer_status_broadcast_server.so"

pkgmgr-installer_files = ""
pkgmgr-installer_files += "pkgmgr-installer.manifest"
pkgmgr-installer_files += "/usr/lib/libpkgmgr_installer.so.*"
pkgmgr-installer_files += "/usr/lib/libpkgmgr_installer_status_broadcast_server.so.*"
pkgmgr-installer_files += "/usr/lib/libpkgmgr_installer_client.so.*"

FILES_${PN}-client = "${pkgmgr-client_files}"
FILES_${PN} = "${pkgmgr_files}"
FILES_${PN}-server = "${pkgmgr-server_files}"
FILES_${PN}-types-devel = "${pkgmgr-types-devel_files}"
FILES_${PN}-client-devel = "${pkgmgr-client-devel_files}"
FILES_${PN}-installer-devel = "${pkgmgr-installer-devel_files}"
FILES_${PN}-installer = "${pkgmgr-installer_files}"

PKG_pkgmgr-client= "pkgmgr-client"
PKG_pkgmgr= "pkgmgr"
PKG_pkgmgr-server= "pkgmgr-server"
PKG_pkgmgr-types-devel= "pkgmgr-types-devel"
PKG_pkgmgr-client-devel= "pkgmgr-client-devel"
PKG_pkgmgr-installer-devel= "pkgmgr-installer-devel"
PKG_pkgmgr-installer= "pkgmgr-installer"

require slp-pkgmgr-extraconf.inc
