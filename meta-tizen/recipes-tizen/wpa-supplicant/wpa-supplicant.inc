DESCRIPTION = "WPA supplicant implementation"
HOMEPAGE = "http://hostap.epitest.fi/wpa_supplicant/"
SECTION = "Network & Connectivity/Wireless"
LICENSE = "BSD-3-Clause and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wpa_supplicant-docs  
PROVIDES += "wpa_supplicant-docs "
RPROVIDES_wpa_supplicant-docs  += "wpa_supplicant-docs "

#PROVIDES by wpa_supplicant 
PROVIDES += "wpa_supplicant"
RPROVIDES_wpa_supplicant += "wpa_supplicant"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of wpa_supplicant 
DEPENDS += "systemd"
DEPENDS += "dbus-devel"
DEPENDS += "openssl"
DEPENDS += "readline"
DEPENDS += "libnl1"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n wpa_supplicant-2.0
 cp ${S}/packaging/wpa_supplicant.manifest .
 rm -rf wpa_supplicant-2.0/patches
 cp ${S}/packaging/config wpa_supplicant/.config
 
 
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
 
 cd wpa_supplicant
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 make V=1 BINDIR=/usr/sbin -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}//usr/sbin
 install -m 0755 wpa_supplicant/wpa_cli ${D}/usr/sbin
 install -m 0755 wpa_supplicant/wpa_passphrase ${D}/usr/sbin
 install -m 0755 wpa_supplicant/wpa_supplicant ${D}/usr/sbin
 install -d ${D}/etc/dbus-1/system.d
 install -m 0644 wpa_supplicant/dbus/dbus-wpa_supplicant.conf ${D}/etc/dbus-1/system.d/wpa_supplicant.conf
 install -d ${D}//etc/wpa_supplicant
 install -m 0644 ${S}/packaging/wpa_supplicant-p2p.conf ${D}/etc/wpa_supplicant/wpa_supplicant-p2p.conf
 install -d ${D}//usr/share/dbus-1/system-services
 install -m 0644 wpa_supplicant/dbus/fi.epitest.hostap.WPASupplicant.service ${D}//usr/share/dbus-1/system-services
 install -m 0644 wpa_supplicant/dbus/fi.w1.wpa_supplicant1.service ${D}//usr/share/dbus-1/system-services
 install -d ${D}//var/run/wpa_supplicant
 install -d ${D}/usr/share/man/man{5,8}
 install -m 0644 wpa_supplicant/doc/docbook/*.8 ${D}/usr/share/man/man8
 install -m 0644 wpa_supplicant/doc/docbook/*.5 ${D}/usr/share/man/man5
 
 # install systemd service file
 mkdir -p ${D}/lib/systemd/system
 install -m 0644 wpa_supplicant/systemd/wpa_supplicant.service ${D}/lib/systemd/system
 mkdir -p ${D}/lib/systemd/system/network.target.wants
 ln -s ../wpa_supplicant.service ${D}/lib/systemd/system/network.target.wants/wpa_supplicant.service
 
 
 
}

PACKAGES = ""
PACKAGES += "wpa_supplicant-docs"
PACKAGES += "wpa_supplicant"

wpa_supplicant-docs_files = ""
wpa_supplicant-docs_files += "/usr/share/info"
wpa_supplicant-docs_files += "/usr/share/man"

wpa_supplicant_files = ""
wpa_supplicant_files += "wpa_supplicant.manifest"
wpa_supplicant_files += "/usr/sbin/wpa_cli"
wpa_supplicant_files += "/usr/sbin/wpa_passphrase"
wpa_supplicant_files += "/usr/sbin/wpa_supplicant"
wpa_supplicant_files += "/etc/dbus-1/system.d/wpa_supplicant.conf"
wpa_supplicant_files += "/etc/wpa_supplicant/wpa_supplicant-p2p.conf"
wpa_supplicant_files += "/usr/share/dbus-1/system-services"
wpa_supplicant_files += "/var/run/wpa_supplicant"
wpa_supplicant_files += "/lib/systemd/system/wpa_supplicant.service"
wpa_supplicant_files += "/lib/systemd/system/network.target.wants/wpa_supplicant.service"

FILES_${PN}-docs = "${wpa_supplicant-docs_files}"
FILES_${PN} = "${wpa_supplicant_files}"

PKG_wpa_supplicant-docs= "wpa_supplicant-docs"
PKG_wpa_supplicant= "wpa_supplicant"

require wpa-supplicant-extraconf.inc
