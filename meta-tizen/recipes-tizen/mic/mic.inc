DESCRIPTION = "Image Creator for Linux Distributions"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mic 
PROVIDES += "mic"
RPROVIDES_mic += "mic"

RDEPENDS = ""
#RDEPENDS of mic (${PN})
RDEPENDS_${PN} += "parted"
RDEPENDS_${PN} += "syslinux"
RDEPENDS_${PN} += "python-M2Crypto"
RDEPENDS_${PN} += "python-urlgrabber"
RDEPENDS_${PN} += "python-rpm"
RDEPENDS_${PN} += "qemu-linux-user"
RDEPENDS_${PN} += "dosfstools"
RDEPENDS_${PN} += "python-zypp"
RDEPENDS_${PN} += "/usr/bin/genisoimage"
RDEPENDS_${PN} += "device-mapper"
RDEPENDS_${PN} += "e2fsprogs"
RDEPENDS_${PN} += "python"
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "yum"
RDEPENDS_${PN} += "btrfs-progs"
RDEPENDS_${PN} += "kpartx"
RDEPENDS_${PN} += "gzip"
RDEPENDS_${PN} += "cpio"
RDEPENDS_${PN} += "util-linux"
RDEPENDS_${PN} += "squashfs"
RDEPENDS_${PN} += "bzip2"


DEPENDS = ""
#DEPENDS of mic 
DEPENDS += "python-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n mic-0.19
 cp ${S}/packaging/mic.manifest .
 
 
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
 
 CFLAGS="$RPM_OPT_FLAGS" /usr/bin/python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 /usr/bin/python setup.py install --root=$RPM_BUILD_ROOT -O1
 
 # install man page
 mkdir -p ${D}//usr/share/man/man1
 
 
}

PACKAGES = ""
PACKAGES += "mic"

mic_files = ""
mic_files += "mic.manifest"
mic_files += "doc/*"
mic_files += "README.rst AUTHORS COPYING ChangeLog"
mic_files += "/etc/mic"
mic_files += "/etc/mic/mic.conf"
mic_files += "/usr/lib/python2.7/site-packages/*"
mic_files += "/usr/lib/mic"
mic_files += "/usr/lib/mic/*"
mic_files += "/usr/bin/*"

FILES_${PN} = "${mic_files}"

PKG_mic= "mic"

require mic-extraconf.inc
