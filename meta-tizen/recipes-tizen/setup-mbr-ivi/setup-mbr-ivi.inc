DESCRIPTION = "Legacy BIOS boot setup"
HOMEPAGE = "http://www.tizen.org"
SECTION = "System/Configuration"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by setup-mbr-ivi 
PROVIDES += "setup-mbr-ivi"
RPROVIDES_setup-mbr-ivi += "setup-mbr-ivi"

RDEPENDS = ""
#RDEPENDS of setup-mbr-ivi (${PN})
RDEPENDS_${PN} += "/usr/bin/dd"
RDEPENDS_${PN} += "/usr/bin/sort"
RDEPENDS_${PN} += "/usr/bin/grep"
RDEPENDS_${PN} += "syslinux-extlinux"
RDEPENDS_${PN} += "/usr/bin/sed"
RDEPENDS_${PN} += "/usr/bin/printf"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n setup-mbr-ivi-1.0
 
 ###
 ### BUILD
 ###
 
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
 
 
 ###
 ### INSTALL
 ###
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}//usr/sbin
 install -m755 setup-mbr-ivi ${D}//usr/sbin
 install -m755 setup-extlinux-conf ${D}//usr/sbin
 
 ###
 ### CLEAN
 ###
 
}

PACKAGES = ""
PACKAGES += "setup-mbr-ivi"

setup-mbr-ivi_files = ""
setup-mbr-ivi_files += "/usr/sbin/setup-mbr-ivi"
setup-mbr-ivi_files += "/usr/sbin/setup-extlinux-conf"

FILES_${PN} = "${setup-mbr-ivi_files}"

PKG_setup-mbr-ivi= "setup-mbr-ivi"

require setup-mbr-ivi-extraconf.inc
