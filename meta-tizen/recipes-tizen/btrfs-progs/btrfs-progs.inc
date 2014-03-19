DESCRIPTION = "Utilities for the Btrfs filesystem"
HOMEPAGE = "http://btrfs.wiki.kernel.org/index.php/Main_Page"
SECTION = "Base/File Systems"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by btrfs-progs-docs  
PROVIDES += "btrfs-progs-docs "
RPROVIDES_btrfs-progs-docs  += "btrfs-progs-docs "

#PROVIDES by btrfs-progs 
PROVIDES += "btrfs-progs"
RPROVIDES_btrfs-progs += "btrfs-progs"

RDEPENDS = ""
#RDEPENDS of btrfs-progs (${PN})
RDEPENDS_${PN} += "coreutils"


DEPENDS = ""
#DEPENDS of btrfs-progs 
DEPENDS += "pkgconfig(ext2fs)"
DEPENDS += "pkgconfig(uuid)"
DEPENDS += "zlib-devel"
DEPENDS += "lzo-devel"
DEPENDS += "acl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/btrfs-progs.manifest .
 
 
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
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} prefix=/usr bindir=/usr/sbin mandir=/usr/share/man
 ln -s /usr/sbin/btrfsck ${D}/usr/sbin/fsck.btrfs
 
 
 
 
}

PACKAGES = ""
PACKAGES += "btrfs-progs-docs"
PACKAGES += "btrfs-progs"

btrfs-progs-docs_files = ""
btrfs-progs-docs_files += "/usr/share/info"
btrfs-progs-docs_files += "/usr/share/man"

btrfs-progs_files = ""
btrfs-progs_files += "btrfs-progs.manifest"
btrfs-progs_files += "/usr/sbin/btrfs"
btrfs-progs_files += "/usr/sbin/btrfs-convert"
btrfs-progs_files += "/usr/sbin/btrfs-debug-tree"
btrfs-progs_files += "/usr/sbin/btrfs-find-root"
btrfs-progs_files += "/usr/sbin/btrfs-image"
btrfs-progs_files += "/usr/sbin/btrfs-map-logical"
btrfs-progs_files += "/usr/sbin/btrfs-restore"
btrfs-progs_files += "/usr/sbin/btrfs-show"
btrfs-progs_files += "/usr/sbin/btrfs-vol"
btrfs-progs_files += "/usr/sbin/btrfs-zero-log"
btrfs-progs_files += "/usr/sbin/btrfsck"
btrfs-progs_files += "/usr/sbin/btrfsctl"
btrfs-progs_files += "/usr/sbin/btrfstune"
btrfs-progs_files += "/usr/sbin/fsck.btrfs"
btrfs-progs_files += "/usr/sbin/mkfs.btrfs"

FILES_${PN}-docs = "${btrfs-progs-docs_files}"
FILES_${PN} = "${btrfs-progs_files}"

PKG_btrfs-progs-docs= "btrfs-progs-docs"
PKG_btrfs-progs= "btrfs-progs"

require btrfs-progs-extraconf.inc
