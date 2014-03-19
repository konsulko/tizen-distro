DESCRIPTION = "A collection of basic system utilities"
HOMEPAGE = "https://github.com/karelzak/util-linux"
SECTION = "Base/Utilities"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by uuidd 
PROVIDES += "uuidd"
RPROVIDES_uuidd += "uuidd"

#PROVIDES by libmount-devel 
PROVIDES += "libmount-devel"
RPROVIDES_libmount-devel += "libmount-devel"
RPROVIDES_libmount-devel += "libmount-dev"

#PROVIDES by util-linux-docs  
PROVIDES += "util-linux-docs "
RPROVIDES_util-linux-docs  += "util-linux-docs "

#PROVIDES by libblkid 
PROVIDES += "libblkid"
RPROVIDES_libblkid += "libblkid"

#PROVIDES by libuuid 
PROVIDES += "libuuid"
RPROVIDES_libuuid += "libuuid"

#PROVIDES by libmount 
PROVIDES += "libmount"
RPROVIDES_libmount += "libmount"

#PROVIDES by libblkid-devel 
PROVIDES += "libblkid-devel"
RPROVIDES_libblkid-devel += "libblkid-devel"
RPROVIDES_libblkid-devel += "libblkid-dev"

#PROVIDES by util-linux 
PROVIDES += "util-linux"
RPROVIDES_util-linux += "util-linux"
# the PROVIDES rules is ignore "eject  "
PROVIDES += "eject"
RPROVIDES_util-linux += "eject"
# the PROVIDES rules is ignore "base = 2.24-0"
PROVIDES += "base"
RPROVIDES_util-linux += "base"
# the PROVIDES rules is ignore "login = 4.0-33.7"
PROVIDES += "login"
RPROVIDES_util-linux += "login"
# the PROVIDES rules is ignore "util = 2.24-0"
PROVIDES += "util"
RPROVIDES_util-linux += "util"
# the PROVIDES rules is ignore "uuid-runtime = 2.24-0"
PROVIDES += "uuid-runtime"
RPROVIDES_util-linux += "uuid-runtime"

#PROVIDES by libuuid-devel 
PROVIDES += "libuuid-devel"
RPROVIDES_libuuid-devel += "libuuid-devel"
RPROVIDES_libuuid-devel += "libuuid-dev"

#PROVIDES by util-linux-locale  
PROVIDES += "util-linux-locale "
RPROVIDES_util-linux-locale  += "util-linux-locale "
# the PROVIDES rules is ignore "util-linux-lang-all = 2.24"
PROVIDES += "util-linux-lang-all"
RPROVIDES_util-linux-locale  += "util-linux-lang-all"

RDEPENDS = ""
#RDEPENDS of libmount-devel (libmount-devel)
RDEPENDS_libmount-devel += "libmount"

#RDEPENDS of libblkid-devel (libblkid-devel)
RDEPENDS_libblkid-devel += "libblkid"

#RDEPENDS of util-linux (${PN})
RDEPENDS_${PN} += "/usr/bin/sed"

#RDEPENDS of libuuid-devel (libuuid-devel)
RDEPENDS_libuuid-devel += "libuuid"

#RDEPENDS of util-linux-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "util-linux"


