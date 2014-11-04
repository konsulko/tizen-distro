DESCRIPTION = "System server"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "Apache-2.0"
PV = "2.0.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libdevman-dev
PROVIDES += "libdevman-dev"


#PROVIDES by libdeviced-dev
PROVIDES += "libdeviced-dev"


#PROVIDES by libdeviced
PROVIDES += "libdeviced"


#PROVIDES by sysman-dev
PROVIDES += "sysman-dev"


#PROVIDES by libhaptic
PROVIDES += "libhaptic"


#PROVIDES by libslp-pm-dev
PROVIDES += "libslp-pm-dev"


#PROVIDES by libslp-pm
PROVIDES += "libslp-pm"


#PROVIDES by system-server


#PROVIDES by sysman-internal-dev
PROVIDES += "sysman-internal-dev"


#PROVIDES by libhaptic-dev
PROVIDES += "libhaptic-dev"


#PROVIDES by libhaptic-plugin-dev
PROVIDES += "libhaptic-plugin-dev"


#PROVIDES by libdevman-haptic-dev
PROVIDES += "libdevman-haptic-dev"


#PROVIDES by sysman
PROVIDES += "sysman"


#PROVIDES by libdevman
PROVIDES += "libdevman"


RDEPENDS = ""
#RDEPENDS of libdevman-dev (libdevman-dev)
RDEPENDS_libdevman-dev += "libdevman"

#RDEPENDS of libhaptic (libhaptic)
RDEPENDS_libhaptic += "system-server"

#RDEPENDS of system-server (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "vconf"

#RDEPENDS of libdeviced (libdeviced)
RDEPENDS_libdeviced += "system-server"

#RDEPENDS of sysman-dev (sysman-dev)
RDEPENDS_sysman-dev += "sysman"

#RDEPENDS of libslp-pm-dev (libslp-pm-dev)
RDEPENDS_libslp-pm-dev += "libslp-pm"

#RDEPENDS of libslp-pm (libslp-pm)
RDEPENDS_libslp-pm += "system-server"

#RDEPENDS of libdeviced-dev (libdeviced-dev)
RDEPENDS_libdeviced-dev += "libdeviced"

#RDEPENDS of sysman-internal-dev (sysman-internal-dev)
RDEPENDS_sysman-internal-dev += "sysman"

#RDEPENDS of libhaptic-dev (libhaptic-dev)
RDEPENDS_libhaptic-dev += "libhaptic"

#RDEPENDS of libhaptic-plugin-dev (libhaptic-plugin-dev)
RDEPENDS_libhaptic-plugin-dev += "libhaptic"

#RDEPENDS of libdevman-haptic-dev (libdevman-haptic-dev)
RDEPENDS_libdevman-haptic-dev += "libdevman-dev"

#RDEPENDS of sysman (sysman)
RDEPENDS_sysman += "system-server"

#RDEPENDS of libdevman (libdevman)
RDEPENDS_libdevman += "system-server"


