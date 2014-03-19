DESCRIPTION = "Utilities for the Second Extended File System"
HOMEPAGE = "http://e2fsprogs.sourceforge.net"
SECTION = "System/Filesystems"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libext2fs 
PROVIDES += "libext2fs"
RPROVIDES_libext2fs += "libext2fs"

#PROVIDES by e2fsprogs-devel 
PROVIDES += "e2fsprogs-devel"
RPROVIDES_e2fsprogs-devel += "e2fsprogs-devel"
RPROVIDES_e2fsprogs-devel += "e2fsprogs-dev"

#PROVIDES by e2fsprogs 
PROVIDES += "e2fsprogs"
RPROVIDES_e2fsprogs += "e2fsprogs"

#PROVIDES by e2fsprogs-docs  
PROVIDES += "e2fsprogs-docs "
RPROVIDES_e2fsprogs-docs  += "e2fsprogs-docs "

#PROVIDES by libcom_err 
PROVIDES += "libcom_err"
RPROVIDES_libcom_err += "libcom_err"

#PROVIDES by libcom_err-devel 
PROVIDES += "libcom_err-devel"
RPROVIDES_libcom_err-devel += "libcom_err-devel"
RPROVIDES_libcom_err-devel += "libcom_err-dev"

#PROVIDES by libext2fs-devel 
PROVIDES += "libext2fs-devel"
RPROVIDES_libext2fs-devel += "libext2fs-devel"
RPROVIDES_libext2fs-devel += "libext2fs-dev"

RDEPENDS = ""
#RDEPENDS of e2fsprogs-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libuuid-dev"
RDEPENDS_${PN}-devel += "libblkid-dev"
RDEPENDS_${PN}-devel += "libext2fs-dev"

#RDEPENDS of e2fsprogs (${PN})
RDEPENDS_${PN} += "libext2fs"
RDEPENDS_${PN} += "libcom_err"

#RDEPENDS of libcom_err-devel (libcom_err-devel)
RDEPENDS_libcom_err-devel += "glibc-dev"
RDEPENDS_libcom_err-devel += "libcom_err"

#RDEPENDS of libext2fs-devel (libext2fs-devel)
RDEPENDS_libext2fs-devel += "libext2fs"
RDEPENDS_libext2fs-devel += "libcom_err-dev"


DEPENDS = ""
#DEPENDS of e2fsprogs 
DEPENDS += "autoconf-native"
DEPENDS += "libuuid-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "libblkid-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/e2fsprogs.manifest .
 
 
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
   --disable-evms \
   --with-root-prefix=''   \
   --enable-elf-shlibs \
   --disable-libblkid \
   --disable-libuuid \
   --disable-uuidd \
   --disable-nls \
   --disable-fsck \
   CFLAGS="$RPM_OPT_FLAGS"
 make -j16 V=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install install-libs DESTDIR=$RPM_BUILD_ROOT ELF_INSTALL_DIR=//usr/lib
 find "${D}//usr/lib" -type f -name "*.a" \
        -print -delete
 # Let boot continue even if system clock is wrong
 install -p -m 644 ${S}/packaging/e2fsck.conf ${D}/etc/e2fsck.conf
 
 
 rm $RPM_BUILD_ROOT/usr/lib/e2initrd_helper
 rm -f $RPM_BUILD_ROOT//usr/sbin/mkfs.ext4dev
 rm -f $RPM_BUILD_ROOT//usr/sbin/fsck.ext4dev
 rm -f $RPM_BUILD_ROOT/usr/share/man/man8/mkfs.ext4dev.8*
 rm -f $RPM_BUILD_ROOT/usr/share/man/man8/fsck.ext4dev.8*
 rm -v ${D}/usr/include/quota/mkquota.h
 rm -v ${D}/usr/lib/pkgconfig/quota.pc
 
 
}

PACKAGES = ""
PACKAGES += "libext2fs"
PACKAGES += "e2fsprogs-devel"
PACKAGES += "e2fsprogs"
PACKAGES += "libcom_err"
PACKAGES += "e2fsprogs-docs"
PACKAGES += "libcom_err-devel"
PACKAGES += "libext2fs-devel"

libext2fs_files = ""
libext2fs_files += "e2fsprogs.manifest"
libext2fs_files += "/usr/lib/libext2fs.so.*"
libext2fs_files += "/usr/lib/libe2p.so.*"

e2fsprogs-devel_files = ""
e2fsprogs-devel_files += "e2fsprogs.manifest"
e2fsprogs-devel_files += "README"