DEPENDS = ""
#DEPENDS of util-linux 
DEPENDS += "zlib-devel"
DEPENDS += "ncurses"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libtool-cross"
DEPENDS += "readline"
DEPENDS += "fdupes-native"
DEPENDS += "pam"
DEPENDS += "binutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n util-linux-2.24 
 cp ${S}/packaging/util-linux.manifest .
 #
 # nologin
 cp ${S}/packaging/nologin.c ${S}/packaging/nologin.8   .
 
 
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
 
 autoreconf -fi
 export SUID_CFLAGS="-fpie"
 export SUID_LDFLAGS="-pie"
 
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
   --enable-mesg \
   --enable-partx \
   --disable-kill \
   --enable-write \
   --enable-line \
   --enable-new-mount \
   --enable-login-utils \
   --enable-mountpoint \
   --disable-use-tty-group \
   --disable-static \
   --disable-silent-rules \
   --disable-rpath
 #
 make -j16
 #
 ${HOST_SYS}-gcc -fwhole-program -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -o nologin nologin.c
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}{/etc/pam.d,/usr/share/man/man{1,8},/usr/bin,/usr/sbin,/usr/share/info}
 mkdir -p ${D}/var/lib/libuuid/
 mkdir -p ${D}/var/run/uuidd/
 install -m 644 ${S}/packaging/blkid.conf ${D}/etc/blkid.conf
 install -m 644 ${S}/packaging/login.pamd ${D}/etc/pam.d/login
 install -m 644 ${S}/packaging/remote.pamd ${D}/etc/pam.d/remote
 install -m 644 ${S}/packaging/su.pamd ${D}/etc/pam.d/su
 install -m 644 ${S}/packaging/su.pamd ${D}/etc/pam.d/su-l
 install -d -m 755 ${D}/etc/default
 install -m 644 ${S}/packaging/su.default ${D}/etc/default/su
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -m 644 ${S}/packaging/etc_filesystems ${D}/etc/filesystems
 install -m 755 nologin ${D}//usr/sbin
 rm -f ${D}//usr/lib/libblkid.la
 rm -f ${D}//usr/lib/libuuid.la
 rm -f ${D}//usr/lib/libmount.la
 install -m 644 nologin.8 ${D}/usr/share/man/man8
 echo -e "#! /bin/sh\n/sbin/blockdev --flushbufs \$1" > ${D}/usr/sbin/flushb
 chmod 755 ${D}/usr/sbin/flushb
 # Stupid hack so we don't have a tcsh dependency
 chmod 644 ${D}/usr/share/doc/util-linux/getopt/getopt*.tcsh
 # Following files we don't want to package, so remove them
 rm -f ${D}/usr/bin/pg
 rm -f ${D}/usr/share/man/man1/pg.1*
 rm -rf ${D}/usr/share/bash-completion
 # Do not package these files to get rid of the perl dependency
 rm -f ${D}/usr/bin/chkdupexe
 rm -f ${D}/usr/share/man/man1/chkdupexe.1
 # we use this tools from pwdutils
 rm -f ${D}//usr/bin/{chfn,chsh,newgrp}
 rm -f ${D}//usr/sbin/{vigr,vipw}
 rm -f ${D}//usr/share/man/man1/{chfn.1*,chsh.1*,newgrp.1*}
 rm -f ${D}//usr/share/man/man8/{vigr.8*,vipw.8*}
 
 
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} util-linux util-linux.lang
 # create list of setarch(8) symlinks
 find  ${D}/usr/bin/ -regextype posix-egrep -type l \
   -regex ".*(linux32|linux64|s390|s390x|i386|ppc|ppc64|ppc32|sparc|sparc64|sparc32|sparc32bash|mips|mips64|mips32|ia64|x86_64|parisc|parisc32|parisc64)$" \
   -printf "/usr/bin/%f\n" >> util-linux.files
 # clock.txt from uuidd is a ghost file
 touch ${D}/var/lib/libuuid/clock.txt
 # rcuuidd helper
 
 rm -rf ${D}//usr/share/man/ru
 
 # remove duplicate manpages
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}//usr/share/man | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
 
}

PACKAGES = ""
PACKAGES += "uuidd"
PACKAGES += "libmount-devel"
PACKAGES += "util-linux-docs"
PACKAGES += "libblkid"
PACKAGES += "libuuid"
PACKAGES += "libmount"
PACKAGES += "util-linux-locale"
PACKAGES += "util-linux"
PACKAGES += "libuuid-devel"
PACKAGES += "libblkid-devel"

uuidd_files = ""
uuidd_files += "util-linux.manifest"

libmount-devel_files = ""
libmount-devel_files += "util-linux.manifest"
libmount-devel_files += "/usr/lib/libmount.so"
libmount-devel_files += "/usr/include/libmount"
libmount-devel_files += "/usr/include/libmount/libmount.h"
libmount-devel_files += "/usr/lib/pkgconfig/mount.pc"

