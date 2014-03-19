DESCRIPTION = "Kernel loader which uses a FAT, ext2/3 or iso9660 filesystem or a PXE network"
HOMEPAGE = "http://syslinux.zytor.com/"
SECTION = "System/Boot"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by syslinux-devel 
PROVIDES += "syslinux-devel"
RPROVIDES_syslinux-devel += "syslinux-devel"
RPROVIDES_syslinux-devel += "syslinux-dev"

#PROVIDES by syslinux 
PROVIDES += "syslinux"
RPROVIDES_syslinux += "syslinux"

#PROVIDES by syslinux-extlinux 
PROVIDES += "syslinux-extlinux"
RPROVIDES_syslinux-extlinux += "syslinux-extlinux"

#PROVIDES by syslinux-tftpboot 
PROVIDES += "syslinux-tftpboot"
RPROVIDES_syslinux-tftpboot += "syslinux-tftpboot"

RDEPENDS = ""
#RDEPENDS of syslinux-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "syslinux"

#RDEPENDS of syslinux (${PN})
RDEPENDS_${PN} += "mtools"

#RDEPENDS of syslinux-extlinux (${PN}-extlinux)
RDEPENDS_${PN}-extlinux += "syslinux"

#RDEPENDS of syslinux-tftpboot (${PN}-tftpboot)
RDEPENDS_${PN}-tftpboot += "syslinux"


DEPENDS = ""
#DEPENDS of syslinux 
inherit perlnative
DEPENDS += "libuuid-devel"
DEPENDS += "e2fsprogs"
DEPENDS += "nasm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n syslinux-4.05
 cp ${S}/packaging/syslinux.manifest .
 
 
 
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
 
 make CC='gcc' clean
 make CC='gcc' installer
 make CC='gcc' -C sample tidy
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make CC='gcc' install-all \
 	INSTALLROOT=${D} BINDIR=/usr/bin SBINDIR=/sbin \
 	LIBDIR=/usr/lib DATADIR=/usr/share \
 	MANDIR=/usr/share/man INCDIR=/usr/include \
 	TFTPBOOT=/var/lib/tftpboot EXTLINUXDIR=/boot/extlinux
 make CC='gcc' -C sample tidy
 
 
}

PACKAGES = ""
PACKAGES += "syslinux-devel"
PACKAGES += "syslinux"
PACKAGES += "syslinux-extlinux"
PACKAGES += "syslinux-tftpboot"

syslinux-devel_files = ""
syslinux-devel_files += "syslinux.manifest"
syslinux-devel_files += "COPYING NEWS README doc/*"
syslinux-devel_files += "sample"
syslinux-devel_files += "/usr/share/man/man*/*"
syslinux-devel_files += "/usr/share/syslinux/com32"
syslinux-devel_files += "/usr/share/syslinux/diag"

syslinux_files = ""
syslinux_files += "syslinux.manifest"
syslinux_files += "/usr/bin/*"
syslinux_files += "/usr/share/syslinux"
syslinux_files += "/usr/share/syslinux/*.com"
syslinux_files += "/usr/share/syslinux/*.exe"
syslinux_files += "/usr/share/syslinux/*.c32"
syslinux_files += "/usr/share/syslinux/*.bin"
syslinux_files += "/usr/share/syslinux/*.0"
syslinux_files += "/usr/share/syslinux/memdisk"
syslinux_files += "/usr/share/syslinux/dosutil"

syslinux-extlinux_files = ""
syslinux-extlinux_files += "syslinux.manifest"
syslinux-extlinux_files += "/sbin/extlinux"
syslinux-extlinux_files += "/boot/extlinux"

syslinux-tftpboot_files = ""
syslinux-tftpboot_files += "syslinux.manifest"
syslinux-tftpboot_files += "/var/lib/tftpboot"

FILES_${PN}-devel = "${syslinux-devel_files}"
FILES_${PN} = "${syslinux_files}"
FILES_${PN}-extlinux = "${syslinux-extlinux_files}"
FILES_${PN}-tftpboot = "${syslinux-tftpboot_files}"

PKG_syslinux-devel= "syslinux-devel"
PKG_syslinux= "syslinux"
PKG_syslinux-extlinux= "syslinux-extlinux"
PKG_syslinux-tftpboot= "syslinux-tftpboot"

require syslinux-extraconf.inc
