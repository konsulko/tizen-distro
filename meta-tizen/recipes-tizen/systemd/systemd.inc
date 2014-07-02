DESCRIPTION = "A System and Service Manager"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/systemd"
SECTION = "Base/Startup"
LICENSE = "LGPL-2.0+ and MIT and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libsystemd


#PROVIDES by systemd
# the PROVIDES rules is ignore "SysVinit = 2.86-24"
PROVIDES += "SysVinit"
RPROVIDES_systemd += "SysVinit"
# the PROVIDES rules is ignore "sysvinit = 2.86-24"
PROVIDES += "sysvinit"
RPROVIDES_systemd += "sysvinit"
# the PROVIDES rules is ignore "/bin/systemctl  "
PROVIDES += "/bin/systemctl"
RPROVIDES_systemd += "/bin/systemctl"
# the PROVIDES rules is ignore "/sbin/shutdown  "
PROVIDES += "/sbin/shutdown"
RPROVIDES_systemd += "/sbin/shutdown"
# the PROVIDES rules is ignore "udev = 208"
PROVIDES += "udev"
RPROVIDES_systemd += "udev"


#PROVIDES by libgudev-dev


#PROVIDES by systemd-dev
# the PROVIDES rules is ignore "libudev-dev = 208"
PROVIDES += "libudev-dev"
RPROVIDES_systemd-dev += "libudev-dev"


#PROVIDES by libgudev


#PROVIDES by systemd-analyze


RDEPENDS = ""
#RDEPENDS of systemd (${PN})
RDEPENDS_${PN} += "hwdata"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "gawk"
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "eglibc"
RDEPENDS_${PN} += "shadow"

#RDEPENDS of libgudev-dev (libgudev-dev)
RDEPENDS_libgudev-dev += "libgudev"

#RDEPENDS of systemd-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "systemd"

#RDEPENDS of libgudev (libgudev)
RDEPENDS_libgudev += "systemd"

#RDEPENDS of systemd-analyze (${PN}-analyze)
RDEPENDS_${PN}-analyze += "systemd"


