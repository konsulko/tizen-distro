DESCRIPTION = "Provides desktop-skin."
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by desktop-skin 
PROVIDES += "desktop-skin"
RPROVIDES_desktop-skin += "desktop-skin"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 install -m 755 Script/launch_cam.sh ${D}/usr/bin
 install -m 755 Script/launch_video.sh ${D}/usr/bin
 
 mkdir -p ${D}/home/app
 install -m 644 Video/AmazingNature_480p.mp4 ${D}/home/app
 
 mkdir -p ${D}/home/app/Photos
 install -m 644 Photos/* ${D}/home/app/Photos
 
 mkdir -p ${D}/usr/share/icons/tizen/32x32
 install -m 644 icons/tizen/32x32/* ${D}/usr/share/icons/tizen/32x32
 
 mkdir -p ${D}/usr/share/backgrounds/tizen
 install -m 644  backgrounds/tizen/golfe-morbihan.jpg ${D}/usr/share/backgrounds/tizen/golfe-morbihan.jpg
 
 
}

PACKAGES = ""
PACKAGES += "desktop-skin"

desktop-skin_files = ""
desktop-skin_files += "/usr/bin/launch_cam.sh"
desktop-skin_files += "/usr/bin/launch_video.sh"
desktop-skin_files += "/home/app/AmazingNature_480p.mp4"
desktop-skin_files += "/home/app/Photos/*"
desktop-skin_files += "/usr/share/icons/tizen/32x32/*"
desktop-skin_files += "/usr/share/backgrounds/tizen/golfe-morbihan.jpg"

FILES_${PN} = "${desktop-skin_files}"

PKG_desktop-skin= "desktop-skin"

require desktop-skin-extraconf.inc
