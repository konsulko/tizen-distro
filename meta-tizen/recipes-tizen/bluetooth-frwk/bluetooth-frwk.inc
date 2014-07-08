DESCRIPTION = "Bluetooth framework for BlueZ and Obexd"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by bluetooth-frwk-core


#PROVIDES by bluetooth-frwk-dev


#PROVIDES by bluetooth-frwk-service


#PROVIDES by bluetooth-frwk


RDEPENDS = ""
#RDEPENDS of bluetooth-frwk-core (${PN}-core)
RDEPENDS_${PN}-core += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk-service (${PN}-service)
RDEPENDS_${PN}-service += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk (${PN})
RDEPENDS_${PN} += "bluetooth-tools"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "syspopup"
RDEPENDS_${PN} += "vconf"
RDEPENDS_${PN} += "eglibc"


DEPENDS = ""
#DEPENDS of bluetooth-frwk
DEPENDS += "status"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "tethering"
DEPENDS += "libxml2"
DEPENDS += "dbus"
DEPENDS += "syspopup"
DEPENDS += "tizen-platform-config"
DEPENDS += "aul"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "security-server"
DEPENDS += "notification"
DEPENDS += "alarm-manager"
DEPENDS += "libprivilege-control"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bluetooth-frwk.manifest .
 
 
 
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
 
 
 export CFLAGS+="   -Wall -g -fvisibility=hidden -fPIC"
 export LDFLAGS+=" -Wl,--rpath=${prefix}/lib -Wl,--as-needed -Wl,--unresolved-symbols=ignore-in-shared-libs"
 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         ${EXTRA_OECMAKE} . \
 -DTZ_SYS_USER_GROUP=users \
  -DLIBNOTIFY_SUPPORT=Off \
  -DLIBNOTIFICATION_SUPPORT=Off
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}${sysconfdir}/rc.d/rc3.d/
 mkdir -p ${D}${sysconfdir}/rc.d/rc5.d/
 ln -s ${sysconfdir}/rc.d/init.d/bluetooth-frwk-service ${D}${sysconfdir}/rc.d/rc3.d/S80bluetooth-frwk-service
 ln -s ${sysconfdir}/rc.d/init.d/bluetooth-frwk-service ${D}${sysconfdir}/rc.d/rc5.d/S80bluetooth-frwk-service
 
 mkdir -p ${D}/lib/systemd/user
 mkdir -p ${D}/lib/systemd/user/tizen-middleware.target.wants
 install -m 0644 bt-service/bluetooth-frwk-service.service ${D}/lib/systemd/user
 ln -s ../bluetooth-frwk-service.service ${D}/lib/systemd/user/tizen-middleware.target.wants/bluetooth-frwk-service.service
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    vconftool set -tf int db/bluetooth/status "0" -g 6520
    vconftool set -tf int file/private/bt-service/flight_mode_deactivated "0" -g 6520 -i
    vconftool set -tf string memory/bluetooth/sco_headset_name "" -g 6520 -i
    vconftool set -tf int memory/bluetooth/device "0" -g 6520 -i
    vconftool set -tf int memory/bluetooth/btsco "0" -g 6520 -i

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " bluetooth-frwk-dev "
PACKAGES += " bluetooth-frwk-core "
PACKAGES += " bluetooth-frwk-service "
PACKAGES += " bluetooth-frwk "

bluetooth-frwk-dev_files = ""
bluetooth-frwk-dev_files += "bluetooth-frwk.manifest"
bluetooth-frwk-dev_files += "${prefix}/include/bt-service/bluetooth-api.h"
bluetooth-frwk-dev_files += "${prefix}/include/bt-service/bluetooth-hid-api.h"
bluetooth-frwk-dev_files += "${prefix}/include/bt-service/bluetooth-audio-api.h"
bluetooth-frwk-dev_files += "${prefix}/include/bt-service/bluetooth-telephony-api.h"
bluetooth-frwk-dev_files += "${prefix}/include/bt-service/bluetooth-media-control.h"
bluetooth-frwk-dev_files += "${prefix}/lib/pkgconfig/bluetooth-api.pc"
bluetooth-frwk-dev_files += "${prefix}/lib/libbluetooth-api.so"

bluetooth-frwk-core_files = ""
bluetooth-frwk-core_files += "bluetooth-frwk.manifest"
bluetooth-frwk-core_files += "${prefix}/share/dbus-1/system-services/org.projectx.bt_core.service"
bluetooth-frwk-core_files += "${prefix}/bin/bt-core"
bluetooth-frwk-core_files += "${sysconfdir}/dbus-1/system.d/bluetooth-frwk-core.conf"

bluetooth-frwk-service_files = ""
bluetooth-frwk-service_files += "bluetooth-frwk.manifest"
bluetooth-frwk-service_files += "${prefix}/share/dbus-1/system-services/org.projectx.bt.service"
bluetooth-frwk-service_files += "${sysconfdir}/rc.d/init.d/bluetooth-frwk-service"
bluetooth-frwk-service_files += "${sysconfdir}/rc.d/rc3.d/S80bluetooth-frwk-service"
bluetooth-frwk-service_files += "${sysconfdir}/rc.d/rc5.d/S80bluetooth-frwk-service"
bluetooth-frwk-service_files += "${prefix}/bin/bt-service"
bluetooth-frwk-service_files += "/lib/systemd/user/tizen-middleware.target.wants/bluetooth-frwk-service.service"
bluetooth-frwk-service_files += "/lib/systemd/user/bluetooth-frwk-service.service"
bluetooth-frwk-service_files += "/opt/var/lib/bluetooth/auto-pair-blacklist"
bluetooth-frwk-service_files += "${sysconfdir}/dbus-1/system.d/bluetooth-frwk-service.conf"

bluetooth-frwk_files = ""
bluetooth-frwk_files += "bluetooth-frwk.manifest"
bluetooth-frwk_files += "${prefix}/lib/libbluetooth-api.so.*"

FILES_${PN}-dev = "${bluetooth-frwk-dev_files}"
FILES_${PN}-core = "${bluetooth-frwk-core_files}"
FILES_${PN}-service = "${bluetooth-frwk-service_files}"
FILES_${PN} = "${bluetooth-frwk_files}"

PKG_bluetooth-frwk-dev= "bluetooth-frwk-dev"
PKG_bluetooth-frwk-core= "bluetooth-frwk-core"
PKG_bluetooth-frwk-service= "bluetooth-frwk-service"
PKG_bluetooth-frwk= "bluetooth-frwk"

require bluetooth-frwk-extraconf.inc

