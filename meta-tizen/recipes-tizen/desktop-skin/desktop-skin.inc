DESCRIPTION = "Desktop skin for Tizen:Common"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Multimedia"
LICENSE = "GPL-2.0+"
PV = "2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by desktop-skin


RDEPENDS = ""
#RDEPENDS of desktop-skin (${PN})
RDEPENDS_${PN} += "python-pycairo"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/desktop-skin.manifest .
 
 
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
 
 mkdir -p ${D}${prefix}/bin
 install -m 755 Script/launch_cam.sh ${D}${prefix}/bin
 install -m 755 Script/launch_video.sh ${D}${prefix}/bin
 install -m 755 Script/mark_image.py ${D}${prefix}/bin
 install -m 755 Script/wifi ${D}${prefix}/bin
 
 mkdir -p ${D}${prefix}/share/media/videos
 install -m 644 Video/AmazingNature_480p.mp4 ${D}${prefix}/share/media/videos
 
 mkdir -p ${D}${prefix}/share/media/photos
 install -m 644 Photos/* ${D}${prefix}/share/media/photos
 
 mkdir -p ${D}${prefix}/share/icons/tizen/32x32
 install -m 644 icons/tizen/32x32/* ${D}${prefix}/share/icons/tizen/32x32
 
 mkdir -p ${D}${prefix}/share/applications/tizen
 install -m 644 applications/tizen/* ${D}${prefix}/share/applications/tizen
 
 mkdir -p ${D}${prefix}/share/backgrounds/tizen
 install -m 644  backgrounds/tizen/golfe-morbihan.jpg ${D}${prefix}/share/backgrounds/tizen/golfe-morbihan.jpg
 install -m 644  backgrounds/tizen/tizen_common.png ${D}${prefix}/share/backgrounds/tizen/tizen_common.png
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ln -sf tizen_common.png $D${prefix}/share/backgrounds/tizen/current

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " desktop-skin "

desktop-skin_files = ""
desktop-skin_files += "${prefix}/bin/*"
desktop-skin_files += "${prefix}/share/media/videos/AmazingNature_480p.mp4"
desktop-skin_files += "${prefix}/share/media/photos/*"
desktop-skin_files += "${prefix}/share/icons/tizen/32x32/*"
desktop-skin_files += "${prefix}/share/applications/tizen/*"
desktop-skin_files += "${prefix}/share/backgrounds/tizen/*"
MANIFESTFILES_${PN} = "desktop-skin.manifest"

FILES_${PN} = "${desktop-skin_files}"

PKG_desktop-skin= "desktop-skin"

require desktop-skin-extraconf.inc

