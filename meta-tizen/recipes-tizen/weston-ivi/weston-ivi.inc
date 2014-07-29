DESCRIPTION = "Tizen IVI Weston configuration and set-up"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Configuration"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by weston-ivi-config
PROVIDES += "weston-ivi-config"


#PROVIDES by weston-ivi
# the PROVIDES rules is ignore "weston-startup  "
PROVIDES += "weston-startup"
RPROVIDES_weston-ivi += "weston-startup"


RDEPENDS = ""
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
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
 install -d ${D}/lib/systemd/user/weston.target.wants
 install -m 644 weston.service ${D}/lib/systemd/user/weston.service
 ln -sf ../weston.service ${D}//lib/systemd/user/weston.target.wants/
 
 mkdir -p ${D}${sysconfdir}/profile.d/
 install -m 0644 weston.sh ${D}${sysconfdir}/profile.d/
 
 mkdir -p ${D}${sysconfdir}/xdg/weston
 install -m 0644 weston.ini ${D}${sysconfdir}/xdg/weston
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " weston-ivi-config "
PACKAGES += " weston-ivi "

weston-ivi-config_files = ""
weston-ivi-config_files += "${sysconfdir}/xdg/weston/weston.ini"
CONFFILES_${PN}-config = ""
CONFFILES_${PN}-config += "${sysconfdir}/xdg/weston/weston.ini"
MANIFESTFILES_${PN}-config = "weston-ivi.manifest"

weston-ivi_files = ""
weston-ivi_files += "/lib/systemd/user/weston.service"
weston-ivi_files += "/lib/systemd/user/weston.target.wants/weston.service"
weston-ivi_files += "${sysconfdir}/profile.d/*"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/profile.d/*"
MANIFESTFILES_${PN} = "weston-ivi.manifest"

FILES_${PN}-config = "${weston-ivi-config_files}"
FILES_${PN} = "${weston-ivi_files}"

PKG_weston-ivi-config= "weston-ivi-config"
PKG_weston-ivi= "weston-ivi"

require weston-ivi-extraconf.inc

