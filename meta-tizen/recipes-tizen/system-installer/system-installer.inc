DESCRIPTION = "PC Installer"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by system-installer 
PROVIDES += "system-installer"
RPROVIDES_system-installer += "system-installer"

RDEPENDS = ""
#RDEPENDS of system-installer (${PN})
RDEPENDS_${PN} += "rsync"
RDEPENDS_${PN} += "gptfdisk"
RDEPENDS_${PN} += "dosfstools"
RDEPENDS_${PN} += "snapper"
RDEPENDS_${PN} += "plymouth"
RDEPENDS_${PN} += "syslinux-extlinux"
RDEPENDS_${PN} += "btrfs-progs"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/system-installer.manifest .
 
 
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
 
 install -d ${D}//usr/sbin
 install -d ${D}//etc/installer
 install -d ${D}//lib/systemd/system
 
 install -m 0644 systemd/system-installer.service ${D}//lib/systemd/system
 install -m 0775 scripts/system-installer  ${D}//usr/sbin/system-installer
 install -m 0775 scripts/installer-conf-creator  ${D}//usr/sbin/installer-conf-creator
 
 
}

PACKAGES = ""
PACKAGES += "system-installer"

system-installer_files = ""
system-installer_files += "system-installer.manifest"
system-installer_files += "/usr/sbin/system-installer"
system-installer_files += "/usr/sbin/installer-conf-creator"
system-installer_files += "/lib/systemd/system/system-installer.service"

FILES_${PN} = "${system-installer_files}"

PKG_system-installer= "system-installer"

require system-installer-extraconf.inc