DEPENDS = ""
#DEPENDS of systemd
DEPENDS += "kmod"
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
DEPENDS += "attr"
DEPENDS += "gperf"
DEPENDS += "hwdata"
DEPENDS += "dbus"
DEPENDS += "usbutils"
DEPENDS_append_class-native = " pkgconfig-native"
DEPENDS_append_class-target = " pkgconfig-native"
DEPENDS += "acl"
DEPENDS += "xz"
DEPENDS += "glib-2.0"
DEPENDS += "libxslt"
DEPENDS += "pciutils"
DEPENDS += "libcap"
DEPENDS += "util-linux"
DEPENDS += "libgcrypt"
DEPENDS += "libpam"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/systemd.manifest .
 
 
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
 
 
   
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=${TARGET_SYS} \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir}
 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=${TARGET_SYS} \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} \
         --enable-bootchart \
         --libexecdir=${prefix}/lib \
         --docdir=${prefix}/share/doc/packages/systemd \
         --disable-static \
         --with-sysvinit-path= \
         --with-sysvrcnd-path= \
         --with-smack-run-label=System
 make -j16 \
         systemunitdir=/lib/systemd/system \
         userunitdir=/lib/systemd/user
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
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
 
 # udev links
 ${prefix}/bin/mkdir -p ${D}/${prefix}/sbin
 ${prefix}/bin/ln -sf ../bin/udevadm ${D}${prefix}/sbin/udevadm
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/firmware/updates
 
 # Create SysV compatibility symlinks. systemctl/systemd are smart
 # enough to detect in which way they are called.
 ${prefix}/bin/ln -s ../lib/systemd/systemd ${D}${prefix}/sbin/init
 ${prefix}/bin/ln -s ../lib/systemd/systemd ${D}${prefix}/bin/systemd
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/reboot
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/halt
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/poweroff
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/shutdown
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/telinit
 ${prefix}/bin/ln -s ../bin/systemctl ${D}${prefix}/sbin/runlevel
 
 # legacy links
 ${prefix}/bin/ln -s loginctl ${D}${prefix}/bin/systemd-loginctl
 
 # We create all wants links manually at installation time to make sure
 # they are not owned and hence overriden by rpm after the used deleted
 # them.
 ${prefix}/bin/rm -r ${D}${sysconfdir}/systemd/system/*.target.wants
 
 # Make sure the ghost-ing below works
 ${prefix}/bin/touch ${D}${sysconfdir}/systemd/system/runlevel2.target
 ${prefix}/bin/touch ${D}${sysconfdir}/systemd/system/runlevel3.target
 ${prefix}/bin/touch ${D}${sysconfdir}/systemd/system/runlevel4.target
 ${prefix}/bin/touch ${D}${sysconfdir}/systemd/system/runlevel5.target
 
 # Make sure these directories are properly owned
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system/basic.target.wants
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system/default.target.wants
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system/dbus.target.wants
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system/syslog.target.wants
 
 # Make sure the user generators dir exists too
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system-generators
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/user-generators
 
 # Create new-style configuration files so that we can ghost-own them
 ${prefix}/bin/touch ${D}${sysconfdir}/hostname
 ${prefix}/bin/touch ${D}${sysconfdir}/vconsole.conf
 ${prefix}/bin/touch ${D}${sysconfdir}/locale.conf
 ${prefix}/bin/touch ${D}${sysconfdir}/machine-id
 ${prefix}/bin/touch ${D}${sysconfdir}/machine-info
 ${prefix}/bin/touch ${D}${sysconfdir}/timezone
 #${prefix}/bin/mkdir -p ${D}${sysconfdir}/X11/xorg.conf.d
 #${prefix}/bin/touch ${D}${sysconfdir}/X11/xorg.conf.d/00-keyboard.conf
 
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system-preset/
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/user-preset/
 
 # Make sure the shutdown/sleep drop-in dirs exist
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system-shutdown/
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/system-sleep/
 
 # Make sure the NTP units dir exists
 ${prefix}/bin/mkdir -p ${D}${prefix}/lib/systemd/ntp-units.d/
 
 # Install modprobe fragment
 ${prefix}/bin/mkdir -p ${D}${sysconfdir}/modprobe.d/
 
 # Enable readahead services
 ${prefix}/bin/ln -s ../systemd-readahead-collect.service ${D}${prefix}/lib/systemd/system/default.target.wants/
 ${prefix}/bin/ln -s ../systemd-readahead-replay.service ${D}${prefix}/lib/systemd/system/default.target.wants/
 
 # Fix the dangling /var/lock -> /run/lock symlink
 install -Dm644 tmpfiles.d/legacy.conf ${D}${prefix}/lib/tmpfiles.d/legacy.conf
 
 install -m644 ${S}/packaging/pamconsole-tmp.conf ${D}${prefix}/lib/tmpfiles.d/
 
 rm -rf ${D}/${prefix}/lib/systemd/user/default.target
 
 rm -rf ${D}/${prefix}/share/doc/packages/systemd
 
 # Move macros to the proper location for Tizen
 mkdir -p ${D}${sysconfdir}/rpm
 install -m644 src/core/macros.systemd ${D}${sysconfdir}/rpm/macros.systemd
 rm -f ${D}${prefix}/lib/rpm/macros.d/macros.systemd
 
 
}

pkg_preinst_${PN}() {
    #!/bin/sh -e

    ${D}${prefix}/bin/getent group cdrom >/dev/null 2>&1 || ${D}${prefix}/sbin/groupadd -r -g 11 cdrom >/dev/null 2>&1 || :
    ${D}${prefix}/bin/getent group tape >/dev/null 2>&1 || ${D}${prefix}/sbin/groupadd -r -g 33 tape >/dev/null 2>&1 || :
    ${D}${prefix}/bin/getent group dialout >/dev/null 2>&1 || ${D}${prefix}/sbin/groupadd -r -g 18 dialout >/dev/null 2>&1 || :
    ${D}${prefix}/bin/getent group floppy >/dev/null 2>&1 || ${D}${prefix}/sbin/groupadd -r -g 19 floppy >/dev/null 2>&1 || :
    ${D}${prefix}/bin/systemctl stop systemd-udevd-control.socket systemd-udevd-kernel.socket systemd-udevd.service >/dev/null 2>&1 || :
    # Rename configuration files that changed their names
    ${D}${prefix}/bin/mv -n ${sysconfdir}/systemd/systemd-logind.conf ${sysconfdir}/systemd/logind.conf >/dev/null 2>&1 || :
    ${D}${prefix}/bin/mv -n ${sysconfdir}/systemd/systemd-journald.conf ${sysconfdir}/systemd/journald.conf >/dev/null 2>&1 || :

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ${D}${prefix}/bin/systemd-machine-id-setup > /dev/null 2>&1 || :
    ${D}${prefix}/lib/systemd/systemd-random-seed save > /dev/null 2>&1 || :
    ${D}${prefix}/bin/systemctl daemon-reexec > /dev/null 2>&1 || :
    ${D}${prefix}/bin/systemctl start systemd-udevd.service >/dev/null 2>&1 || :

}

pkg_postinst_libgudev() {
    #!/bin/sh -e

    ldconfig
}

pkg_postinst_libsystemd() {
    #!/bin/sh -e

    ldconfig
}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    if [ $1 -eq 0 ] ; then
            ${D}${prefix}/bin/systemctl disable \
                    getty@.service \
                    remote-fs.target \
                    systemd-readahead-replay.service \
                    systemd-readahead-collect.service >/dev/null 2>&1 || :
            ${D}${prefix}/bin/rm -f ${sysconfdir}/systemd/system/default.target >/dev/null 2>&1 || :
    fi

}

pkg_postrm_libgudev() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_libsystemd() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ $1 -ge 1 ] ; then
            ${D}${prefix}/bin/systemctl daemon-reload > /dev/null 2>&1 || :
            ${D}${prefix}/bin/systemctl try-restart systemd-logind.service >/dev/null 2>&1 || :
    fi

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libsystemd "
PACKAGES += " systemd "
PACKAGES += " libgudev-dev "
PACKAGES += " systemd-dev "
PACKAGES += " libgudev "
PACKAGES += " systemd-analyze "

libsystemd_files = ""
libsystemd_files += "systemd.manifest"
libsystemd_files += "${prefix}/lib/security/pam_systemd.so"
libsystemd_files += "${prefix}/lib/libsystemd-daemon.so.*"
libsystemd_files += "${prefix}/lib/libsystemd-login.so.*"
libsystemd_files += "${prefix}/lib/libsystemd-journal.so.*"
libsystemd_files += "${prefix}/lib/libsystemd-id128.so.*"
libsystemd_files += "${prefix}/lib/libudev.so.*"
libsystemd_files += "${prefix}/lib/libnss_myhostname.so.2"

systemd_files = ""
systemd_files += "systemd.manifest"
systemd_files += "${sysconfdir}/systemd/bootchart.conf"
systemd_files += "${sysconfdir}/pam.d/systemd-user"
systemd_files += "${prefix}/bin/bootctl"
systemd_files += "${prefix}/bin/kernel-install"
systemd_files += "${prefix}/bin/machinectl"
systemd_files += "${prefix}/bin/systemd-run"
systemd_files += "${prefix}/lib/kernel"
systemd_files += "${prefix}/lib/kernel/install.d"
systemd_files += "${prefix}/lib/kernel/install.d/50-depmod.install"
systemd_files += "${prefix}/lib/kernel/install.d/90-loaderentry.install"
systemd_files += "${prefix}/lib/systemd/system-generators/systemd-efi-boot-generator"
systemd_files += "${prefix}/bin/hostnamectl"
systemd_files += "${prefix}/bin/localectl"
systemd_files += "${prefix}/bin/systemd-coredumpctl"
systemd_files += "${prefix}/bin/timedatectl"
systemd_files += "${sysconfdir}/systemd"
systemd_files += "${sysconfdir}/systemd/system"
systemd_files += "${sysconfdir}/systemd/user"
systemd_files += "${sysconfdir}/tmpfiles.d"
systemd_files += "${sysconfdir}/sysctl.d"
systemd_files += "${sysconfdir}/modules-load.d"
systemd_files += "${sysconfdir}/binfmt.d"
systemd_files += "${prefix}/share/bash-completion/*"
systemd_files += "${prefix}/share/zsh/site-functions"
systemd_files += "${prefix}/share/zsh/site-functions/*"
systemd_files += "${sysconfdir}/udev"
systemd_files += "${sysconfdir}/udev/rules.d"
systemd_files += "${prefix}/lib/systemd"
systemd_files += "${prefix}/lib/systemd/system"
systemd_files += "${prefix}/lib/systemd/system-generators"
systemd_files += "${prefix}/lib/systemd/user-generators"
systemd_files += "${prefix}/lib/systemd/system-preset"
systemd_files += "${prefix}/lib/systemd/user-preset"
systemd_files += "${prefix}/lib/systemd/system-shutdown"
systemd_files += "${prefix}/lib/systemd/system-sleep"
systemd_files += "${prefix}/lib/tmpfiles.d"
systemd_files += "${prefix}/lib/sysctl.d"
systemd_files += "${prefix}/lib/modules-load.d"
systemd_files += "${prefix}/lib/binfmt.d"
systemd_files += "${prefix}/lib/firmware"
systemd_files += "${prefix}/lib/firmware/updates"
systemd_files += "${prefix}/share/systemd"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.systemd1.conf"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.hostname1.conf"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.login1.conf"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.locale1.conf"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.timedate1.conf"
systemd_files += "${sysconfdir}/dbus-1/system.d/org.freedesktop.machine1.conf"
systemd_files += "${sysconfdir}/systemd/system.conf"
systemd_files += "${sysconfdir}/systemd/user.conf"
systemd_files += "${sysconfdir}/systemd/logind.conf"
systemd_files += "${sysconfdir}/systemd/journald.conf"
systemd_files += "${sysconfdir}/udev/udev.conf"
systemd_files += "${sysconfdir}/rpm/macros.systemd"
systemd_files += "${sysconfdir}/xdg/systemd"
systemd_files += "${prefix}/bin/systemd"
systemd_files += "${prefix}/bin/systemctl"
systemd_files += "${prefix}/bin/systemd-notify"
systemd_files += "${prefix}/bin/systemd-ask-password"
systemd_files += "${prefix}/bin/systemd-tty-ask-password-agent"
systemd_files += "${prefix}/bin/systemd-machine-id-setup"
systemd_files += "${prefix}/bin/loginctl"
systemd_files += "${prefix}/bin/systemd-loginctl"
systemd_files += "${prefix}/bin/journalctl"
systemd_files += "${prefix}/bin/systemd-tmpfiles"
systemd_files += "${prefix}/bin/systemd-nspawn"
systemd_files += "${prefix}/bin/systemd-stdio-bridge"
systemd_files += "${prefix}/bin/systemd-cat"
systemd_files += "${prefix}/bin/systemd-cgls"
systemd_files += "${prefix}/bin/systemd-cgtop"
systemd_files += "${prefix}/bin/systemd-delta"
systemd_files += "${prefix}/bin/systemd-detect-virt"
systemd_files += "${prefix}/bin/systemd-inhibit"
systemd_files += "${prefix}/bin/udevadm"
systemd_files += "${prefix}/lib/sysctl.d/*.conf"
systemd_files += "${prefix}/lib/systemd/systemd"
systemd_files += "${prefix}/lib/systemd/system"
systemd_files += "${prefix}/lib/systemd/system/basic.target.wants"
systemd_files += "${prefix}/lib/systemd/user"
systemd_files += "${prefix}/lib/systemd/user/bluetooth.target"
systemd_files += "${prefix}/lib/systemd/user/exit.target"
systemd_files += "${prefix}/lib/systemd/user/printer.target"
systemd_files += "${prefix}/lib/systemd/user/shutdown.target"
systemd_files += "${prefix}/lib/systemd/user/sockets.target"
systemd_files += "${prefix}/lib/systemd/user/sound.target"
systemd_files += "${prefix}/lib/systemd/user/systemd-exit.service"
systemd_files += "${prefix}/lib/systemd/user/paths.target"
systemd_files += "${prefix}/lib/systemd/user/smartcard.target"
systemd_files += "${prefix}/lib/systemd/user/timers.target"
systemd_files += "${prefix}/lib/systemd/systemd-*"
systemd_files += "${prefix}/lib/systemd/catalog"
systemd_files += "${prefix}/lib/systemd/catalog/systemd.catalog"
systemd_files += "${prefix}/lib/udev"
systemd_files += "${prefix}/lib/systemd/system-generators/systemd-getty-generator"
systemd_files += "${prefix}/lib/systemd/system-generators/systemd-fstab-generator"
systemd_files += "${prefix}/lib/systemd/system-generators/systemd-system-update-generator"
systemd_files += "${prefix}/lib/systemd/system-generators/systemd-gpt-auto-generator"
systemd_files += "${prefix}/lib/tmpfiles.d/systemd.conf"
systemd_files += "${prefix}/lib/tmpfiles.d/x11.conf"
systemd_files += "${prefix}/lib/tmpfiles.d/tmp.conf"
systemd_files += "${prefix}/lib/tmpfiles.d/legacy.conf"
systemd_files += "${prefix}/lib/tmpfiles.d/pamconsole-tmp.conf"
systemd_files += "${prefix}/sbin/init"
systemd_files += "${prefix}/sbin/reboot"
systemd_files += "${prefix}/sbin/halt"
systemd_files += "${prefix}/sbin/poweroff"
systemd_files += "${prefix}/sbin/shutdown"
systemd_files += "${prefix}/sbin/telinit"
systemd_files += "${prefix}/sbin/runlevel"
systemd_files += "${prefix}/sbin/udevadm"
systemd_files += "${prefix}/share/systemd/kbd-model-map"
systemd_files += "${prefix}/share/dbus-1/services/org.freedesktop.systemd1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.systemd1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.hostname1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.login1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.locale1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.timedate1.service"
systemd_files += "${prefix}/share/dbus-1/system-services/org.freedesktop.machine1.service"
systemd_files += "${prefix}/share/dbus-1/interfaces/org.freedesktop.systemd1.*.xml"
systemd_files += "${prefix}/share/dbus-1/interfaces/org.freedesktop.hostname1.xml"
systemd_files += "${prefix}/share/dbus-1/interfaces/org.freedesktop.locale1.xml"
systemd_files += "${prefix}/share/dbus-1/interfaces/org.freedesktop.timedate1.xml"
systemd_files += "${prefix}/share/polkit-1"
systemd_files += "${prefix}/share/polkit-1/actions"
systemd_files += "${prefix}/share/polkit-1/actions/org.freedesktop.systemd1.policy"
systemd_files += "${prefix}/share/polkit-1/actions/org.freedesktop.hostname1.policy"
systemd_files += "${prefix}/share/polkit-1/actions/org.freedesktop.login1.policy"
systemd_files += "${prefix}/share/polkit-1/actions/org.freedesktop.locale1.policy"
systemd_files += "${prefix}/share/polkit-1/actions/org.freedesktop.timedate1.policy"
systemd_files += "${prefix}/share/pkgconfig/systemd.pc"
systemd_files += "${prefix}/share/pkgconfig/udev.pc"

libgudev-dev_files = ""
libgudev-dev_files += "systemd.manifest"
libgudev-dev_files += "${prefix}/lib/libgudev-1.0.so"
libgudev-dev_files += "${prefix}/include/gudev-1.0"
libgudev-dev_files += "${prefix}/include/gudev-1.0/gudev"
libgudev-dev_files += "${prefix}/include/gudev-1.0/gudev/*.h"
libgudev-dev_files += "${prefix}/lib/pkgconfig/gudev-1.0*"

systemd-dev_files = ""
systemd-dev_files += "systemd.manifest"
systemd-dev_files += "${prefix}/lib/libsystemd-daemon.so"
systemd-dev_files += "${prefix}/lib/libsystemd-login.so"
systemd-dev_files += "${prefix}/lib/libsystemd-journal.so"
systemd-dev_files += "${prefix}/lib/libsystemd-id128.so"
systemd-dev_files += "${prefix}/lib/libudev.so"
systemd-dev_files += "${prefix}/include/systemd"
systemd-dev_files += "${prefix}/include/systemd/sd-daemon.h"
systemd-dev_files += "${prefix}/include/systemd/sd-login.h"
systemd-dev_files += "${prefix}/include/systemd/sd-journal.h"
systemd-dev_files += "${prefix}/include/systemd/sd-id128.h"
systemd-dev_files += "${prefix}/include/systemd/sd-messages.h"
systemd-dev_files += "${prefix}/include/systemd/sd-shutdown.h"
systemd-dev_files += "${prefix}/include/libudev.h"
systemd-dev_files += "${prefix}/lib/pkgconfig/libsystemd-daemon.pc"
systemd-dev_files += "${prefix}/lib/pkgconfig/libsystemd-login.pc"
systemd-dev_files += "${prefix}/lib/pkgconfig/libsystemd-journal.pc"
systemd-dev_files += "${prefix}/lib/pkgconfig/libsystemd-id128.pc"
systemd-dev_files += "${prefix}/lib/pkgconfig/libudev.pc"

libgudev_files = ""
libgudev_files += "systemd.manifest"
libgudev_files += "${prefix}/lib/libgudev-1.0.so.*"

systemd-analyze_files = ""
systemd-analyze_files += "systemd.manifest"
systemd-analyze_files += "${prefix}/bin/systemd-analyze"

FILES_lib${PN} = "${libsystemd_files}"
FILES_${PN} = "${systemd_files}"
FILES_libgudev-dev = "${libgudev-dev_files}"
FILES_${PN}-dev = "${systemd-dev_files}"
FILES_libgudev = "${libgudev_files}"
FILES_${PN}-analyze = "${systemd-analyze_files}"

PKG_libsystemd= "libsystemd"
PKG_systemd= "systemd"
PKG_libgudev-dev= "libgudev-dev"
PKG_systemd-dev= "systemd-dev"
PKG_libgudev= "libgudev"
PKG_systemd-analyze= "systemd-analyze"

require systemd-extraconf.inc

