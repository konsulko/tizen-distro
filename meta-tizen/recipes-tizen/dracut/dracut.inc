DESCRIPTION = "Initramfs generator using udev"
HOMEPAGE = "https://dracut.wiki.kernel.org/"
SECTION = "Base/Startup"
LICENSE = "GPL-2.0+ and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dracut-network 
PROVIDES += "dracut-network"
RPROVIDES_dracut-network += "dracut-network"

#PROVIDES by dracut 
PROVIDES += "dracut"
RPROVIDES_dracut += "dracut"

#PROVIDES by dracut-caps 
PROVIDES += "dracut-caps"
RPROVIDES_dracut-caps += "dracut-caps"

#PROVIDES by dracut-tools 
PROVIDES += "dracut-tools"
RPROVIDES_dracut-tools += "dracut-tools"

RDEPENDS = ""
#RDEPENDS of dracut-network (${PN}-network)
RDEPENDS_${PN}-network += "dracut"

#RDEPENDS of dracut (${PN})
RDEPENDS_${PN} += "xz"
RDEPENDS_${PN} += "kmod-compat"
RDEPENDS_${PN} += "grep"
RDEPENDS_${PN} += "kpartx"
RDEPENDS_${PN} += "cpio"
RDEPENDS_${PN} += "kbd"
RDEPENDS_${PN} += "udev"
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "hardlink"
RDEPENDS_${PN} += "findutils"
RDEPENDS_${PN} += "file"
RDEPENDS_${PN} += "filesystem"
RDEPENDS_${PN} += "gzip"
RDEPENDS_${PN} += "sed"
RDEPENDS_${PN} += "util-linux"
RDEPENDS_${PN} += "bash"

#RDEPENDS of dracut-caps (${PN}-caps)
RDEPENDS_${PN}-caps += "libcap"
RDEPENDS_${PN}-caps += "dracut"

#RDEPENDS of dracut-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "dracut"


DEPENDS = ""
#DEPENDS of dracut 
DEPENDS += "dash"
DEPENDS += "git"
DEPENDS += "asciidoc"
DEPENDS += "bash"
DEPENDS += "xsltproc"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dracut.manifest .
 
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
 
 make all
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} \
      libdir=/usr/lib \
      bindir=/usr/bin \
      systemdsystemunitdir=/lib/systemd/system \
      sysconfdir=/etc mandir=/usr/share/man
 
 echo "DRACUT_VERSION=032-0" > ${D}//usr/lib/dracut/dracut-version.sh
 
 rm -fr ${D}//usr/lib/dracut/modules.d/01fips
 rm -fr ${D}//usr/lib/dracut/modules.d/02fips-aesni
 
 
 # remove gentoo specific modules
 rm -fr ${D}//usr/lib/dracut/modules.d/50gensplash
 
 # with systemd IMA and selinux modules do not make sense
 rm -fr ${D}//usr/lib/dracut/modules.d/96securityfs
 rm -fr ${D}//usr/lib/dracut/modules.d/97masterkey
 rm -fr ${D}//usr/lib/dracut/modules.d/98integrity
 rm -fr ${D}//usr/lib/dracut/modules.d/98selinux
 
 mkdir -p ${D}/boot/dracut
 mkdir -p ${D}/var/lib/dracut/overlay
 mkdir -p ${D}/var/log
 touch ${D}/var/log/dracut.log
 mkdir -p ${D}/usr/com/initramfs
 
 install -m 0644 dracut.conf.d/suse.conf.example   ${D}/etc/dracut.conf.d/01-dist.conf
 
 
 mkdir -p ${D}/etc/logrotate.d
 install -m 0644 dracut.logrotate ${D}/etc/logrotate.d/dracut_log
 
 
 
}

PACKAGES = ""
PACKAGES += "dracut-network"
PACKAGES += "dracut"
PACKAGES += "dracut-caps"
PACKAGES += "dracut-tools"

