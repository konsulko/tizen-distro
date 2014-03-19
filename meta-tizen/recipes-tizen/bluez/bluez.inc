DESCRIPTION = "Bluetooth Stack for Linux"
HOMEPAGE = "http://www.bluez.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bluez-docs  
PROVIDES += "bluez-docs "
RPROVIDES_bluez-docs  += "bluez-docs "

#PROVIDES by bluez-devel 
PROVIDES += "bluez-devel"
RPROVIDES_bluez-devel += "bluez-devel"
RPROVIDES_bluez-devel += "bluez-dev"

#PROVIDES by obexd 
PROVIDES += "obexd"
RPROVIDES_obexd += "obexd"

#PROVIDES by bluez 
PROVIDES += "bluez"
RPROVIDES_bluez += "bluez"

#PROVIDES by bluez-test 
PROVIDES += "bluez-test"
RPROVIDES_bluez-test += "bluez-test"

#PROVIDES by libbluetooth 
PROVIDES += "libbluetooth"
RPROVIDES_libbluetooth += "libbluetooth"

#PROVIDES by bluez-cups 
PROVIDES += "bluez-cups"
RPROVIDES_bluez-cups += "bluez-cups"

RDEPENDS = ""
#RDEPENDS of bluez-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libbluetooth"

#RDEPENDS of obexd (obexd)
RDEPENDS_obexd += "tizen-platform-config-tools"

#RDEPENDS of bluez (${PN})
RDEPENDS_${PN} += "systemd"

#RDEPENDS of bluez-test (${PN}-test)
RDEPENDS_${PN}-test += "libbluetooth"
RDEPENDS_${PN}-test += "dbus-python"
RDEPENDS_${PN}-test += "python-gobject"

#RDEPENDS of bluez-cups (${PN}-cups)
RDEPENDS_${PN}-cups += "libbluetooth"


DEPENDS = ""
#DEPENDS of bluez 
DEPENDS += "flex"
DEPENDS += "systemd"
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "pkgconfig-native"
DEPENDS += "check-devel"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(libnl-1)"
DEPENDS += "libsndfile-devel"
DEPENDS += "udev"
DEPENDS += "automake-native"
DEPENDS += "libcap-ng-devel"
DEPENDS += "libtool-cross"
DEPENDS += "libusb-devel"
DEPENDS += "libudev-devel"
DEPENDS += "glib2-devel"
DEPENDS += "libical-devel"
DEPENDS += "readline-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bluez.manifest .
 
 
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
 
 autoreconf -fiv
 
 export CFLAGS="${CFLAGS} -D__TIZEN_PATCH__"
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info  --with-pic \
             --libexecdir=/lib \
             --disable-usb	\
             --enable-test	\
             --enable-library	\
             --enable-experimental	\
             --enable-readline	\
             --with-systemdunitdir=/lib/systemd/system	\
             --enable-capng
 make -j16 all V=1
 
 exit 0
 make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 rm -rvf $RPM_BUILD_ROOT//usr/lib/gstreamer-*
 install --mode=0755 -D ${S}/packaging/bluetooth.sh $RPM_BUILD_ROOT/usr/lib/udev/bluetooth.sh
 install --mode=0644 -D ${S}/packaging/bluetooth.modprobe $RPM_BUILD_ROOT//etc/modprobe.d/50-bluetooth.conf
 if ! test -e ${D}/usr/lib/cups/backend/bluetooth
 then if test -e ${D}/usr/lib/cups/backend/bluetooth
      then mkdir -p ${D}/usr/lib/cups/backend
           mv ${D}/usr/lib/cups/backend/bluetooth ${D}/usr/lib/cups/backend/bluetooth
      fi
 fi
 # no idea why this is suddenly necessary...
 install --mode 0755 -d $RPM_BUILD_ROOT/var/lib/bluetooth
 
 install -D -m 0755 ${S}/packaging/obex-root-setup ${D}/usr/bin/obex-root-setup
 install -D -m 0755 ${S}/packaging/create-symlinks ${D}/etc/obex/root-setup.d/000_create-symlinks
 install -D -m 0755 tools/btiotest $RPM_BUILD_ROOT//usr/bin/
 install -D -m 0755 tools/bluetooth-player $RPM_BUILD_ROOT//usr/bin/
 install -D -m 0755 tools/mpris-player $RPM_BUILD_ROOT//usr/bin/
 install -D -m 0755 tools/btmgmt $RPM_BUILD_ROOT//usr/bin/
 install -D -m 0755 tools/scotest $RPM_BUILD_ROOT//usr/bin/
 
 install -D -m 0755 tools/obexctl ${D}/usr/bin/obexctl
 
 
}

