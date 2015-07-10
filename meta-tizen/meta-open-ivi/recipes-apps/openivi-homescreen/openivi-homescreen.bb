DESCRIPTION = "Homescreen HTML5 application based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-homescreen.git;branch=master;tag=caad9d6273cd22ec2f26bf1387b304b2d2ad783f"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-homescreen


RDEPENDS = ""
#RDEPENDS of openivi-homescreen (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of openivi-homescreen
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n openivi-homescreen-0.0.2
 #cp ${S}/packaging/openivi-homescreen.manifest .
 
 
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
 
 #empty
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p ${D}/opt/usr/apps/.preinstallWidgets
 mkdir -p ${D}${prefix}/share/Modello/Common/icons
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/openivi-homescreen.wgt config.xml manifest.json css icon.png index.html js
 install -m 0644 icon.png ${D}${prefix}/share/Modello/Common/icons
 
 mkdir -p ${D}${prefix}/bin
 mkdir -p ${D}${prefix}/lib/systemd/user/weston.target.wants/
 install -m 755 systemd/DNA_launcher.sh ${D}${prefix}/bin
 install -m 0644 systemd/DNA_Homescreen-launchpad-ready.path ${D}${prefix}/lib/systemd/user
 install -m 0644 systemd/DNA_Homescreen.service ${D}${prefix}/lib/systemd/user
 ln -sf ../DNA_Homescreen-launchpad-ready.path ${D}${prefix}/lib/systemd/user/weston.target.wants/
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-homescreen "

openivi-homescreen_files = ""
openivi-homescreen_files += "/opt/usr/apps/.preinstallWidgets/Modello-Homescreen.wgt"
openivi-homescreen_files += "${prefix}/share/Modello/Common/icons/icon.png"
openivi-homescreen_files += "${prefix}/lib/systemd/user/DNA_Homescreen.service"
openivi-homescreen_files += "${prefix}/lib/systemd/user/DNA_Homescreen-launchpad-ready.path"
openivi-homescreen_files += "${prefix}/bin/DNA_launcher.sh"
openivi-homescreen_files += "${prefix}/lib/systemd/user/weston.target.wants"

FILES_${PN} = "${openivi-homescreen_files}"

PKG_openivi-homescreen= "openivi-homescreen"
