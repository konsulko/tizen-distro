DESCRIPTION = "A System and Service Manager"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/systemd"
SECTION = "Base/Startup"
LICENSE = "LGPL-2.0+ and MIT and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsystemd 
PROVIDES += "libsystemd"
RPROVIDES_libsystemd += "libsystemd"

#PROVIDES by systemd 
PROVIDES += "systemd"
RPROVIDES_systemd += "systemd"
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

#PROVIDES by libgudev-devel 
PROVIDES += "libgudev-devel"
RPROVIDES_libgudev-devel += "libgudev-devel"
RPROVIDES_libgudev-devel += "libgudev-dev"

#PROVIDES by systemd-devel 
PROVIDES += "systemd-devel"
RPROVIDES_systemd-devel += "systemd-devel"
RPROVIDES_systemd-devel += "systemd-dev"
# the PROVIDES rules is ignore "libudev-devel = 208"
PROVIDES += "libudev-devel"
RPROVIDES_systemd-devel += "libudev-devel"
RPROVIDES_systemd-devel += "libudev-dev"

#PROVIDES by libgudev 
PROVIDES += "libgudev"
RPROVIDES_libgudev += "libgudev"

#PROVIDES by systemd-analyze 
PROVIDES += "systemd-analyze"
RPROVIDES_systemd-analyze += "systemd-analyze"

RDEPENDS = ""
#RDEPENDS of systemd (${PN})
RDEPENDS_${PN} += "/usr/bin/getent"
RDEPENDS_${PN} += "/usr/sbin/groupadd"
RDEPENDS_${PN} += "hwdata"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "gawk"
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "filesystem"

#RDEPENDS of libgudev-devel (libgudev-devel)
RDEPENDS_libgudev-devel += "libgudev"

#RDEPENDS of systemd-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "systemd"

#RDEPENDS of libgudev (libgudev)
RDEPENDS_libgudev += "systemd"

#RDEPENDS of systemd-analyze (${PN}-analyze)
RDEPENDS_${PN}-analyze += "systemd"


