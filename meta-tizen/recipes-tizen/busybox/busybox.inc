DESCRIPTION = "The Swiss Army Knife of Embedded Linux"
HOMEPAGE = "http://www.busybox.net/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by busybox 
PROVIDES += "busybox"
RPROVIDES_busybox += "busybox"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/busybox.manifest .
 cp -a ${S}/packaging/busybox.tizen.config .config
 
 
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
 
 export VERBOSE=-v
 export BUILD_VERBOSE=2
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing"
 export CC="gcc"
 export HOSTCC=gcc
 make -e oldconfig
 make -e -j16
 make -e doc busybox.links -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}/usr/bin
 install -d ${D}/usr/share/busybox
 install busybox.links ${D}/usr/share/busybox
 install applets/install.sh ${D}/usr/bin/busybox.install
 install busybox ${D}/usr/bin
 
 
}

PACKAGES = ""
PACKAGES += "busybox"

busybox_files = ""
busybox_files += "busybox.manifest"
busybox_files += "/usr/bin/busybox"
busybox_files += "/usr/bin/busybox.install"
busybox_files += "/usr/share/busybox"
busybox_files += "/usr/share/busybox/busybox.links"

FILES_${PN} = "${busybox_files}"

PKG_busybox= "busybox"

require busybox-extraconf.inc
