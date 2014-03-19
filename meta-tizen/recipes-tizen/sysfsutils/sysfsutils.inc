DESCRIPTION = "System Utilities Package / Libsysfs"
HOMEPAGE = "http://linux-diag.sourceforge.net"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sysfsutils-devel 
PROVIDES += "sysfsutils-devel"
RPROVIDES_sysfsutils-devel += "sysfsutils-devel"
RPROVIDES_sysfsutils-devel += "sysfsutils-dev"

#PROVIDES by sysfsutils 
PROVIDES += "sysfsutils"
RPROVIDES_sysfsutils += "sysfsutils"
# the PROVIDES rules is ignore "libsysfs  "
PROVIDES += "libsysfs"
RPROVIDES_sysfsutils += "libsysfs"

RDEPENDS = ""
#RDEPENDS of sysfsutils-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "sysfsutils"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sysfsutils.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic
 oe_runmake -j16
 
 
 
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
 # don't install the tools
 rm -f ${D}//usr/bin/dlist_test
 rm -f ${D}//usr/bin/get_device
 rm -f ${D}//usr/bin/get_driver
 rm -f ${D}//usr/bin/get_module
 rm -f ${D}//usr/bin/testlibsysfs
 
 
}

PACKAGES = ""
PACKAGES += "sysfsutils-devel"
PACKAGES += "sysfsutils"

sysfsutils-devel_files = ""
sysfsutils-devel_files += "sysfsutils.manifest"
sysfsutils-devel_files += "/usr/include/sysfs"
sysfsutils-devel_files += "/usr/include/sysfs/libsysfs.h"
sysfsutils-devel_files += "/usr/include/sysfs/dlist.h"
sysfsutils-devel_files += "/usr/lib/libsysfs.so"

sysfsutils_files = ""
sysfsutils_files += "sysfsutils.manifest"
sysfsutils_files += "/usr/bin/systool"
sysfsutils_files += "/usr/share/man/man1/systool.1.gz"
sysfsutils_files += "/usr/lib/libsysfs.so.*"
sysfsutils_files += "README"

FILES_${PN}-devel = "${sysfsutils-devel_files}"
FILES_${PN} = "${sysfsutils_files}"

PKG_sysfsutils-devel= "sysfsutils-devel"
PKG_sysfsutils= "sysfsutils"

require sysfsutils-extraconf.inc
