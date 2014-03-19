DESCRIPTION = "FUSE module for filesystem on top of an SQLite db"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "LGPLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsqlfs 
PROVIDES += "libsqlfs"
RPROVIDES_libsqlfs += "libsqlfs"

RDEPENDS = ""
#RDEPENDS of libsqlfs (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/usr/bin/find"


DEPENDS = ""
#DEPENDS of libsqlfs 
DEPENDS += "libcap"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "attr"
DEPENDS += "pkgconfig(fuse)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/libsqlfs.manifest .
 
 
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
 
 #
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
         --infodir=/usr/share/info
 #make
 
 gcc  $CFLAGS -g \
                 -DFUSE \
                 -D_GNU_SOURCE \
                 -D_FILE_OFFSET_BITS=64 \
                 -D_REENTRANT \
                 -DFUSE_USE_VERSION=25 \
                 -I/usr/include -I. \
                 sqlfs.c fuse_main.c \
                 -o libsqlfs_mount \
                 $LDFLAGS \
                 -L/usr/lib \
                 -lpthread \
                 -lfuse -lrt\
                 -lsqlite3 -ldl -lcap
 
 gcc $CFLAGS -g \
                 sqlfs_txn_cmd.c \
                 -o sqlfs_txn_cmd \
                 $LDFLAGS
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 install -m 0755 libsqlfs_mount ${D}/usr/bin/
 install -m 0755 sqlfs_txn_cmd ${D}/usr/bin/
 #mkdir -p ${D}/sbin
 #install -m 0755 ${S}/packaging/mount.fuse.libsqlfs ${D}/sbin/
 
 #mkdir -p ${D}/usr/lib/systemd/system/basic.target.wants
 #install -m 0644 ${S}/packaging/opt-var-kdb-db.mount ${D}/usr/lib/systemd/system/
 #install -m 0644 ${S}/packaging/opt-var-kdb-db-libsqlfs.service ${D}/usr/lib/systemd/system/
 #install -m 0644 ${S}/packaging/opt-var-kdb-db-smack-labels.service ${D}/usr/lib/systemd/system/
 #ln -sf ../opt-var-kdb-db-libsqlfs.service ${D}/usr/lib/systemd/system/basic.target.wants/
 #ln -sf ../opt-var-kdb-db-smack-labels.service ${D}/usr/lib/systemd/system/basic.target.wants/
 
 mkdir -p ${D}/etc/rc.d/init.d
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc4.d
 install -m 0755 sqlfs-mount ${D}/etc/rc.d/init.d
 ln -s ../init.d/sqlfs-mount ${D}/etc/rc.d/rc3.d/S03sqlfs-mount
 ln -s ../init.d/sqlfs-mount ${D}/etc/rc.d/rc4.d/S03sqlfs-mount
 
 #mkdir -p ${D}/etc/preconf.d
 #install -m 0755 ${S}/packaging/libsqlfs.preinit ${D}/etc/preconf.d
 
 mkdir -p ${D}/usr/share/license
 install COPYING ${D}/usr/share/license/libsqlfs
 
 
}

PACKAGES = ""
PACKAGES += "libsqlfs"

libsqlfs_files = ""
libsqlfs_files += "libsqlfs.manifest"
libsqlfs_files += "/etc/rc.d/init.d/sqlfs-mount"
libsqlfs_files += "/etc/rc.d/rc3.d/S03sqlfs-mount"
libsqlfs_files += "/etc/rc.d/rc4.d/S03sqlfs-mount"
libsqlfs_files += "/usr/bin/sqlfs_txn_cmd"
libsqlfs_files += "/usr/bin/libsqlfs_mount"
libsqlfs_files += "/usr/share/license/libsqlfs"

FILES_${PN} = "${libsqlfs_files}"

PKG_libsqlfs= "libsqlfs"

require libsqlfs-extraconf.inc