util-linux-docs_files = ""
util-linux-docs_files += "/usr/share/info"
util-linux-docs_files += "/usr/share/man"
util-linux-docs_files += "/usr/share/doc/util-linux/getopt"

libblkid_files = ""
libblkid_files += "util-linux.manifest"
libblkid_files += "/usr/lib/libblkid.so.1"
libblkid_files += "/usr/lib/libblkid.so.1.*"

libuuid_files = ""
libuuid_files += "util-linux.manifest"
libuuid_files += "/usr/lib/libuuid.so.1"
libuuid_files += "/usr/lib/libuuid.so.1.*"

libmount_files = ""
libmount_files += "util-linux.manifest"
libmount_files += "/usr/lib/libmount.so.1"
libmount_files += "/usr/lib/libmount.so.1.*"

util-linux-locale_files = ""

util-linux_files = ""
util-linux_files += "util-linux.manifest"
util-linux_files += "/etc/filesystems"
util-linux_files += "/etc/blkid.conf"
util-linux_files += "/etc/pam.d/login"
util-linux_files += "/etc/pam.d/remote"
util-linux_files += "/etc/pam.d/su"
util-linux_files += "/etc/pam.d/su-l"
util-linux_files += "/etc/default/su"
util-linux_files += "/usr/bin/su"
util-linux_files += "/usr/bin/cal"
util-linux_files += "/usr/bin/eject"
util-linux_files += "/usr/bin/lslocks"
util-linux_files += "/usr/bin/utmpdump"
util-linux_files += "/usr/bin/wdctl"
util-linux_files += "/usr/sbin/resizepart"
util-linux_files += "/usr/sbin/sulogin"
util-linux_files += "/usr/bin/login"
util-linux_files += "/usr/bin/chrt"
util-linux_files += "/usr/bin/col"
util-linux_files += "/usr/bin/colcrt"
util-linux_files += "/usr/bin/colrm"
util-linux_files += "/usr/bin/column"
util-linux_files += "/usr/bin/dmesg"
util-linux_files += "/usr/bin/fallocate"
util-linux_files += "/usr/bin/findmnt"
util-linux_files += "/usr/bin/flock"
util-linux_files += "/usr/bin/getopt"
util-linux_files += "/usr/bin/hexdump"
util-linux_files += "/usr/bin/ionice"
util-linux_files += "/usr/bin/ipcmk"
util-linux_files += "/usr/bin/ipcrm"
util-linux_files += "/usr/bin/ipcs"
util-linux_files += "/usr/bin/isosize"
util-linux_files += "/usr/bin/line"
util-linux_files += "/usr/bin/logger"
util-linux_files += "/usr/bin/look"
util-linux_files += "/usr/bin/lsblk"
util-linux_files += "/usr/bin/lscpu"
util-linux_files += "/usr/bin/mcookie"
util-linux_files += "/usr/bin/mesg"
util-linux_files += "/usr/bin/more"
util-linux_files += "/usr/bin/mount"
util-linux_files += "/usr/bin/mountpoint"
util-linux_files += "/usr/bin/namei"
util-linux_files += "/usr/bin/prlimit"
util-linux_files += "/usr/bin/rename"
util-linux_files += "/usr/bin/renice"
util-linux_files += "/usr/bin/rev"
util-linux_files += "/usr/bin/script"
util-linux_files += "/usr/bin/scriptreplay"
util-linux_files += "/usr/bin/setarch"
util-linux_files += "/usr/bin/setsid"
util-linux_files += "/usr/bin/tailf"
util-linux_files += "/usr/bin/taskset"
util-linux_files += "/usr/bin/ul"
util-linux_files += "/usr/bin/umount"
util-linux_files += "/usr/bin/unshare"
util-linux_files += "/usr/bin/uuidgen"
util-linux_files += "/usr/sbin/addpart"
util-linux_files += "/usr/sbin/agetty"
util-linux_files += "/usr/sbin/blkid"
util-linux_files += "/usr/sbin/blockdev"
util-linux_files += "/usr/sbin/chcpu"
util-linux_files += "/usr/sbin/ctrlaltdel"
util-linux_files += "/usr/sbin/delpart"
util-linux_files += "/usr/sbin/findfs"
util-linux_files += "/usr/sbin/fsck"
util-linux_files += "/usr/sbin/fsck.minix"
util-linux_files += "/usr/sbin/fsck.cramfs"
util-linux_files += "/usr/sbin/fsfreeze"
util-linux_files += "/usr/sbin/fstrim"
util-linux_files += "/usr/sbin/ldattach"
util-linux_files += "/usr/sbin/losetup"
util-linux_files += "/usr/sbin/mkfs"
util-linux_files += "/usr/sbin/mkfs.bfs"
util-linux_files += "/usr/sbin/mkfs.minix"
util-linux_files += "/usr/sbin/mkfs.cramfs"
util-linux_files += "/usr/sbin/mkswap"
util-linux_files += "/usr/sbin/nologin"
util-linux_files += "/usr/sbin/raw"
util-linux_files += "/usr/sbin/partx"
util-linux_files += "/usr/sbin/pivot_root"
util-linux_files += "/usr/sbin/rtcwake"
util-linux_files += "/usr/sbin/swaplabel"
util-linux_files += "/usr/sbin/swapoff"
util-linux_files += "/usr/sbin/swapon"
util-linux_files += "/usr/sbin/switch_root"
util-linux_files += "/usr/sbin/wipefs"
util-linux_files += "/usr/bin/whereis"
util-linux_files += "/usr/sbin/flushb"
util-linux_files += "/usr/sbin/readprofile"
util-linux_files += "/usr/sbin/fdisk"
util-linux_files += "/usr/sbin/cfdisk"
util-linux_files += "/usr/sbin/sfdisk"
util-linux_files += "/usr/bin/cytune"
util-linux_files += "/usr/sbin/fdformat"
util-linux_files += "/usr/sbin/hwclock"
util-linux_files += "/usr/bin/setterm"
util-linux_files += "/usr/sbin/blkdiscard"
util-linux_files += "/usr/sbin/runuser"
util-linux_files += "/usr/bin/last"
util-linux_files += "/usr/bin/lastb"
util-linux_files += "/usr/bin/nsenter"

