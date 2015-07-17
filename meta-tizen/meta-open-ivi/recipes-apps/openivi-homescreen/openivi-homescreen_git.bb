DESCRIPTION = "Homescreen HTML5 application based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-homescreen.git;protocol=https;branch=master;tag=e4daf6b2b2f0a1d9c55cfa8a028818baf0987cd6"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-homescreen


RDEPENDS = ""
#RDEPENDS of openivi-homescreen (${PN})
RDEPENDS_${PN} += "openivi-common-app"


DEPENDS = ""
#DEPENDS of openivi-homescreen
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"
DEPENDS += "zip-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
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
 mkdir -p ${D}${prefix}/share/openivi/Common/icons
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/openivi-homescreen.wgt config.xml css icon.png index.html js images
 install -m 0644 icon.png ${D}${prefix}/share/openivi/Common/icons
 
 mkdir -p ${D}${prefix}/bin
 mkdir -p ${D}/lib/systemd/system
 mkdir -p ${D}/etc/systemd/system/multi-user.target.wants/
 install -m 755 systemd/OPENIVI_launcher.sh ${D}${prefix}/bin
 install -m 0644 systemd/OPENIVI_Homescreen.service ${D}/lib/systemd/system
 ln -sf systemd/OPENIVI_Homescreen.service ${D}/etc/systemd/system/multi-user.target.wants/
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-homescreen "

openivi-homescreen_files = ""
openivi-homescreen_files += "/opt/usr/apps/.preinstallWidgets/openivi-homescreen.wgt"
openivi-homescreen_files += "${prefix}/share/openivi/Common/icons/icon.png"
openivi-homescreen_files += "/lib/systemd/system/OPENIVI_Homescreen.service"
openivi-homescreen_files += "${prefix}/bin/OPENIVI_launcher.sh"
openivi-homescreen_files += "/etc/systemd/system/multi-user.target.wants/"

FILES_${PN} = "${openivi-homescreen_files}"

PKG_openivi-homescreen= "openivi-homescreen"