DEPENDS = ""
#DEPENDS of systemd 
DEPENDS += "kmod"
DEPENDS += "intltool-native"
DEPENDS += "attr"
DEPENDS += "gperf"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "hwdata"
DEPENDS += "pciutils"
DEPENDS += "usbutils"
DEPENDS += "acl"
DEPENDS += "pam"
DEPENDS += "libxslt"
DEPENDS += "pkgconfig(liblzma)"
DEPENDS += "libcap"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libgcrypt"
DEPENDS += "libblkid-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/systemd.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
         --infodir=/usr/share/info \
         --enable-bootchart \
         --libexecdir=/usr/lib \
 	    --docdir=/usr/share/doc/packages/systemd \
         --disable-static \
         --with-sysvinit-path= \
         --with-sysvrcnd-path= \
         --with-smack-run-label=System
 make -j16
 
 
 
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
 
 # udev links
 /usr/bin/mkdir -p ${D}//usr/sbin
 /usr/bin/ln -sf ../bin/udevadm ${D}/usr/sbin/udevadm
 /usr/bin/mkdir -p ${D}/usr/lib/firmware/updates
 
 # Create SysV compatibility symlinks. systemctl/systemd are smart
 # enough to detect in which way they are called.
 /usr/bin/ln -s ../lib/systemd/systemd ${D}/usr/sbin/init
 /usr/bin/ln -s ../lib/systemd/systemd ${D}/usr/bin/systemd
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/reboot
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/halt
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/poweroff
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/shutdown
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/telinit
 /usr/bin/ln -s ../bin/systemctl ${D}/usr/sbin/runlevel
 
 # legacy links
 /usr/bin/ln -s loginctl ${D}/usr/bin/systemd-loginctl
 
 # We create all wants links manually at installation time to make sure
 # they are not owned and hence overriden by rpm after the used deleted
 # them.
 /usr/bin/rm -r ${D}/etc/systemd/system/*.target.wants
 
 # Make sure the ghost-ing below works
 /usr/bin/touch ${D}/etc/systemd/system/runlevel2.target
 /usr/bin/touch ${D}/etc/systemd/system/runlevel3.target
 /usr/bin/touch ${D}/etc/systemd/system/runlevel4.target
 /usr/bin/touch ${D}/etc/systemd/system/runlevel5.target
 
 # Make sure these directories are properly owned
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system/basic.target.wants
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system/default.target.wants
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system/dbus.target.wants
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system/syslog.target.wants
 
 # Make sure the user generators dir exists too
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system-generators
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/user-generators
 
 # Create new-style configuration files so that we can ghost-own them
 /usr/bin/touch ${D}/etc/hostname
 /usr/bin/touch ${D}/etc/vconsole.conf
 /usr/bin/touch ${D}/etc/locale.conf
 /usr/bin/touch ${D}/etc/machine-id
 /usr/bin/touch ${D}/etc/machine-info
 /usr/bin/touch ${D}/etc/timezone
 #/usr/bin/mkdir -p ${D}/etc/X11/xorg.conf.d
 #/usr/bin/touch ${D}/etc/X11/xorg.conf.d/00-keyboard.conf
 
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system-preset/
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/user-preset/
 
 # Make sure the shutdown/sleep drop-in dirs exist
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system-shutdown/
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/system-sleep/
 
 # Make sure the NTP units dir exists
 /usr/bin/mkdir -p ${D}/usr/lib/systemd/ntp-units.d/
 
 # Install modprobe fragment
 /usr/bin/mkdir -p ${D}/etc/modprobe.d/
 
 # Enable readahead services
 /usr/bin/ln -s ../systemd-readahead-collect.service ${D}/usr/lib/systemd/system/default.target.wants/
 /usr/bin/ln -s ../systemd-readahead-replay.service ${D}/usr/lib/systemd/system/default.target.wants/
 
 # Fix the dangling /var/lock -> /run/lock symlink
 install -Dm644 tmpfiles.d/legacy.conf ${D}/usr/lib/tmpfiles.d/legacy.conf
 
 install -m644 ${S}/packaging/pamconsole-tmp.conf ${D}/usr/lib/tmpfiles.d/
 
 rm -rf ${D}//usr/lib/systemd/user/default.target
 
 rm -rf ${D}//usr/share/doc/packages/systemd
 
 # Move macros to the proper location for Tizen
 mkdir -p ${D}/etc/rpm
 install -m644 src/core/macros.systemd ${D}/etc/rpm/macros.systemd
 rm -f ${D}/usr/lib/rpm/macros.d/macros.systemd
 
 
}

PACKAGES = ""
PACKAGES += "libsystemd"
PACKAGES += "systemd"
PACKAGES += "libgudev-devel"
PACKAGES += "systemd-devel"
PACKAGES += "libgudev"
PACKAGES += "systemd-analyze"

libsystemd_files = ""
libsystemd_files += "systemd.manifest"
libsystemd_files += "/usr/lib/security/pam_systemd.so"
libsystemd_files += "/usr/lib/libsystemd-daemon.so.*"
libsystemd_files += "/usr/lib/libsystemd-login.so.*"
libsystemd_files += "/usr/lib/libsystemd-journal.so.*"
libsystemd_files += "/usr/lib/libsystemd-id128.so.*"
libsystemd_files += "/usr/lib/libudev.so.*"
libsystemd_files += "/usr/lib/libnss_myhostname.so.2"

systemd_files = ""
systemd_files += "systemd.manifest"
systemd_files += "/etc/systemd/bootchart.conf"
systemd_files += "/etc/pam.d/systemd-user"
systemd_files += "/usr/bin/bootctl"
systemd_files += "/usr/bin/kernel-install"
systemd_files += "/usr/bin/machinectl"
systemd_files += "/usr/bin/systemd-run"
systemd_files += "/usr/lib/kernel"
systemd_files += "/usr/lib/kernel/install.d"
systemd_files += "/usr/lib/kernel/install.d/50-depmod.install"
systemd_files += "/usr/lib/kernel/install.d/90-loaderentry.install"
systemd_files += "/usr/lib/systemd/system-generators/systemd-efi-boot-generator"
systemd_files += "/usr/bin/hostnamectl"
systemd_files += "/usr/bin/localectl"
systemd_files += "/usr/bin/systemd-coredumpctl"
systemd_files += "/usr/bin/timedatectl"
systemd_files += "/etc/systemd"
systemd_files += "/etc/systemd/system"
systemd_files += "/etc/systemd/user"
systemd_files += "/etc/tmpfiles.d"
systemd_files += "/etc/sysctl.d"
systemd_files += "/etc/modules-load.d"
systemd_files += "/etc/binfmt.d"
systemd_files += "/usr/share/bash-completion/*"
systemd_files += "/usr/share/zsh/site-functions"
systemd_files += "/usr/share/zsh/site-functions/*"
systemd_files += "/etc/udev"
systemd_files += "/etc/udev/rules.d"
systemd_files += "/usr/lib/systemd"
systemd_files += "/usr/lib/systemd/system"
systemd_files += "/usr/lib/systemd/system-generators"
systemd_files += "/usr/lib/systemd/user-generators"
systemd_files += "/usr/lib/systemd/system-preset"
systemd_files += "/usr/lib/systemd/user-preset"
systemd_files += "/usr/lib/systemd/system-shutdown"
systemd_files += "/usr/lib/systemd/system-sleep"
systemd_files += "/usr/lib/tmpfiles.d"
systemd_files += "/usr/lib/sysctl.d"
systemd_files += "/usr/lib/modules-load.d"
systemd_files += "/usr/lib/binfmt.d"
systemd_files += "/usr/lib/firmware"
systemd_files += "/usr/lib/firmware/updates"
systemd_files += "/usr/share/systemd"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.systemd1.conf"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.hostname1.conf"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.login1.conf"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.locale1.conf"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.timedate1.conf"
systemd_files += "/etc/dbus-1/system.d/org.freedesktop.machine1.conf"
systemd_files += "/etc/systemd/system.conf"
systemd_files += "/etc/systemd/user.conf"
systemd_files += "/etc/systemd/logind.conf"
systemd_files += "/etc/systemd/journald.conf"
systemd_files += "/etc/udev/udev.conf"
systemd_files += "/etc/rpm/macros.systemd"
systemd_files += "/etc/xdg/systemd"
systemd_files += "/usr/bin/systemd"
systemd_files += "/usr/bin/systemctl"
systemd_files += "/usr/bin/systemd-notify"
systemd_files += "/usr/bin/systemd-ask-password"
systemd_files += "/usr/bin/systemd-tty-ask-password-agent"
systemd_files += "/usr/bin/systemd-machine-id-setup"
systemd_files += "/usr/bin/loginctl"
systemd_files += "/usr/bin/systemd-loginctl"
systemd_files += "/usr/bin/journalctl"
systemd_files += "/usr/bin/systemd-tmpfiles"
systemd_files += "/usr/bin/systemd-nspawn"
systemd_files += "/usr/bin/systemd-stdio-bridge"
systemd_files += "/usr/bin/systemd-cat"
systemd_files += "/usr/bin/systemd-cgls"
systemd_files += "/usr/bin/systemd-cgtop"
systemd_files += "/usr/bin/systemd-delta"
systemd_files += "/usr/bin/systemd-detect-virt"
systemd_files += "/usr/bin/systemd-inhibit"
systemd_files += "/usr/bin/udevadm"
systemd_files += "/usr/lib/sysctl.d/*.conf"
systemd_files += "/usr/lib/systemd/systemd"
systemd_files += "/usr/lib/systemd/system"
systemd_files += "/usr/lib/systemd/system/basic.target.wants"
systemd_files += "/usr/lib/systemd/user"
systemd_files += "/usr/lib/systemd/user/bluetooth.target"
systemd_files += "/usr/lib/systemd/user/exit.target"
systemd_files += "/usr/lib/systemd/user/printer.target"
systemd_files += "/usr/lib/systemd/user/shutdown.target"
systemd_files += "/usr/lib/systemd/user/sockets.target"
systemd_files += "/usr/lib/systemd/user/sound.target"
systemd_files += "/usr/lib/systemd/user/systemd-exit.service"
systemd_files += "/usr/lib/systemd/user/paths.target"
systemd_files += "/usr/lib/systemd/user/smartcard.target"
systemd_files += "/usr/lib/systemd/user/timers.target"
systemd_files += "/usr/lib/systemd/systemd-*"
systemd_files += "/usr/lib/systemd/catalog"
systemd_files += "/usr/lib/systemd/catalog/systemd.catalog"
systemd_files += "/usr/lib/udev"
systemd_files += "/usr/lib/systemd/system-generators/systemd-getty-generator"
systemd_files += "/usr/lib/systemd/system-generators/systemd-fstab-generator"
systemd_files += "/usr/lib/systemd/system-generators/systemd-system-update-generator"
systemd_files += "/usr/lib/systemd/system-generators/systemd-gpt-auto-generator"
systemd_files += "/usr/lib/tmpfiles.d/systemd.conf"
systemd_files += "/usr/lib/tmpfiles.d/x11.conf"
systemd_files += "/usr/lib/tmpfiles.d/tmp.conf"
systemd_files += "/usr/lib/tmpfiles.d/legacy.conf"
systemd_files += "/usr/lib/tmpfiles.d/pamconsole-tmp.conf"
systemd_files += "/usr/sbin/init"
systemd_files += "/usr/sbin/reboot"
systemd_files += "/usr/sbin/halt"
systemd_files += "/usr/sbin/poweroff"
systemd_files += "/usr/sbin/shutdown"
systemd_files += "/usr/sbin/telinit"
systemd_files += "/usr/sbin/runlevel"
systemd_files += "/usr/sbin/udevadm"
systemd_files += "/usr/share/systemd/kbd-model-map"
systemd_files += "/usr/share/dbus-1/services/org.freedesktop.systemd1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.systemd1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.hostname1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.login1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.locale1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.timedate1.service"
systemd_files += "/usr/share/dbus-1/system-services/org.freedesktop.machine1.service"
systemd_files += "/usr/share/dbus-1/interfaces/org.freedesktop.systemd1.*.xml"
systemd_files += "/usr/share/dbus-1/interfaces/org.freedesktop.hostname1.xml"
systemd_files += "/usr/share/dbus-1/interfaces/org.freedesktop.locale1.xml"
systemd_files += "/usr/share/dbus-1/interfaces/org.freedesktop.timedate1.xml"
systemd_files += "/usr/share/polkit-1"
systemd_files += "/usr/share/polkit-1/actions"
systemd_files += "/usr/share/polkit-1/actions/org.freedesktop.systemd1.policy"
systemd_files += "/usr/share/polkit-1/actions/org.freedesktop.hostname1.policy"
systemd_files += "/usr/share/polkit-1/actions/org.freedesktop.login1.policy"
systemd_files += "/usr/share/polkit-1/actions/org.freedesktop.locale1.policy"
systemd_files += "/usr/share/polkit-1/actions/org.freedesktop.timedate1.policy"
systemd_files += "/usr/share/pkgconfig/systemd.pc"
systemd_files += "/usr/share/pkgconfig/udev.pc"

libgudev-devel_files = ""
libgudev-devel_files += "systemd.manifest"
libgudev-devel_files += "/usr/lib/libgudev-1.0.so"
libgudev-devel_files += "/usr/include/gudev-1.0"
libgudev-devel_files += "/usr/include/gudev-1.0/gudev"
libgudev-devel_files += "/usr/include/gudev-1.0/gudev/*.h"
libgudev-devel_files += "/usr/lib/pkgconfig/gudev-1.0*"

systemd-devel_files = ""
systemd-devel_files += "systemd.manifest"
systemd-devel_files += "/usr/lib/libsystemd-daemon.so"
systemd-devel_files += "/usr/lib/libsystemd-login.so"
systemd-devel_files += "/usr/lib/libsystemd-journal.so"
systemd-devel_files += "/usr/lib/libsystemd-id128.so"
systemd-devel_files += "/usr/lib/libudev.so"
systemd-devel_files += "/usr/include/systemd"
systemd-devel_files += "/usr/include/systemd/sd-daemon.h"
systemd-devel_files += "/usr/include/systemd/sd-login.h"
systemd-devel_files += "/usr/include/systemd/sd-journal.h"
systemd-devel_files += "/usr/include/systemd/sd-id128.h"
systemd-devel_files += "/usr/include/systemd/sd-messages.h"
systemd-devel_files += "/usr/include/systemd/sd-shutdown.h"
systemd-devel_files += "/usr/include/libudev.h"
systemd-devel_files += "/usr/lib/pkgconfig/libsystemd-daemon.pc"
systemd-devel_files += "/usr/lib/pkgconfig/libsystemd-login.pc"
systemd-devel_files += "/usr/lib/pkgconfig/libsystemd-journal.pc"
systemd-devel_files += "/usr/lib/pkgconfig/libsystemd-id128.pc"
systemd-devel_files += "/usr/lib/pkgconfig/libudev.pc"

libgudev_files = ""
libgudev_files += "systemd.manifest"
libgudev_files += "/usr/lib/libgudev-1.0.so.*"

systemd-analyze_files = ""
systemd-analyze_files += "systemd.manifest"
systemd-analyze_files += "/usr/bin/systemd-analyze"

FILES_lib${PN} = "${libsystemd_files}"
FILES_${PN} = "${systemd_files}"
FILES_libgudev-devel = "${libgudev-devel_files}"
FILES_${PN}-devel = "${systemd-devel_files}"
FILES_libgudev = "${libgudev_files}"
FILES_${PN}-analyze = "${systemd-analyze_files}"

PKG_libsystemd= "libsystemd"
PKG_systemd= "systemd"
PKG_libgudev-devel= "libgudev-devel"
PKG_systemd-devel= "systemd-devel"
PKG_libgudev= "libgudev"
PKG_systemd-analyze= "systemd-analyze"

require systemd-extraconf.inc
