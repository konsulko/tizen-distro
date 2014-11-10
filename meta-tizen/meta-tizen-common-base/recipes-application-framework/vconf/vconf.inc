DESCRIPTION = "Configuration system library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"
PV = "0.2.51"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by vconf-keys-dev
PROVIDES += "vconf-keys-dev"


#PROVIDES by vconf


#PROVIDES by vconf-dev
PROVIDES += "vconf-dev"


RDEPENDS = ""
#RDEPENDS of vconf-keys-dev (${PN}-keys-dev)
RDEPENDS_${PN}-keys-dev += "vconf"
RDEPENDS_${PN}-keys-dev += "vconf-internal-keys-dev"

#RDEPENDS of vconf (${PN})
RDEPENDS_${PN} += "glibc"
RDEPENDS_${PN} += "systemd"

#RDEPENDS of vconf-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "vconf"
RDEPENDS_${PN}-dev += "glib-2.0"


DEPENDS = ""
#DEPENDS of vconf
inherit tizen_cmake
DEPENDS += "vconf-internal-keys"
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "dlog"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n vconf-0.2.51
 cp ${S}/packaging/vconf.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         ${EXTRA_OECMAKE} . \
 	-DTZ_SYS_CONFIG=${prefix}/kdb
 
 make -j16
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
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
 mkdir -p ${D}${prefix}/kdb/db
 mkdir -p ${D}${prefix}/kdb/db/.backup
 mkdir -p ${D}${systemd_unitdir}/system/basic.target.wants
 mkdir -p ${D}${prefix}/lib/tmpfiles.d
 install -m0644 ${S}/packaging/vconf-setup.service ${D}${systemd_unitdir}/system/
 install -m0644 ${S}/packaging/vconf-setup.conf ${D}${prefix}/lib/tmpfiles.d/
 ln -sf ../vconf-setup.service ${D}${systemd_unitdir}/system/basic.target.wants/
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    systemctl daemon-reload
    chsmack -a 'User' $D${prefix}/kdb
    chsmack -a 'User' $D${prefix}/kdb/db
    chsmack -a 'User' $D${prefix}/kdb/db/.backup

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    systemctl daemon-reload

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " vconf-keys-dev "
PACKAGES += " vconf "
PACKAGES += " vconf-dev "

vconf-keys-dev_files = ""
vconf-keys-dev_files += "${prefix}/include/vconf/vconf-keys.h"
MANIFESTFILES_${PN}-keys-dev = "vconf.manifest"

vconf_files = ""
vconf_files += "${sysconfdir}/preconf.d/vconf-setup"
vconf_files += "${prefix}/bin/vconftool"
vconf_files += "${prefix}/bin/vconf-init"
vconf_files += "${prefix}/kdb/kdb_first_boot"
vconf_files += "${prefix}/lib/*.so.*"
vconf_files += "%attr(777,root,users) ${prefix}/kdb/db"
vconf_files += "%attr(777,root,root) ${prefix}/kdb/db/.backup"
vconf_files += "${systemd_unitdir}/system/basic.target.wants/vconf-setup.service"
vconf_files += "${systemd_unitdir}/system/vconf-setup.service"
vconf_files += "${prefix}/lib/tmpfiles.d/vconf-setup.conf"
MANIFESTFILES_${PN} = "vconf.manifest"
DIRFILES_${PN} = ""
DIRFILES_${PN} += "%attr(777,root,users) ${prefix}/kdb/db"
DIRFILES_${PN} += "%attr(777,root,root) ${prefix}/kdb/db/.backup"

vconf-dev_files = ""
vconf-dev_files += "${prefix}/include/vconf/vconf.h"
vconf-dev_files += "${prefix}/lib/pkgconfig/*.pc"
vconf-dev_files += "${prefix}/lib/*.so"
MANIFESTFILES_${PN}-dev = "vconf.manifest"

FILES_${PN}-keys-dev = "${vconf-keys-dev_files}"
FILES_${PN} = "${vconf_files}"
FILES_${PN}-dev = "${vconf-dev_files}"

PKG_vconf-keys-dev= "vconf-keys-dev"
PKG_vconf= "vconf"
PKG_vconf-dev= "vconf-dev"

require vconf-extraconf.inc

