DESCRIPTION = "Device mapper utility"
HOMEPAGE = "http://sources.redhat.com/dm"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdevmapper 
PROVIDES += "libdevmapper"
RPROVIDES_libdevmapper += "libdevmapper"

#PROVIDES by device-mapper 
PROVIDES += "device-mapper"
RPROVIDES_device-mapper += "device-mapper"

#PROVIDES by device-mapper-devel 
PROVIDES += "device-mapper-devel"
RPROVIDES_device-mapper-devel += "device-mapper-devel"
RPROVIDES_device-mapper-devel += "device-mapper-dev"

RDEPENDS = ""
#RDEPENDS of device-mapper (${PN})
RDEPENDS_${PN} += "libdevmapper"

#RDEPENDS of device-mapper-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libdevmapper"
RDEPENDS_${PN}-devel += "device-mapper"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n LVM2.2.02.98
 
 
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
         --exec-prefix="" \
         --bindir=""/bin \
         --sbindir=""/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=""/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --with-user= --with-group= --with-device-uid=0 --with-device-gid=6 --with-device-mode=0660 --enable-pkgconfig
 make device-mapper
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install_device-mapper DESTDIR=${D} usrlibdir=${D}/usr/lib
 sed -i 's/ (.*)//g' ${D}/usr/lib/pkgconfig/*.pc
 
 
 
}

PACKAGES = ""
PACKAGES += "libdevmapper"
PACKAGES += "device-mapper"
PACKAGES += "device-mapper-devel"

libdevmapper_files = ""

device-mapper_files = ""
device-mapper_files += "LGPL-2.1 COPYING COPYING.LIB"
device-mapper_files += "/usr/share/man/man8/dmsetup.8.gz"

device-mapper-devel_files = ""
device-mapper-devel_files += "/usr/include/libdevmapper.h"
device-mapper-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_libdevmapper = "${libdevmapper_files}"
FILES_${PN} = "${device-mapper_files}"
FILES_${PN}-devel = "${device-mapper-devel_files}"

PKG_libdevmapper= "libdevmapper"
PKG_device-mapper= "device-mapper"
PKG_device-mapper-devel= "device-mapper-devel"

require device-mapper-extraconf.inc
