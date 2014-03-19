DESCRIPTION = "Tools to Manage Multipathed Devices with the device-mapper"
HOMEPAGE = "http://christophe.varoqui.free.fr/"
SECTION = "System/Base"
LICENSE = "BSD-3-Clause  GPL-2.0+  LGPL-2.1+  MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by kpartx 
PROVIDES += "kpartx"
RPROVIDES_kpartx += "kpartx"

#PROVIDES by multipath-tools 
PROVIDES += "multipath-tools"
RPROVIDES_multipath-tools += "multipath-tools"

RDEPENDS = ""
#RDEPENDS of kpartx (kpartx)
RDEPENDS_kpartx += "device-mapper"

#RDEPENDS of multipath-tools (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "grep"
RDEPENDS_${PN} += "device-mapper"
RDEPENDS_${PN} += "kpartx"


DEPENDS = ""
#DEPENDS of multipath-tools 
DEPENDS += "libaio"
DEPENDS += "device-mapper"
DEPENDS += "readline-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n multipath-tools-0.4.9
 cp ${S}/packaging/multipath-tools.manifest .
 
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
 
 cd kpartx
 make CC="${HOST_SYS}-gcc" OPTFLAGS="$RPM_OPT_FLAGS" LIB=/usr/lib
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 pushd kpartx
 make DESTDIR=$RPM_BUILD_ROOT LIB=/usr/lib install
 popd
 
 
 
}

PACKAGES = ""
PACKAGES += "kpartx"
PACKAGES += "multipath-tools"

kpartx_files = ""
kpartx_files += "multipath-tools.manifest"
kpartx_files += "BSD-3-Clause ; GPL-2.0+ ; LGPL-2.1+ ; MIT COPYING"
kpartx_files += "/usr/lib/udev/rules.d/kpartx.rules"
kpartx_files += "/sbin/kpartx"
kpartx_files += "/lib/udev"
kpartx_files += "/lib/udev/kpartx_id"
kpartx_files += "/usr/share/man/man8/kpartx.8*"

multipath-tools_files = ""
multipath-tools_files += "multipath-tools.manifest"

FILES_kpartx = "${kpartx_files}"
FILES_${PN} = "${multipath-tools_files}"

PKG_kpartx= "kpartx"
PKG_multipath-tools= "multipath-tools"

require multipath-tools-extraconf.inc
