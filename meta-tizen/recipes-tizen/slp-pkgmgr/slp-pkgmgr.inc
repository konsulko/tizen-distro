DESCRIPTION = "Packager Manager client library package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Package Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by pkgmgr-client


#PROVIDES by pkgmgr


#PROVIDES by pkgmgr-server


#PROVIDES by pkgmgr-types-dev


#PROVIDES by pkgmgr-client-dev


#PROVIDES by pkgmgr-installer-dev


#PROVIDES by pkgmgr-installer


RDEPENDS = ""
#RDEPENDS of pkgmgr-client (pkgmgr-client)
RDEPENDS_pkgmgr-client += "shared-mime-info"
RDEPENDS_pkgmgr-client += "pkgmgr"

#RDEPENDS of pkgmgr-server (pkgmgr-server)
RDEPENDS_pkgmgr-server += "pkgmgr"

#RDEPENDS of pkgmgr-types-dev (pkgmgr-types-dev)
RDEPENDS_pkgmgr-types-dev += "pkgmgr"

#RDEPENDS of pkgmgr-client-dev (pkgmgr-client-dev)
RDEPENDS_pkgmgr-client-dev += "pkgmgr"

#RDEPENDS of pkgmgr-installer-dev (pkgmgr-installer-dev)
RDEPENDS_pkgmgr-installer-dev += "pkgmgr"

#RDEPENDS of pkgmgr-installer (pkgmgr-installer)
RDEPENDS_pkgmgr-installer += "pkgmgr"


DEPENDS = ""
#DEPENDS of pkgmgr
DEPENDS += "pkgmgr-info"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "unzip"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "iniparser"
DEPENDS += "dbus"
DEPENDS += "security-server"
DEPENDS += "dlog"
DEPENDS += "app-core"
DEPENDS += "ail"
DEPENDS += "bundle"
DEPENDS += "ecore"
DEPENDS += "tizen-platform-config"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pkgmgr.manifest ${S}/packaging/pkgmgr-client.manifest ${S}/packaging/pkgmgr-client-devel.manifest ${S}/packaging/pkgmgr-server.manifest ${S}/packaging/pkgmgr-installer.manifest ${S}/packaging/pkgmgr-installer-devel.manifest ${S}/packaging/pkgmgr-types-devel.manifest .
 
 
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
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         ${EXTRA_OECMAKE} . \
     -DX11_SUPPORT=Off
 
 make 
 
 
 
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
 rm -f  ${D}${prefix}/bin/pkgmgr_backend_sample
 rm -f ${D}${prefix}/lib/libpkgmgr_backend_lib_sample.so
 rm -f ${D}${prefix}/lib/libpkgmgr_parser_lib_sample.so
 
 mkdir -p ${D}${sysconfdir}/package-manager/backend
 mkdir -p ${D}${sysconfdir}/package-manager/backendlib
 mkdir -p ${D}/etc/opt/upgrade
 
 mkdir -p ${D}${sysconfdir}/package-manager/server
 
 #find_lang package-manager
 
 
 
}

pkg_postinst_pkgmgr-installer() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postinst_pkgmgr-server() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    # For pkgmgr-install:
    # Update mime database to support package mime types
    update-mime-database /usr/share/mime

}

pkg_postinst_pkgmgr-client() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_pkgmgr-client() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_pkgmgr-installer() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " pkgmgr-client "
PACKAGES += " pkgmgr "
PACKAGES += " pkgmgr-server "
PACKAGES += " pkgmgr-types-dev "
PACKAGES += " pkgmgr-client-dev "
PACKAGES += " pkgmgr-installer-dev "
PACKAGES += " pkgmgr-installer "

pkgmgr-client_files = ""
pkgmgr-client_files += "${sysconfdir}/package-manager"
pkgmgr-client_files += "${sysconfdir}/package-manager/pkg_path.conf"
pkgmgr-client_files += "${prefix}/lib/libpkgmgr-client.so.*"
CONFFILES_pkgmgr-client = ""
CONFFILES_pkgmgr-client += "${sysconfdir}/package-manager/pkg_path.conf"
MANIFESTFILES_pkgmgr-client = "pkgmgr-client.manifest"
DIRFILES_pkgmgr-client = ""
DIRFILES_pkgmgr-client += "${sysconfdir}/package-manager"

pkgmgr_files = ""
pkgmgr_files += "${sysconfdir}/package-manager/backend"
pkgmgr_files += "${sysconfdir}/package-manager/backendlib"
pkgmgr_files += "${sysconfdir}/opt/upgrade"
pkgmgr_files += "${sysconfdir}/opt/upgrade/pkgmgr.patch.sh"
pkgmgr_files += "${prefix}/bin/pkgcmd"
pkgmgr_files += "${prefix}/bin/pkgcmd.real"
pkgmgr_files += "${prefix}/bin/pkgcmd.wrapper"
pkgmgr_files += "${prefix}/bin/pkg_initdb"
pkgmgr_files += "${prefix}/bin/pkg_getsize"
pkgmgr_files += "${prefix}/bin/pkginfo"
pkgmgr_files += "${prefix}/bin/pkgmgr-install"
pkgmgr_files += "${prefix}/share/packages"
pkgmgr_files += "${prefix}/share/packages/org.tizen.pkgmgr-install.xml"
pkgmgr_files += "${prefix}/share/mime/packages/mime.wac.xml"
pkgmgr_files += "${prefix}/share/mime/packages/mime.tpk.xml"
MANIFESTFILES_pkgmgr = "pkgmgr.manifest"
DIRFILES_pkgmgr = ""
DIRFILES_pkgmgr += "${sysconfdir}/package-manager/backend"
DIRFILES_pkgmgr += "${sysconfdir}/package-manager/backendlib"
DIRFILES_pkgmgr += "${sysconfdir}/opt/upgrade"
DIRFILES_pkgmgr += "${prefix}/share/packages"

