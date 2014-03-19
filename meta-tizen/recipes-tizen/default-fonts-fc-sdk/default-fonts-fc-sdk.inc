DESCRIPTION = "Font configuration package for SDK"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "TO BE FILLED IN"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by default-fonts-fc-sdk 
PROVIDES += "default-fonts-fc-sdk"
RPROVIDES_default-fonts-fc-sdk += "default-fonts-fc-sdk"

RDEPENDS = ""

DEPENDS = ""

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
 
 cp ${S}/packaging/default-fonts-fc-sdk.manifest .
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
 mkdir -p ${D}/usr/etc/fonts/conf.d/
 mkdir -p ${D}/opt/etc/fonts/conf.avail/ && cp -a sdk_fonts_fc/* ${D}/opt/etc/fonts/conf.avail/
 cd ${D}/usr/etc/fonts/conf.d/
 ln -s ../../../../opt/etc/fonts/conf.avail/99-slp.conf ${D}/usr/etc/fonts/conf.d/99-slp.conf
 
 
}

PACKAGES = ""
PACKAGES += "default-fonts-fc-sdk"

default-fonts-fc-sdk_files = ""
default-fonts-fc-sdk_files += "default-fonts-fc-sdk.manifest"
default-fonts-fc-sdk_files += "/opt/etc/fonts/conf.avail/99-slp.conf"
default-fonts-fc-sdk_files += "/usr/etc/fonts/conf.d/99-slp.conf"

FILES_${PN} = "${default-fonts-fc-sdk_files}"

PKG_default-fonts-fc-sdk= "default-fonts-fc-sdk"

require default-fonts-fc-sdk-extraconf.inc
