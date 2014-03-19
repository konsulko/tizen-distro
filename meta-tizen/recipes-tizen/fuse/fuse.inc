DESCRIPTION = "User space File System"
HOMEPAGE = "http://fuse.sourceforge.net"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+ and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by fuse-devel 
PROVIDES += "fuse-devel"
RPROVIDES_fuse-devel += "fuse-devel"
RPROVIDES_fuse-devel += "fuse-dev"

#PROVIDES by libfuse 
PROVIDES += "libfuse"
RPROVIDES_libfuse += "libfuse"

#PROVIDES by fuse 
PROVIDES += "fuse"
RPROVIDES_fuse += "fuse"

#PROVIDES by fuse-docs  
PROVIDES += "fuse-docs "
RPROVIDES_fuse-docs  += "fuse-docs "

#PROVIDES by libulockmgr 
PROVIDES += "libulockmgr"
RPROVIDES_libulockmgr += "libulockmgr"

RDEPENDS = ""
#RDEPENDS of fuse-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libulockmgr"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "fuse"
RDEPENDS_${PN}-devel += "libfuse"

#RDEPENDS of fuse (${PN})
RDEPENDS_${PN} += "util-linux"
RDEPENDS_${PN} += "which"


DEPENDS = ""
#DEPENDS of fuse 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/fuse.manifest .
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS -g -fno-strict-aliasing"
 export MOUNT_FUSE_PATH=/usr/sbin
 
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
         --infodir=/usr/share/info --with-pic \
     --with-pkgconfigdir=/usr/lib/pkgconfig \
     --enable-lib \
     --disable-example \
     --enable-static
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
 rm -rf $RPM_BUILD_ROOT//etc/init.d
 
 
}

PACKAGES = ""
PACKAGES += "libulockmgr"
PACKAGES += "libfuse"
PACKAGES += "fuse"
PACKAGES += "fuse-docs"
PACKAGES += "fuse-devel"

libulockmgr_files = ""
libulockmgr_files += "fuse.manifest"
libulockmgr_files += "/usr/lib/libulockmgr.so.*"

libfuse_files = ""
libfuse_files += "fuse.manifest"
libfuse_files += "/usr/lib/libfuse.so.2*"

fuse_files = ""
fuse_files += "fuse.manifest"
fuse_files += "/usr/sbin/mount.fuse"
fuse_files += "/usr/bin/ulockmgr_server"
fuse_files += "/etc/udev/rules.d/99-fuse.rules"

fuse-docs_files = ""
fuse-docs_files += "/usr/share/info"
fuse-docs_files += "/usr/share/man"

fuse-devel_files = ""
fuse-devel_files += "fuse.manifest"
fuse-devel_files += "/usr/lib/libfuse.so"
fuse-devel_files += "/usr/lib/libulockmgr.so"
fuse-devel_files += "/usr/include/fuse.h"
fuse-devel_files += "/usr/include/fuse"
fuse-devel_files += "/usr/lib/pkgconfig/*.pc"
fuse-devel_files += "/usr/include/ulockmgr.h"

FILES_libulockmgr = "${libulockmgr_files}"
FILES_lib${PN} = "${libfuse_files}"
FILES_${PN} = "${fuse_files}"
FILES_${PN}-docs = "${fuse-docs_files}"
FILES_${PN}-devel = "${fuse-devel_files}"

PKG_libulockmgr= "libulockmgr"
PKG_libfuse= "libfuse"
PKG_fuse= "fuse"
PKG_fuse-docs= "fuse-docs"
PKG_fuse-devel= "fuse-devel"

require fuse-extraconf.inc
