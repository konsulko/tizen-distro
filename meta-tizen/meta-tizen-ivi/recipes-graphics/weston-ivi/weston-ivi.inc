DESCRIPTION = "Tizen IVI Weston configuration and set-up"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Configuration"
LICENSE = "MIT"
PV = "1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by weston-ivi-config-modello
PROVIDES += "weston-ivi-config-modello"


#PROVIDES by weston-ivi-config
PROVIDES += "weston-ivi-config"


#PROVIDES by weston-ivi
# the PROVIDES rules is ignore "weston-startup  "
PROVIDES += "weston-startup"
RPROVIDES_weston-ivi += "weston-startup"


RDEPENDS = ""
#RDEPENDS of weston-ivi-config-modello (${PN}-config-modello)
RDEPENDS_${PN}-config-modello += "weekeyboard"
RDEPENDS_${PN}-config-modello += "sed"

#RDEPENDS of weston-ivi-config (${PN}-config)
RDEPENDS_${PN}-config += "weekeyboard"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/weston-ivi.manifest .
 
 
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
 
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
 install -d ${D}${prefix}/lib/systemd/user/weston.target.wants
 install -m 644 weston.service ${D}${prefix}/lib/systemd/user/weston.service
 ln -sf ../weston.service ${D}${prefix}/lib/systemd/user/weston.target.wants/
 
 mkdir -p ${D}${sysconfdir}/profile.d/
 install -m 0644 weston.sh ${D}${sysconfdir}/profile.d/
 
 mkdir -p ${D}${sysconfdir}/xdg/weston
 install -m 0644 weston.ini ${D}${sysconfdir}/xdg/weston
 install -m 0644 weston-modello.ini ${D}${sysconfdir}/xdg/weston/weston-modello.ini
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ln -s $D${sysconfdir}/xdg/weston/weston-modello.ini $D${sysconfdir}/xdg/weston/weston.ini
    sed -i 's/ --current-mode//' $D${prefix}/lib/systemd/user/weston.service

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    rm $D${sysconfdir}/xdg/weston/weston.ini
    sed -i 's/\(^ExecStart.*\)/\1 --current-mode/' $D${prefix}/lib/systemd/user/weston.service

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " weston-ivi-config-modello "
PACKAGES += " weston-ivi-config "
PACKAGES += " weston-ivi "

weston-ivi-config-modello_files = ""
weston-ivi-config-modello_files += "${sysconfdir}/xdg/weston/weston-modello.ini"
CONFFILES_${PN}-config-modello = ""
CONFFILES_${PN}-config-modello += "${sysconfdir}/xdg/weston/weston-modello.ini"
MANIFESTFILES_${PN}-config-modello = "weston-ivi.manifest"

weston-ivi-config_files = ""
weston-ivi-config_files += "${sysconfdir}/xdg/weston/weston.ini"
CONFFILES_${PN}-config = ""
CONFFILES_${PN}-config += "${sysconfdir}/xdg/weston/weston.ini"
MANIFESTFILES_${PN}-config = "weston-ivi.manifest"

weston-ivi_files = ""
weston-ivi_files += "${prefix}/lib/systemd/user/weston.service"
weston-ivi_files += "${prefix}/lib/systemd/user/weston.target.wants/weston.service"
weston-ivi_files += "${sysconfdir}/profile.d/*"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/profile.d/*"
MANIFESTFILES_${PN} = "weston-ivi.manifest"

FILES_${PN}-config-modello = "${weston-ivi-config-modello_files}"
FILES_${PN}-config = "${weston-ivi-config_files}"
FILES_${PN} = "${weston-ivi_files}"

PKG_weston-ivi-config-modello= "weston-ivi-config-modello"
PKG_weston-ivi-config= "weston-ivi-config"
PKG_weston-ivi= "weston-ivi"

require weston-ivi-extraconf.inc

