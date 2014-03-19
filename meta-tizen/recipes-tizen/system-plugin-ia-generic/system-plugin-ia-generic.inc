DESCRIPTION = "The inittab file and the /etc/init.d scripts"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "Apache v2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by system-plugin-ia-generic-clovertrail 
PROVIDES += "system-plugin-ia-generic-clovertrail"
RPROVIDES_system-plugin-ia-generic-clovertrail += "system-plugin-ia-generic-clovertrail"

#PROVIDES by system-plugin-ia-generic-blackbay 
PROVIDES += "system-plugin-ia-generic-blackbay"
RPROVIDES_system-plugin-ia-generic-blackbay += "system-plugin-ia-generic-blackbay"

#PROVIDES by system-plugin-ia-generic 
PROVIDES += "system-plugin-ia-generic"
RPROVIDES_system-plugin-ia-generic += "system-plugin-ia-generic"

RDEPENDS = ""
#RDEPENDS of system-plugin-ia-generic-clovertrail (${PN}-clovertrail)
RDEPENDS_${PN}-clovertrail += "system-plugin-ia-generic"

#RDEPENDS of system-plugin-ia-generic-blackbay (${PN}-blackbay)
RDEPENDS_${PN}-blackbay += "system-plugin-ia-generic"

#RDEPENDS of system-plugin-ia-generic (${PN})
RDEPENDS_${PN} += "corewatcher"
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "udev"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 # >> gbp-apply-patches    # auto-added by gbp
 # << gbp-apply-patches    # auto-added by gbp
 
 
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
 
 cp ${S}/packaging/system-plugin-ia-generic.manifest .
 gcc -o brcm_patchram_plus brcm_patchram_plus.c
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cp -a etc ${D}
 cp -a usr ${D}
 mkdir -p ${D}/usr/etc/bluetooth/
 #install -m 0755 scripts/bt-dev-end.sh  ${D}/usr/etc/bluetooth/
 #install -m 0755 scripts/bt-dev-start.sh  ${D}/usr/etc/bluetooth/
 install -m 0755 scripts/bt-set-addr.sh  ${D}/usr/etc/bluetooth/
 mkdir -p ${D}/bin/
 cp -f brcm_patchram_plus ${D}/bin/
 
 
}

PACKAGES = ""
PACKAGES += "system-plugin-ia-generic-clovertrail"
PACKAGES += "system-plugin-ia-generic-blackbay"
PACKAGES += "system-plugin-ia-generic"

system-plugin-ia-generic-clovertrail_files = ""
system-plugin-ia-generic-clovertrail_files += "/etc/profile.d/display-1280x720.sh"

system-plugin-ia-generic-blackbay_files = ""
system-plugin-ia-generic-blackbay_files += "/etc/profile.d/fonts.sh"

system-plugin-ia-generic_files = ""
system-plugin-ia-generic_files += "system-plugin-ia-generic.manifest"
system-plugin-ia-generic_files += "/etc/fstab"
system-plugin-ia-generic_files += "/etc/inittab"
system-plugin-ia-generic_files += "/etc/modules-load.d/comms.conf"
system-plugin-ia-generic_files += "/etc/profile.d/system.sh"
system-plugin-ia-generic_files += "/etc/rc.d/rc.entersleep"
system-plugin-ia-generic_files += "/etc/rc.d/rc.firstboot"
system-plugin-ia-generic_files += "/etc/rc.d/rc.leavesleep"
system-plugin-ia-generic_files += "/etc/rc.d/rc.shutdown"
system-plugin-ia-generic_files += "/etc/rc.d/rc.sysinit"
system-plugin-ia-generic_files += "/etc/rc.d/rc.*"
system-plugin-ia-generic_files += "/usr/bin/wlan.sh"
system-plugin-ia-generic_files += "/usr/bin/wlan_prov.pl"
system-plugin-ia-generic_files += "/usr/lib/systemd/system/firstboot.service"
system-plugin-ia-generic_files += "/usr/lib/systemd/system/sysinit.target.wants/firstboot.service"

FILES_${PN}-clovertrail = "${system-plugin-ia-generic-clovertrail_files}"
FILES_${PN}-blackbay = "${system-plugin-ia-generic-blackbay_files}"
FILES_${PN} = "${system-plugin-ia-generic_files}"

PKG_system-plugin-ia-generic-clovertrail= "system-plugin-ia-generic-clovertrail"
PKG_system-plugin-ia-generic-blackbay= "system-plugin-ia-generic-blackbay"
PKG_system-plugin-ia-generic= "system-plugin-ia-generic"

require system-plugin-ia-generic-extraconf.inc
