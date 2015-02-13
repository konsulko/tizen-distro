DESCRIPTION = "Tizen IVI udev Rules"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Hardware Adaptation"
LICENSE = "GPL-2.0"
PV = "0.13"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by udev-rules


#PROVIDES by udev-rules-ivi
PROVIDES += "udev-rules-ivi"


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n udev-rules-0.13
 
 
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
 
 rm -rf ${D}
 make -C ivi install DESTDIR=${D}
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " udev-rules-ivi "

udev-rules-ivi_files = ""
udev-rules-ivi_files += "/usr/lib/udev/rules.d/99-atkbd.rules"
udev-rules-ivi_files += "/usr/lib/udev/rules.d/99-dri.rules"
udev-rules-ivi_files += "/usr/lib/udev/rules.d/99-neard.rules"
udev-rules-ivi_files += "/usr/lib/udev/rules.d/99-tty.rules"
udev-rules-ivi_files += "/usr/lib/udev/rules.d/70-tun.rules"

FILES_${PN}-ivi = "${udev-rules-ivi_files}"

PKG_udev-rules-ivi= "udev-rules-ivi"

require udev-rules-extraconf.inc