DEPENDS = ""
#DEPENDS of system-server
DEPENDS += "smack"
DEPENDS += "edbus"
inherit tizen_cmake
DEPENDS += "attr"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "notification"
DEPENDS += "tizen-platform-config"
DEPENDS += "syspopup"
inherit pkgconfig
DEPENDS += "libtapi"
DEPENDS += "usbutils"
DEPENDS += "libdevice-node"
DEPENDS += "systemd"
DEPENDS += "dlog"
DEPENDS += "heynoti"
DEPENDS += "ecore"
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"
DEPENDS += "sensor"
DEPENDS += "vconf"
DEPENDS += "capi-base-common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/system-server.manifest .
 cp ${S}/packaging/deviced.manifest .
 cp ${S}/packaging/sysman.manifest .
 cp ${S}/packaging/libslp-pm.manifest .
 cp ${S}/packaging/haptic.manifest .
 cp ${S}/packaging/devman.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         ${EXTRA_OECMAKE} . \
        -DTZ_SYS_ETC=${sysconfdir} \
        -DSYSTEMD_DIR=${systemd_unitdir}/system
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 mkdir -p ${D}/${systemd_unitdir}/system/multi-user.target.wants 
 ln -s ../system-server.service  ${D}/${systemd_unitdir}/system/multi-user.target.wants/system-server.service  
 
 mkdir -p ${D}/${systemd_unitdir}/system/sockets.target.wants 
 ln -s ../system-server.socket  ${D}/${systemd_unitdir}/system/sockets.target.wants/system-server.socket  
 
 
 mkdir -p ${D}/${systemd_unitdir}/system/graphical.target.wants 
 ln -s ../regpmon.service  ${D}/${systemd_unitdir}/system/graphical.target.wants/regpmon.service  
 install -m 0644 ${S}/packaging/regpmon.service ${D}${systemd_unitdir}/system/regpmon.service
 
 
 mkdir -p ${D}/${systemd_unitdir}/system/graphical.target.wants 
 ln -s ../zbooting-done.service  ${D}/${systemd_unitdir}/system/graphical.target.wants/zbooting-done.service  
 install -m 0644 ${S}/packaging/zbooting-done.service ${D}${systemd_unitdir}/system/zbooting-done.service
 
 
 #fdupes ${D}
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    #memory type vconf key init
    users_gid=$(getent group $TZ_SYS_USER_GROUP | cut -f3 -d':')
    vconftool set -t int memory/sysman/usbhost_status -1 -i
    vconftool set -t int memory/sysman/mmc 0 -i
    vconftool set -t int memory/sysman/earjack_key 0 -i
    vconftool set -t int memory/sysman/added_usb_storage 0 -i
    vconftool set -t int memory/sysman/removed_usb_storage 0 -i
    vconftool set -t int memory/sysman/charger_status -1 -i
    vconftool set -t int memory/sysman/charge_now -1 -i
    vconftool set -t int memory/sysman/battery_status_low -1 -i
    vconftool set -t int memory/sysman/battery_capacity -1 -i
    vconftool set -t int memory/sysman/usb_status -1 -i
    vconftool set -t int memory/sysman/earjack -1 -i
    vconftool set -t int memory/sysman/low_memory 1 -i
    vconftool set -t int memory/sysman/sliding_keyboard -1 -i
    vconftool set -t int memory/sysman/mmc_mount -1 -i
    vconftool set -t int memory/sysman/mmc_unmount -1 -i
    vconftool set -t int memory/sysman/mmc_format -1 -i
    vconftool set -t int memory/sysman/mmc_format_progress 0 -i
    vconftool set -t int memory/sysman/mmc_err_status 0 -i
    vconftool set -t int memory/sysman/power_off 0 -g $users_gid -i -f
    vconftool set -t int memory/sysman/battery_level_status -1 -i
    vconftool set -t string memory/private/sysman/added_storage_uevent "" -i
    vconftool set -t string memory/private/sysman/removed_storage_uevent "" -g $users_gid -i
    vconftool set -t int memory/sysman/hdmi 0 -i
    vconftool set -t int memory/sysman/stime_changed 0 -i
    #db type vconf key init
    vconftool set -t int db/sysman/mmc_dev_changed 0 -i
    vconftool set -t int memory/pm/state 0 -i -g $users_gid
    vconftool set -t int memory/pm/battery_timetofull -1 -i
    vconftool set -t int memory/pm/battery_timetoempty -1 -i
    vconftool set -t int memory/pm/sip_status 0 -i -g $users_gid
    vconftool set -t int memory/pm/custom_brightness_status 0 -i -g $users_gid
    vconftool set -t bool memory/pm/brt_changed_lpm 0 -i
    vconftool set -t int memory/pm/current_brt 60 -i -g $users_gid
    heynotitool set system_wakeup
    heynotitool set pm_event
    heynotitool set power_off_start
    heynotitool set mmcblk_add
    heynotitool set mmcblk_remove
    heynotitool set device_charge_chgdet
    heynotitool set device_usb_host_add
    heynotitool set device_usb_host_remove
    heynotitool set device_pci_keyboard_add
    heynotitool set device_pci_keyboard_remove
    heynotitool set device_usb_chgdet
    heynotitool set device_ta_chgdet
    heynotitool set device_earjack_chgdet
    heynotitool set device_earkey_chgdet
    heynotitool set device_tvout_chgdet
    heynotitool set device_hdmi_chgdet
    heynotitool set device_keyboard_chgdet
    systemctl daemon-reload
    if [ "$1" = "1" ]; then
        systemctl restart system-server.service
        systemctl restart regpmon.service
        systemctl restart zbooting-done.service
    fi
    [ "x$D" == "x" ] && ldconfig

}

