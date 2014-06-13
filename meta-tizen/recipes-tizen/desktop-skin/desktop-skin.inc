DESCRIPTION = "Provides desktop-skin."
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by desktop-skin 


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
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
 
 mkdir -p ${D}${prefix}/bin
 install -m 755 Script/launch_cam.sh ${D}${prefix}/bin
 install -m 755 Script/launch_video.sh ${D}${prefix}/bin
 
 mkdir -p ${D}/home/app
 install -m 644 Video/AmazingNature_480p.mp4 ${D}/home/app
 
 mkdir -p ${D}/home/app/Photos
 install -m 644 Photos/* ${D}/home/app/Photos
 
 mkdir -p ${D}${prefix}/share/icons/tizen/32x32
 install -m 644 icons/tizen/32x32/* ${D}${prefix}/share/icons/tizen/32x32
 
 mkdir -p ${D}${prefix}/share/backgrounds/tizen
 install -m 644  backgrounds/tizen/golfe-morbihan.jpg ${D}${prefix}/share/backgrounds/tizen/golfe-morbihan.jpg
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e
    chown -R app:app /home/app

}


desktop-skin_files = ""
desktop-skin_files += "${prefix}/bin/launch_cam.sh"
desktop-skin_files += "${prefix}/bin/launch_video.sh"
desktop-skin_files += "/home/app/AmazingNature_480p.mp4"
desktop-skin_files += "/home/app/Photos/*"
desktop-skin_files += "${prefix}/share/icons/tizen/32x32/*"
desktop-skin_files += "${prefix}/share/backgrounds/tizen/golfe-morbihan.jpg"

FILES_${PN} = "${desktop-skin_files}"

PKG_desktop-skin= "desktop-skin"

require desktop-skin-extraconf.inc

