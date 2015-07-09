DESCRIPTION = "Homescreen HTML5 application based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-homescreen.git;branch=master;tag=caad9d6273cd22ec2f26bf1387b304b2d2ad783f"

DEPENDS = ""
DEPENDS += "zip"

S = "${WORKDIR}/git"

do_configure() {
}

do_compile() {
 #cd ${S}/git
 #LANG=C
 #export LANG
 #unset DISPLAY
 #LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 oe_runmake
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}

 mkdir -p ${D}${prefix}/bin
 #cp install_widgets.sh ${D}${prefix}/bin
 #cp prepare_widgets.sh ${D}${prefix}/bin

 mkdir -p  ${D}${prefix}/share/openivi_apps
 cp -r *.wgt ${D}${prefix}/share/openivi_apps/
 #cp -r apps/*.png ${D}${prefix}/share/openivi_apps/
 #cp -r apps/*.desktop ${D}${prefix}/share/openivi_apps/
 #cp install.conf ${D}${prefix}/share/openivi_apps/
 
 # install xwalk preinstall service in user session
 #mkdir -p ${D}${prefix}/lib/systemd/user
 #install -m 644 xwalk_widgets_preinstall.service ${D}${prefix}/lib/systemd/user/
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-homescreen "

openivi-Homescreen_files = ""
openivi-Homescreen_files += "/usr/share/openivi_apps"
openivi-Homescreen_files += "/usr/share/openivi_apps/OPENIVI001.HomeScreen.wgt"
openivi-homescreen_files += "/opt/usr/apps/.preinstallWidgets/OPENIVI001.HomeScreen.wgt"
#openivi-homescreen_files += "${prefix}/share/Modello/Common/icons/Homescreen_icon.png"
#openivi-homescreen_files += "${prefix}/lib/systemd/user/Modello_Homescreen.service"
#openivi-homescreen_files += "${prefix}/lib/systemd/user/Modello_Homescreen-launchpad-ready.path"
#openivi-homescreen_files += "${prefix}/bin/modello_launcher.sh"
#openivi-homescreen_files += "${prefix}/lib/systemd/user/weston.target.wants"

FILES_${PN} = "${openivi-homescreen_files}"

PKG_openivi-homescreen= "openivi-homescreen"