pkg_postinst_libslp-pm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libhaptic() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_sysman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libdevman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libdeviced() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    if [ "$1" = "0" ]; then
        systemctl stop system-server.service
        systemctl stop regpmon.service
        systemctl stop zbooting-done.service
    fi

}

pkg_postrm_libhaptic() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    systemctl daemon-reload
    [ "x$D" == "x" ] && ldconfig

}

pkg_postrm_libslp-pm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libdeviced() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libdevman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_sysman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libdevman-dev "
PACKAGES += " libhaptic "
PACKAGES += " sysman-dev "
PACKAGES += " libdeviced-dev "
PACKAGES += " libslp-pm-dev "
PACKAGES += " libdevman "
PACKAGES += " libslp-pm "
PACKAGES += " system-server "
PACKAGES += " sysman-internal-dev "
PACKAGES += " libhaptic-dev "
PACKAGES += " libhaptic-plugin-dev "
PACKAGES += " libdevman-haptic-dev "
PACKAGES += " libdeviced "
PACKAGES += " sysman "

libdevman-dev_files = ""
libdevman-dev_files += "${prefix}/include/devman/devman.h"
libdevman-dev_files += "${prefix}/include/devman/devman_image.h"
libdevman-dev_files += "${prefix}/include/devman/devman_managed.h"
libdevman-dev_files += "${prefix}/include/devman/devman_haptic.h"
libdevman-dev_files += "${prefix}/include/devman/devman_PG.h"
libdevman-dev_files += "${prefix}/lib/pkgconfig/devman.pc"
libdevman-dev_files += "${prefix}/lib/libdevman.so"

libhaptic_files = ""
libhaptic_files += "${prefix}/lib/libhaptic.so.*"
MANIFESTFILES_libhaptic = "haptic.manifest"

sysman-dev_files = ""
sysman-dev_files += "${prefix}/include/sysman/sysman.h"
sysman-dev_files += "${prefix}/include/sysman/sysman_managed.h"
sysman-dev_files += "${prefix}/include/sysman/sysman_PG.h"
sysman-dev_files += "${prefix}/lib/pkgconfig/sysman.pc"
sysman-dev_files += "${prefix}/lib/libsysman.so"

libdeviced-dev_files = ""
libdeviced-dev_files += "${prefix}/include/deviced/dd-battery.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-control.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-deviced.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-deviced-managed.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-display.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-haptic.h"
libdeviced-dev_files += "${prefix}/include/deviced/dd-led.h"
libdeviced-dev_files += "${prefix}/include/deviced/haptic-module.h"
libdeviced-dev_files += "${prefix}/include/deviced/haptic-plugin-intf.h"
libdeviced-dev_files += "${prefix}/lib/libdeviced.so"
libdeviced-dev_files += "${prefix}/lib/pkgconfig/deviced.pc"

libslp-pm-dev_files = ""
libslp-pm-dev_files += "${prefix}/include/pmapi/pmapi.h"
libslp-pm-dev_files += "${prefix}/include/pmapi/pmapi_managed.h"
libslp-pm-dev_files += "${prefix}/include/pmapi/pm_PG.h"
libslp-pm-dev_files += "${prefix}/lib/pkgconfig/pmapi.pc"
libslp-pm-dev_files += "${prefix}/lib/libpmapi.so"

libdevman_files = ""
libdevman_files += "${prefix}/bin/display_wd"
libdevman_files += "${prefix}/lib/libdevman.so.*"
MANIFESTFILES_libdevman = "devman.manifest"

libslp-pm_files = ""
libslp-pm_files += "${prefix}/lib/libpmapi.so.*"
MANIFESTFILES_libslp-pm = "libslp-pm.manifest"

