DESCRIPTION = "User Mode Init manager for bluetooth device in pr3"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Communications/Bluetooth"
LICENSE = "GPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by uim 
PROVIDES += "uim"
RPROVIDES_uim += "uim"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of uim 
DEPENDS += "bluez"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/uim.manifest .
 
 
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
 
 gcc -o uim uim.c
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/bin/
 cp -f uim ${D}/bin/
 
 
}

PACKAGES = ""
PACKAGES += "uim"

uim_files = ""
uim_files += "uim.manifest"

FILES_${PN} = "${uim_files}"

PKG_uim= "uim"

require uim-extraconf.inc