dracut-network_files = ""
dracut-network_files += "dracut.manifest"
dracut-network_files += "/usr/lib/dracut/modules.d/40network"
dracut-network_files += "/usr/lib/dracut/modules.d/95fcoe"
dracut-network_files += "/usr/lib/dracut/modules.d/95iscsi"
dracut-network_files += "/usr/lib/dracut/modules.d/90livenet"
dracut-network_files += "/usr/lib/dracut/modules.d/90qemu-net"
dracut-network_files += "/usr/lib/dracut/modules.d/95cifs"
dracut-network_files += "/usr/lib/dracut/modules.d/95nbd"
dracut-network_files += "/usr/lib/dracut/modules.d/95nfs"
dracut-network_files += "/usr/lib/dracut/modules.d/95ssh-client"
dracut-network_files += "/usr/lib/dracut/modules.d/45ifcfg"
dracut-network_files += "/usr/lib/dracut/modules.d/95znet"

dracut_files = ""
dracut_files += "dracut.manifest"
dracut_files += "/usr/bin/dracut"
dracut_files += "/usr/bin/mkinitrd"
dracut_files += "/usr/bin/lsinitrd"
dracut_files += "/usr/lib/dracut"
dracut_files += "/usr/lib/dracut/modules.d"
dracut_files += "/usr/lib/dracut/dracut-functions.sh"
dracut_files += "/usr/lib/dracut/dracut-functions"
dracut_files += "/usr/lib/dracut/dracut-version.sh"
dracut_files += "/usr/lib/dracut/dracut-logger.sh"
dracut_files += "/usr/lib/dracut/dracut-initramfs-restore"
dracut_files += "/usr/lib/dracut/dracut-install"
dracut_files += "/etc/dracut.conf"
dracut_files += "/etc/dracut.conf.d/01-dist.conf"
dracut_files += "/etc/dracut.conf.d"
dracut_files += "/usr/share/man/man8/dracut.8*"
dracut_files += "/usr/share/man/man8/*service.8*"
dracut_files += "/usr/share/man/man8/mkinitrd.8*"
dracut_files += "/usr/share/man/man1/lsinitrd.1*"
dracut_files += "/usr/share/man/man7/dracut.kernel.7*"
dracut_files += "/usr/share/man/man7/dracut.bootup.7*"
dracut_files += "/usr/share/man/man7/dracut.cmdline.7*"
dracut_files += "/usr/share/man/man5/dracut.conf.5*"
dracut_files += "/usr/lib/dracut/modules.d/00dash"
dracut_files += "/usr/lib/dracut/modules.d/00bootchart"
dracut_files += "/usr/lib/dracut/modules.d/00systemd-bootchart/module-setup.sh"
dracut_files += "/usr/lib/dracut/modules.d/03rescue/module-setup.sh"
dracut_files += "/usr/lib/dracut/modules.d/04watchdog"
dracut_files += "/usr/lib/dracut/modules.d/05busybox"
dracut_files += "/usr/lib/dracut/modules.d/10i18n"
dracut_files += "/usr/lib/dracut/modules.d/30convertfs"
dracut_files += "/usr/lib/dracut/modules.d/45url-lib"
dracut_files += "/usr/lib/dracut/modules.d/50plymouth"
dracut_files += "/usr/lib/dracut/modules.d/50drm/module-setup.sh"
dracut_files += "/usr/lib/dracut/modules.d/80cms"
dracut_files += "/usr/lib/dracut/modules.d/90btrfs"
dracut_files += "/usr/lib/dracut/modules.d/90crypt"
dracut_files += "/usr/lib/dracut/modules.d/90dm"
dracut_files += "/usr/lib/dracut/modules.d/90dmraid"
dracut_files += "/usr/lib/dracut/modules.d/90dmsquash-live"
dracut_files += "/usr/lib/dracut/modules.d/90kernel-modules"
dracut_files += "/usr/lib/dracut/modules.d/90lvm"
dracut_files += "/usr/lib/dracut/modules.d/90mdraid"
dracut_files += "/usr/lib/dracut/modules.d/90multipath"
dracut_files += "/usr/lib/dracut/modules.d/90qemu"
dracut_files += "/usr/lib/dracut/modules.d/91crypt-gpg"
dracut_files += "/usr/lib/dracut/modules.d/91crypt-loop"
dracut_files += "/usr/lib/dracut/modules.d/95debug"
dracut_files += "/usr/lib/dracut/modules.d/95resume"
dracut_files += "/usr/lib/dracut/modules.d/95rootfs-block"
dracut_files += "/usr/lib/dracut/modules.d/95dasd"
dracut_files += "/usr/lib/dracut/modules.d/95dasd_mod"
dracut_files += "/usr/lib/dracut/modules.d/95fstab-sys"
dracut_files += "/usr/lib/dracut/modules.d/95zfcp"
dracut_files += "/usr/lib/dracut/modules.d/95terminfo"
dracut_files += "/usr/lib/dracut/modules.d/95udev-rules"
dracut_files += "/usr/lib/dracut/modules.d/95virtfs"
dracut_files += "/usr/lib/dracut/modules.d/97biosdevname"
dracut_files += "/usr/lib/dracut/modules.d/98ecryptfs"
dracut_files += "/usr/lib/dracut/modules.d/98pollcdrom"
dracut_files += "/usr/lib/dracut/modules.d/98syslog"
dracut_files += "/usr/lib/dracut/modules.d/98systemd"
dracut_files += "/usr/lib/dracut/modules.d/98usrmount"
dracut_files += "/usr/lib/dracut/modules.d/99base"
dracut_files += "/usr/lib/dracut/modules.d/99fs-lib"
dracut_files += "/usr/lib/dracut/modules.d/99img-lib"
dracut_files += "/usr/lib/dracut/modules.d/99shutdown"
dracut_files += "/usr/lib/dracut/modules.d/00bash/module-setup.sh"
dracut_files += "/usr/lib/dracut/modules.d/03modsign/load-modsign-keys.sh"
dracut_files += "/usr/lib/dracut/modules.d/03modsign/module-setup.sh"
dracut_files += "/usr/lib/dracut/modules.d/90bcache/module-setup.sh"
dracut_files += "/etc/logrotate.d/dracut_log"
dracut_files += "/usr/com/initramfs"
dracut_files += "/lib/systemd/system/dracut-shutdown.service"
dracut_files += "/lib/systemd/system/shutdown.target.wants/dracut-shutdown.service"
dracut_files += "/lib/systemd/system/dracut-cmdline.service"
dracut_files += "/lib/systemd/system/dracut-initqueue.service"
dracut_files += "/lib/systemd/system/dracut-mount.service"
dracut_files += "/lib/systemd/system/dracut-pre-mount.service"
dracut_files += "/lib/systemd/system/dracut-pre-pivot.service"
dracut_files += "/lib/systemd/system/dracut-pre-trigger.service"
dracut_files += "/lib/systemd/system/dracut-pre-udev.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-cmdline.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-initqueue.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-mount.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-pre-mount.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-pre-pivot.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-pre-trigger.service"
dracut_files += "/lib/systemd/system/initrd.target.wants/dracut-pre-udev.service"
dracut_files += "/usr/lib/kernel/install.d/50-dracut.install"
dracut_files += "/usr/lib/kernel/install.d/51-dracut-rescue.install"
dracut_files += "/usr/share/bash-completion/completions/dracut"
dracut_files += "/usr/share/bash-completion/completions/lsinitrd"

dracut-caps_files = ""
dracut-caps_files += "dracut.manifest"
dracut-caps_files += "/usr/lib/dracut/modules.d/02caps"

dracut-tools_files = ""
dracut-tools_files += "dracut.manifest"
dracut-tools_files += "/usr/share/man/man8/dracut-catimages.8*"
dracut-tools_files += "/usr/bin/dracut-catimages"
dracut-tools_files += "/boot/dracut"
dracut-tools_files += "/var/lib/dracut"
dracut-tools_files += "/var/lib/dracut/overlay"

FILES_${PN}-network = "${dracut-network_files}"
FILES_${PN} = "${dracut_files}"
FILES_${PN}-caps = "${dracut-caps_files}"
FILES_${PN}-tools = "${dracut-tools_files}"

PKG_dracut-network= "dracut-network"
PKG_dracut= "dracut"
PKG_dracut-caps= "dracut-caps"
PKG_dracut-tools= "dracut-tools"

require dracut-extraconf.inc
