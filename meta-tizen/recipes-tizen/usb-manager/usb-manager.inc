DESCRIPTION = "USB server"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework/system"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by usb-server 
PROVIDES += "usb-server"
RPROVIDES_usb-server += "usb-server"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of usb-server 
DEPENDS += "systemd"
DEPENDS += "app-svc"
DEPENDS += "cmake"
DEPENDS += "attr"
DEPENDS += "pkgconfig(capi-system-usb-accessory)"
DEPENDS += "dlog"
DEPENDS += "notification"
DEPENDS += "syspopup"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "app-core"
DEPENDS += "system-server"
DEPENDS += "pkgconfig(libusb-1.0)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(edbus)"
DEPENDS += "ecore"
DEPENDS += "devman"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 cmake . -DCMAKE_INSTALL_PREFIX=/usr -DSIMULATOR=no
 
 
 
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
 
 cp ${S}/packaging/usb-server.manifest .
 cp ${S}/packaging/usb-server.rule .
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "usb-server"

usb-server_files = ""
usb-server_files += "usb-server.manifest"
usb-server_files += "/usr/bin/start_dr.sh"
usb-server_files += "/usr/bin/usb-server"
usb-server_files += "/usr/bin/direct_set_debug.sh"
usb-server_files += "/usr/bin/set_usb_debug.sh"

FILES_${PN} = "${usb-server_files}"

PKG_usb-server= "usb-server"

require usb-manager-extraconf.inc
