DESCRIPTION = "free fonts for Tizen SDK"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "TO BE FILLED IN"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by default-fonts-sdk 
PROVIDES += "default-fonts-sdk"
RPROVIDES_default-fonts-sdk += "default-fonts-sdk"

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
 
 cp ${S}/packaging/default-fonts-sdk.manifest .
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
 mkdir -p ${D}/usr/share/fonts && cp -a fonts ${D}/usr/share
 mkdir -p ${D}/usr/share/fallback_fonts && cp -a fallback_fonts ${D}/usr/share
 
 
}

PACKAGES = ""
PACKAGES += "default-fonts-sdk"

default-fonts-sdk_files = ""
default-fonts-sdk_files += "default-fonts-sdk.manifest"
default-fonts-sdk_files += "/usr/share/fonts/*"
default-fonts-sdk_files += "/usr/share/fallback_fonts/*"

FILES_${PN} = "${default-fonts-sdk_files}"

PKG_default-fonts-sdk= "default-fonts-sdk"

require default-fonts-sdk-extraconf.inc