libuuid-devel_files = ""
libuuid-devel_files += "util-linux.manifest"
libuuid-devel_files += "/usr/lib/libuuid.so"
libuuid-devel_files += "/usr/include/uuid"
libuuid-devel_files += "/usr/include/uuid/uuid.h"
libuuid-devel_files += "/usr/lib/pkgconfig/uuid.pc"

libblkid-devel_files = ""
libblkid-devel_files += "util-linux.manifest"
libblkid-devel_files += "/usr/lib/libblkid.so"
libblkid-devel_files += "/usr/include/blkid"
libblkid-devel_files += "/usr/include/blkid/blkid.h"
libblkid-devel_files += "/usr/lib/pkgconfig/blkid.pc"

FILES_uuidd = "${uuidd_files}"
FILES_libmount-devel = "${libmount-devel_files}"
FILES_${PN}-docs = "${util-linux-docs_files}"
FILES_libblkid = "${libblkid_files}"
FILES_libuuid = "${libuuid_files}"
FILES_libmount = "${libmount_files}"
FILES_${PN}-locale = "${util-linux-locale_files}"
FILES_${PN} = "${util-linux_files}"
FILES_libuuid-devel = "${libuuid-devel_files}"
FILES_libblkid-devel = "${libblkid-devel_files}"

PKG_uuidd= "uuidd"
PKG_libmount-devel= "libmount-devel"
PKG_util-linux-docs= "util-linux-docs"
PKG_libblkid= "libblkid"
PKG_libuuid= "libuuid"
PKG_libmount= "libmount"
PKG_util-linux-locale= "util-linux-locale"
PKG_util-linux= "util-linux"
PKG_libuuid-devel= "libuuid-devel"
PKG_libblkid-devel= "libblkid-devel"

require util-linux-extraconf.inc