pkgmgr-server_files = ""
pkgmgr-server_files += "${prefix}/share/dbus-1/system-services/org.tizen.slp.pkgmgr.service"
pkgmgr-server_files += "${sysconfdir}/dbus-1/system.d/org.tizen.slp.pkgmgr.conf"
pkgmgr-server_files += "${prefix}/bin/pkgmgr-server"
pkgmgr-server_files += "${sysconfdir}/package-manager/server"
CONFFILES_pkgmgr-server = ""
CONFFILES_pkgmgr-server += "${sysconfdir}/dbus-1/system.d/org.tizen.slp.pkgmgr.conf"
MANIFESTFILES_pkgmgr-server = "pkgmgr-server.manifest"

pkgmgr-types-dev_files = ""
pkgmgr-types-dev_files += "${prefix}/include/package-manager-types.h"
pkgmgr-types-dev_files += "${prefix}/include/package-manager-plugin.h"
pkgmgr-types-dev_files += "${prefix}/lib/pkgconfig/pkgmgr-types.pc"
MANIFESTFILES_pkgmgr-types-dev = "pkgmgr-types-devel.manifest"

pkgmgr-client-dev_files = ""
pkgmgr-client-dev_files += "${prefix}/include/package-manager.h"
pkgmgr-client-dev_files += "${prefix}/include/pkgmgr-dbinfo.h"
pkgmgr-client-dev_files += "${prefix}/lib/pkgconfig/pkgmgr.pc"
pkgmgr-client-dev_files += "${prefix}/lib/libpkgmgr-client.so"
MANIFESTFILES_pkgmgr-client-dev = "pkgmgr-client-devel.manifest"

pkgmgr-installer-dev_files = ""
pkgmgr-installer-dev_files += "${prefix}/include/pkgmgr"
pkgmgr-installer-dev_files += "${prefix}/include/pkgmgr/pkgmgr_installer.h"
pkgmgr-installer-dev_files += "${prefix}/lib/pkgconfig/pkgmgr-installer-status-broadcast-server.pc"
pkgmgr-installer-dev_files += "${prefix}/lib/pkgconfig/pkgmgr-installer.pc"
pkgmgr-installer-dev_files += "${prefix}/lib/pkgconfig/pkgmgr-installer-client.pc"
pkgmgr-installer-dev_files += "${prefix}/lib/libpkgmgr_installer.so"
pkgmgr-installer-dev_files += "${prefix}/lib/libpkgmgr_installer_client.so"
pkgmgr-installer-dev_files += "${prefix}/lib/libpkgmgr_installer_status_broadcast_server.so"
MANIFESTFILES_pkgmgr-installer-dev = "pkgmgr-installer-devel.manifest"
DIRFILES_pkgmgr-installer-dev = ""
DIRFILES_pkgmgr-installer-dev += "${prefix}/include/pkgmgr"

pkgmgr-installer_files = ""
pkgmgr-installer_files += "${prefix}/lib/libpkgmgr_installer.so.*"
pkgmgr-installer_files += "${prefix}/lib/libpkgmgr_installer_status_broadcast_server.so.*"
pkgmgr-installer_files += "${prefix}/lib/libpkgmgr_installer_client.so.*"
MANIFESTFILES_pkgmgr-installer = "pkgmgr-installer.manifest"

FILES_pkgmgr-client = "${pkgmgr-client_files}"
FILES_pkgmgr = "${pkgmgr_files}"
FILES_pkgmgr-server = "${pkgmgr-server_files}"
FILES_pkgmgr-types-dev = "${pkgmgr-types-dev_files}"
FILES_pkgmgr-client-dev = "${pkgmgr-client-dev_files}"
FILES_pkgmgr-installer-dev = "${pkgmgr-installer-dev_files}"
FILES_pkgmgr-installer = "${pkgmgr-installer_files}"

PKG_pkgmgr-client= "pkgmgr-client"
PKG_pkgmgr= "pkgmgr"
PKG_pkgmgr-server= "pkgmgr-server"
PKG_pkgmgr-types-dev= "pkgmgr-types-dev"
PKG_pkgmgr-client-dev= "pkgmgr-client-dev"
PKG_pkgmgr-installer-dev= "pkgmgr-installer-dev"
PKG_pkgmgr-installer= "pkgmgr-installer"

require slp-pkgmgr-extraconf.inc

