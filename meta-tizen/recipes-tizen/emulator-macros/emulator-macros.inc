DESCRIPTION = "macros for emulator build"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by emulator-macros 
PROVIDES += "emulator-macros"
RPROVIDES_emulator-macros += "emulator-macros"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/etc/rpm
 install -m 644 ${S}/packaging/macros.emulator ${D}/etc/rpm
 
 
}

PACKAGES = ""
PACKAGES += "emulator-macros"

emulator-macros_files = ""
emulator-macros_files += "/etc/rpm/macros.emulator"

FILES_${PN} = "${emulator-macros_files}"

PKG_emulator-macros= "emulator-macros"

require emulator-macros-extraconf.inc
