DESCRIPTION = "Utilities for video4linux and DVB devices"
HOMEPAGE = "http://linuxtv.org/downloads/v4l-utils/"
SECTION = "Multimedia/Utilities"
LICENSE = "GPL-2.0+ and GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by v4l-utils-devel-tools 
PROVIDES += "v4l-utils-devel-tools"
RPROVIDES_v4l-utils-devel-tools += "v4l-utils-devel-tools"
RPROVIDES_v4l-utils-devel-tools += "v4l-utils-dev"

#PROVIDES by v4l-utils 
PROVIDES += "v4l-utils"
RPROVIDES_v4l-utils += "v4l-utils"

#PROVIDES by libv4l-devel 
PROVIDES += "libv4l-devel"
RPROVIDES_libv4l-devel += "libv4l-devel"
RPROVIDES_libv4l-devel += "libv4l-dev"

#PROVIDES by libv4l 
PROVIDES += "libv4l"
RPROVIDES_libv4l += "libv4l"

RDEPENDS = ""
#RDEPENDS of v4l-utils-devel-tools (${PN}-devel-tools)
RDEPENDS_${PN}-devel-tools += "libv4l"

#RDEPENDS of v4l-utils (${PN})
RDEPENDS_${PN} += "udev"
RDEPENDS_${PN} += "libv4l"

#RDEPENDS of libv4l-devel (libv4l-devel)
RDEPENDS_libv4l-devel += "libv4l"


DEPENDS = ""
#DEPENDS of v4l-utils 
DEPENDS += "libjpeg-turbo"
DEPENDS += "systemd"
DEPENDS += "sysfsutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing"
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} PREFIX=/usr LIBDIR=/usr/lib
 
 
 
}

PACKAGES = ""
PACKAGES += "v4l-utils-devel-tools"
PACKAGES += "v4l-utils"
PACKAGES += "libv4l-devel"
PACKAGES += "libv4l"

v4l-utils-devel-tools_files = ""
v4l-utils-devel-tools_files += "/usr/bin/decode_tm6000"
v4l-utils-devel-tools_files += "/usr/bin/v4l2-compliance"
v4l-utils-devel-tools_files += "/usr/sbin/v4l2-dbg"

v4l-utils_files = ""
v4l-utils_files += "LGPL-2.1+ COPYING"
v4l-utils_files += "/etc/rc_keymaps"
v4l-utils_files += "/etc/rc_keymaps/*"
v4l-utils_files += "/etc/rc_maps.cfg"
v4l-utils_files += "/usr/bin/cx18-ctl"
v4l-utils_files += "/usr/bin/dvb-*"
v4l-utils_files += "/usr/bin/dvbv5-*"
v4l-utils_files += "/usr/bin/ir-keytable"
v4l-utils_files += "/usr/bin/ivtv-ctl"
v4l-utils_files += "/usr/bin/v4l2-ctl"
v4l-utils_files += "/usr/bin/v4l2-sysfs-path"
v4l-utils_files += "/usr/lib/udev/rules.d/70-infrared.rules"
v4l-utils_files += "/usr/share/man/man1/ir-keytable.1.gz"

libv4l-devel_files = ""
libv4l-devel_files += "README.lib-multi-threading"
libv4l-devel_files += "/usr/include/libv4l*.h"
libv4l-devel_files += "/usr/lib/libv4l*.so"
libv4l-devel_files += "/usr/lib/pkgconfig/*.pc"

libv4l_files = ""
libv4l_files += "COPYING.LIB"
libv4l_files += "/usr/lib/libv4l/"
libv4l_files += "/usr/lib/libv4l1.so.*"
libv4l_files += "/usr/lib/libv4l2.so.*"
libv4l_files += "/usr/lib/libv4lconvert.so.*"

FILES_${PN}-devel-tools = "${v4l-utils-devel-tools_files}"
FILES_${PN} = "${v4l-utils_files}"
FILES_libv4l-devel = "${libv4l-devel_files}"
FILES_libv4l = "${libv4l_files}"

PKG_v4l-utils-devel-tools= "v4l-utils-devel-tools"
PKG_v4l-utils= "v4l-utils"
PKG_libv4l-devel= "libv4l-devel"
PKG_libv4l= "libv4l"

require v4l-utils-extraconf.inc
