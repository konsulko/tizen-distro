DESCRIPTION = "A Build Tool to Update Desktop Files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0+"
PV = "12.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by update-desktop-files


#PROVIDES by brp-trim-desktopfiles
PROVIDES += "brp-trim-desktopfiles"


RDEPENDS = ""
#RDEPENDS of update-desktop-files (${PN})
RDEPENDS_${PN} += "desktop-file-utils"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n . -D -T 0
 cp ${S}/packaging/update-desktop-files.manifest .
 mkdir update-desktop-files
 cd update-desktop-files
 
 
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
 
 mkdir -p ${D}/usr/share/spec2yocto/macro
 install -m0755 ${S}/packaging/tizen_update_desktop_file.sh ${S}/packaging/map-desktop-category.sh ${D}/usr/share/spec2yocto/macro
 install -m0644 -D ${S}/packaging/macro ${D}${sysconfdir}/rpm/macros.update-desktop-files
 install -m0755 -D ${S}/packaging/brp-trim-desktop.sh ${D}/usr/share/spec2yocto/macro/brp-tizen.d/brp-70-trim-desktopfiles
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " brp-trim-desktopfiles "
PACKAGES += " update-desktop-files "

brp-trim-desktopfiles_files = ""
brp-trim-desktopfiles_files += "/usr/share/spec2yocto/macro/brp-tizen.d"
MANIFESTFILES_brp-trim-desktopfiles = "update-desktop-files.manifest"

update-desktop-files_files = ""
update-desktop-files_files += "/usr/share/spec2yocto/macro/*"
update-desktop-files_files += "${sysconfdir}/rpm/*"
MANIFESTFILES_${PN} = "update-desktop-files.manifest"

FILES_brp-trim-desktopfiles = "${brp-trim-desktopfiles_files}"
FILES_${PN} = "${update-desktop-files_files}"

PKG_brp-trim-desktopfiles= "brp-trim-desktopfiles"
PKG_update-desktop-files= "update-desktop-files"

require update-desktop-files-extraconf.inc