PACKAGES = ""
PACKAGES += "obexd"
PACKAGES += "bluez-docs"
PACKAGES += "bluez"
PACKAGES += "bluez-test"
PACKAGES += "libbluetooth"
PACKAGES += "bluez-devel"
PACKAGES += "bluez-cups"

obexd_files = ""
obexd_files += "/lib/bluetooth/obexd"
obexd_files += "/lib/systemd/user/obex.service"
obexd_files += "/usr/share/dbus-1/services/org.bluez.obex.service"
obexd_files += "/etc/obex/root-setup.d/000_create-symlinks"
obexd_files += "/usr/bin/obex-root-setup"

bluez-docs_files = ""
bluez-docs_files += "/usr/share/info"
bluez-docs_files += "/usr/share/man"

bluez_files = ""
bluez_files += "bluez.manifest"
bluez_files += "/usr/bin/hcitool"
bluez_files += "/usr/bin/l2ping"
bluez_files += "/usr/bin/obexctl"
bluez_files += "/usr/bin/rfcomm"
bluez_files += "/usr/bin/sdptool"
bluez_files += "/usr/bin/ciptool"
bluez_files += "/usr/bin/hciattach"
bluez_files += "/usr/bin/hciconfig"
bluez_files += "/lib/bluetooth/bluetoothd"
bluez_files += "/usr/bin/bccmd"
bluez_files += "/usr/lib/udev"
bluez_files += "/usr/lib/udev/*"
bluez_files += "/usr/share/dbus-1/system-services/org.bluez.service"
bluez_files += "/etc/dbus-1/system.d/bluetooth.conf"
bluez_files += "/var/lib/bluetooth"
bluez_files += "/etc/modprobe.d"
bluez_files += "/etc/modprobe.d/50-bluetooth.conf"
bluez_files += "/lib/systemd/system/bluetooth.service"

bluez-test_files = ""
bluez-test_files += "bluez.manifest"
bluez-test_files += "/usr/lib/bluez/test/*"
bluez-test_files += "/usr/bin/l2test"
bluez-test_files += "/usr/bin/rctest"
bluez-test_files += "/usr/bin/bluetoothctl"
bluez-test_files += "/usr/bin/btiotest"
bluez-test_files += "/usr/bin/mpris-player"
bluez-test_files += "/usr/bin/bluetooth-player"
bluez-test_files += "/usr/bin/btmon"
bluez-test_files += "/usr/bin/hcidump"
bluez-test_files += "/usr/bin/btmgmt"
bluez-test_files += "/usr/bin/scotest"

libbluetooth_files = ""
libbluetooth_files += "bluez.manifest"
libbluetooth_files += "/usr/lib/libbluetooth.so.*"

bluez-devel_files = ""
bluez-devel_files += "bluez.manifest"
bluez-devel_files += "/usr/include/bluetooth"
bluez-devel_files += "/usr/lib/libbluetooth.so"
bluez-devel_files += "/usr/lib/pkgconfig/bluez.pc"

bluez-cups_files = ""
bluez-cups_files += "bluez.manifest"
bluez-cups_files += "/usr/lib/cups"
bluez-cups_files += "/usr/lib/cups/backend"
bluez-cups_files += "/usr/lib/cups/backend/bluetooth"

FILES_obexd = "${obexd_files}"
FILES_${PN}-docs = "${bluez-docs_files}"
FILES_${PN} = "${bluez_files}"
FILES_${PN}-test = "${bluez-test_files}"
FILES_libbluetooth = "${libbluetooth_files}"
FILES_${PN}-devel = "${bluez-devel_files}"
FILES_${PN}-cups = "${bluez-cups_files}"

PKG_obexd= "obexd"
PKG_bluez-docs= "bluez-docs"
PKG_bluez= "bluez"
PKG_bluez-test= "bluez-test"
PKG_libbluetooth= "libbluetooth"
PKG_bluez-devel= "bluez-devel"
PKG_bluez-cups= "bluez-cups"

require bluez-extraconf.inc