e2fsprogs_files = ""
e2fsprogs_files += "e2fsprogs.manifest"
e2fsprogs_files += "MIT COPYING"
e2fsprogs_files += "RELEASE-NOTES README"
e2fsprogs_files += "/etc/e2fsck.conf"
e2fsprogs_files += "/etc/mke2fs.conf"
e2fsprogs_files += "/usr/sbin/badblocks"
e2fsprogs_files += "/usr/sbin/debugfs"
e2fsprogs_files += "/usr/sbin/dumpe2fs"
e2fsprogs_files += "/usr/sbin/e2undo"
e2fsprogs_files += "/usr/sbin/e2fsck"
e2fsprogs_files += "/usr/sbin/e2label"
e2fsprogs_files += "/usr/sbin/fsck.ext2"
e2fsprogs_files += "/usr/sbin/fsck.ext3"
e2fsprogs_files += "/usr/sbin/fsck.ext4"
e2fsprogs_files += "/usr/sbin/mke2fs"
e2fsprogs_files += "/usr/sbin/mkfs.ext2"
e2fsprogs_files += "/usr/sbin/mkfs.ext3"
e2fsprogs_files += "/usr/sbin/mkfs.ext4"
e2fsprogs_files += "/usr/sbin/resize2fs"
e2fsprogs_files += "/usr/sbin/tune2fs"
e2fsprogs_files += "/usr/sbin/e2image"
e2fsprogs_files += "/usr/sbin/logsave"
e2fsprogs_files += "/usr/bin/chattr"
e2fsprogs_files += "/usr/bin/lsattr"
e2fsprogs_files += "/usr/sbin/mklost+found"
e2fsprogs_files += "/usr/sbin/filefrag"
e2fsprogs_files += "/usr/sbin/e2freefrag"
e2fsprogs_files += "/usr/sbin/e4defrag"

libcom_err_files = ""
libcom_err_files += "e2fsprogs.manifest"
libcom_err_files += "/usr/lib/libcom_err.so.*"
libcom_err_files += "/usr/lib/libss.so.*"

e2fsprogs-docs_files = ""
e2fsprogs-docs_files += "/usr/share/info"
e2fsprogs-docs_files += "/usr/share/man"

libcom_err-devel_files = ""
libcom_err-devel_files += "e2fsprogs.manifest"
libcom_err-devel_files += "/usr/bin/compile_et"
libcom_err-devel_files += "/usr/bin/mk_cmds"
libcom_err-devel_files += "/usr/lib/libcom_err.so"
libcom_err-devel_files += "/usr/lib/libss.so"
libcom_err-devel_files += "/usr/lib/pkgconfig/com_err.pc"
libcom_err-devel_files += "/usr/lib/pkgconfig/ss.pc"
libcom_err-devel_files += "/usr/include/com_err.h"
libcom_err-devel_files += "/usr/include/et"
libcom_err-devel_files += "/usr/include/ss"
libcom_err-devel_files += "/usr/share/et"
libcom_err-devel_files += "/usr/share/ss"

libext2fs-devel_files = ""
libext2fs-devel_files += "e2fsprogs.manifest"
libext2fs-devel_files += "/usr/lib/libext2fs.so"
libext2fs-devel_files += "/usr/lib/libe2p.so"
libext2fs-devel_files += "/usr/include/ext2fs"
libext2fs-devel_files += "/usr/include/e2p"
libext2fs-devel_files += "/usr/lib/pkgconfig/e2p.pc"
libext2fs-devel_files += "/usr/lib/pkgconfig/ext2fs.pc"

FILES_libext2fs = "${libext2fs_files}"
FILES_${PN}-devel = "${e2fsprogs-devel_files}"
FILES_${PN} = "${e2fsprogs_files}"
FILES_libcom_err = "${libcom_err_files}"
FILES_${PN}-docs = "${e2fsprogs-docs_files}"
FILES_libcom_err-devel = "${libcom_err-devel_files}"
FILES_libext2fs-devel = "${libext2fs-devel_files}"

PKG_libext2fs= "libext2fs"
PKG_e2fsprogs-devel= "e2fsprogs-devel"
PKG_e2fsprogs= "e2fsprogs"
PKG_libcom_err= "libcom_err"
PKG_e2fsprogs-docs= "e2fsprogs-docs"
PKG_libcom_err-devel= "libcom_err-devel"
PKG_libext2fs-devel= "libext2fs-devel"

require e2fsprogs-extraconf.inc
