DESCRIPTION = "Various early setup programs"
HOMEPAGE = "http://www.tizen.org"
SECTION = "System/Configuration"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by setup-gummiboot 
PROVIDES += "setup-gummiboot"
RPROVIDES_setup-gummiboot += "setup-gummiboot"
# the PROVIDES rules is ignore "virtual-setup-ivi-bootloader  "
PROVIDES += "virtual-setup-ivi-bootloader"
RPROVIDES_setup-gummiboot += "virtual-setup-ivi-bootloader"

#PROVIDES by setup-ivi-clone 
PROVIDES += "setup-ivi-clone"
RPROVIDES_setup-ivi-clone += "setup-ivi-clone"

#PROVIDES by setup-extlinux 
PROVIDES += "setup-extlinux"
RPROVIDES_setup-extlinux += "setup-extlinux"
# the PROVIDES rules is ignore "virtual-setup-ivi-bootloader  "
PROVIDES += "virtual-setup-ivi-bootloader"
RPROVIDES_setup-extlinux += "virtual-setup-ivi-bootloader"

#PROVIDES by setup-ivi 
PROVIDES += "setup-ivi"
RPROVIDES_setup-ivi += "setup-ivi"

RDEPENDS = ""
#RDEPENDS of setup-gummiboot (setup-gummiboot)
RDEPENDS_setup-gummiboot += "gummiboot"
RDEPENDS_setup-gummiboot += "setup-ivi"

#RDEPENDS of setup-ivi-clone (${PN}-clone)
RDEPENDS_${PN}-clone += "/usr/bin/mount"
RDEPENDS_${PN}-clone += "systemd"
RDEPENDS_${PN}-clone += "/usr/bin/sync"
RDEPENDS_${PN}-clone += "/usr/bin/uuidgen"
RDEPENDS_${PN}-clone += "setup-ivi"
RDEPENDS_${PN}-clone += "dosfstools"
RDEPENDS_${PN}-clone += "rsync"
RDEPENDS_${PN}-clone += "e2fsprogs"
RDEPENDS_${PN}-clone += "/usr/bin/udevadm"
RDEPENDS_${PN}-clone += "gptfdisk"
RDEPENDS_${PN}-clone += "/usr/bin/tail"

#RDEPENDS of setup-ivi (${PN})
RDEPENDS_${PN} += "/usr/bin/tr"
RDEPENDS_${PN} += "/usr/bin/sort"
RDEPENDS_${PN} += "virtual-setup-ivi-bootloader"
RDEPENDS_${PN} += "/usr/bin/grep"
RDEPENDS_${PN} += "/usr/bin/printenv"
RDEPENDS_${PN} += "/usr/bin/sed"
RDEPENDS_${PN} += "/usr/bin/printf"

#RDEPENDS of setup-extlinux (setup-extlinux)
RDEPENDS_setup-extlinux += "syslinux-extlinux"
RDEPENDS_setup-extlinux += "setup-ivi"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n setup-ivi-1.0
 
 
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
 
 
 ###
 ### INSTALL
 ###
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}//usr/sbin
 install -d ${D}//usr/share/setup-ivi
 install -d ${D}//lib/systemd/system
 
 install -m755 setup-ivi-boot ${D}//usr/sbin
 install -m755 setup-ivi-fstab ${D}//usr/sbin
 install -m755 setup-ivi-bootloader-conf ${D}//usr/sbin
 install -m755 setup-ivi-clone ${D}//usr/sbin
 install -m755 setup-ivi-clone-service ${D}//usr/sbin
 install -m644 ivi-clone.service ${D}//lib/systemd/system
 install -m755 setup-gummiboot-conf ${D}//usr/sbin
 install -m755 setup-extlinux-conf ${D}//usr/sbin
 install -m644 setup-ivi-sh-functions ${D}//usr/share/setup-ivi
 install -m644 installerfw-sh-functions ${D}//usr/share/setup-ivi
 
 ###
 ### CLEAN
 ###
 
}

PACKAGES = ""
PACKAGES += "setup-gummiboot"
PACKAGES += "setup-ivi-clone"
PACKAGES += "setup-extlinux"
PACKAGES += "setup-ivi"

setup-gummiboot_files = ""
setup-gummiboot_files += "/usr/sbin/setup-gummiboot-conf"

setup-ivi-clone_files = ""
setup-ivi-clone_files += "/usr/sbin/setup-ivi-clone"
setup-ivi-clone_files += "/usr/sbin/setup-ivi-clone-service"
setup-ivi-clone_files += "/lib/systemd/system/ivi-clone.service"

setup-extlinux_files = ""
setup-extlinux_files += "/usr/sbin/setup-extlinux-conf"

setup-ivi_files = ""
setup-ivi_files += "/usr/sbin/setup-ivi-boot"
setup-ivi_files += "/usr/sbin/setup-ivi-fstab"
setup-ivi_files += "/usr/sbin/setup-ivi-bootloader-conf"
setup-ivi_files += "/usr/share/setup-ivi/setup-ivi-sh-functions"
setup-ivi_files += "/usr/share/setup-ivi/installerfw-sh-functions"

FILES_setup-gummiboot = "${setup-gummiboot_files}"
FILES_${PN}-clone = "${setup-ivi-clone_files}"
FILES_setup-extlinux = "${setup-extlinux_files}"
FILES_${PN} = "${setup-ivi_files}"

PKG_setup-gummiboot= "setup-gummiboot"
PKG_setup-ivi-clone= "setup-ivi-clone"
PKG_setup-extlinux= "setup-extlinux"
PKG_setup-ivi= "setup-ivi"

require setup-ivi-extraconf.inc