system-server_files = ""
system-server_files += "${sysconfdir}/dbus-1/system.d/deviced.conf"
system-server_files += "${prefix}/bin/system_server"
system-server_files += "${prefix}/lib/system-server/shutdown.sh"
system-server_files += "${prefix}/bin/restart"
system-server_files += "${prefix}/bin/movi_format.sh"
system-server_files += "${prefix}/bin/sys_event"
system-server_files += "${prefix}/bin/pm_event"
system-server_files += "${prefix}/bin/regpmon"
system-server_files += "${prefix}/bin/set_pmon"
system-server_files += "${prefix}/bin/sys_pci_noti"
system-server_files += "${prefix}/bin/mmc-smack-label"
system-server_files += "${prefix}/bin/device-daemon"
system-server_files += "${prefix}/bin/fsck_msdosfs"
system-server_files += "${systemd_unitdir}/system/multi-user.target.wants/system-server.service"
system-server_files += "${systemd_unitdir}/system/graphical.target.wants/regpmon.service"
system-server_files += "${systemd_unitdir}/system/sockets.target.wants/system-server.socket"
system-server_files += "${systemd_unitdir}/system/system-server.service"
system-server_files += "${systemd_unitdir}/system/system-server.socket"
system-server_files += "${systemd_unitdir}/system/regpmon.service"
system-server_files += "${systemd_unitdir}/system/graphical.target.wants/zbooting-done.service"
system-server_files += "${systemd_unitdir}/system/zbooting-done.service"
system-server_files += "${prefix}/share/system-server/sys_pci_noti/res/locale/*/LC_MESSAGES/*.mo"
system-server_files += "${prefix}/share/license/fsck_msdosfs"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/dbus-1/system.d/deviced.conf"
MANIFESTFILES_${PN} = "system-server.manifest"

sysman-internal-dev_files = ""
sysman-internal-dev_files += "${prefix}/include/sysman/sysman-internal.h"

libhaptic-dev_files = ""
libhaptic-dev_files += "${prefix}/include/haptic/haptic.h"
libhaptic-dev_files += "${prefix}/lib/libhaptic.so"
libhaptic-dev_files += "${prefix}/lib/pkgconfig/haptic.pc"

libhaptic-plugin-dev_files = ""
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_module.h"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_plugin_intf.h"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_PG.h"
libhaptic-plugin-dev_files += "${prefix}/lib/pkgconfig/haptic-plugin.pc"

libdevman-haptic-dev_files = ""
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext.h"
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext_core.h"
libdevman-haptic-dev_files += "${prefix}/lib/pkgconfig/devman_haptic.pc"

libdeviced_files = ""
libdeviced_files += "${prefix}/lib/libdeviced.so.*"
MANIFESTFILES_libdeviced = "deviced.manifest"

sysman_files = ""
sysman_files += "${prefix}/lib/libsysman.so.*"
MANIFESTFILES_sysman = "sysman.manifest"

FILES_libdevman-dev = "${libdevman-dev_files}"
FILES_libhaptic = "${libhaptic_files}"
FILES_sysman-dev = "${sysman-dev_files}"
FILES_libdeviced-dev = "${libdeviced-dev_files}"
FILES_libslp-pm-dev = "${libslp-pm-dev_files}"
FILES_libdevman = "${libdevman_files}"
FILES_libslp-pm = "${libslp-pm_files}"
FILES_${PN} = "${system-server_files}"
FILES_sysman-internal-dev = "${sysman-internal-dev_files}"
FILES_libhaptic-dev = "${libhaptic-dev_files}"
FILES_libhaptic-plugin-dev = "${libhaptic-plugin-dev_files}"
FILES_libdevman-haptic-dev = "${libdevman-haptic-dev_files}"
FILES_libdeviced = "${libdeviced_files}"
FILES_sysman = "${sysman_files}"

PKG_libdevman-dev= "libdevman-dev"
PKG_libhaptic= "libhaptic"
PKG_sysman-dev= "sysman-dev"
PKG_libdeviced-dev= "libdeviced-dev"
PKG_libslp-pm-dev= "libslp-pm-dev"
PKG_libdevman= "libdevman"
PKG_libslp-pm= "libslp-pm"
PKG_system-server= "system-server"
PKG_sysman-internal-dev= "sysman-internal-dev"
PKG_libhaptic-dev= "libhaptic-dev"
PKG_libhaptic-plugin-dev= "libhaptic-plugin-dev"
PKG_libdevman-haptic-dev= "libdevman-haptic-dev"
PKG_libdeviced= "libdeviced"
PKG_sysman= "sysman"

require system-server-extraconf.inc

