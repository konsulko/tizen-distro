DESCRIPTION = "Fonts With Extensive Style and Language Support Developed for Android"
HOMEPAGE = "http://www.ascendercorp.com/pr/2007-11-12/"
SECTION = "System/Fonts"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by google-droid-fonts 
PROVIDES += "google-droid-fonts"
RPROVIDES_google-droid-fonts += "google-droid-fonts"

RDEPENDS = ""
#RDEPENDS of google-droid-fonts (${PN})
RDEPENDS_${PN} += "/usr/bin/fc-cache"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/google-droid-fonts.manifest .
 
 
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
 
 mkdir -p ${D}/usr/share/fonts/truetype
 install -m 0644 *.ttf ${D}/usr/share/fonts/truetype/
 
 
}

PACKAGES = ""
PACKAGES += "google-droid-fonts"

google-droid-fonts_files = ""
google-droid-fonts_files += "google-droid-fonts.manifest"
google-droid-fonts_files += "/usr/share/fonts/truetype"

FILES_${PN} = "${google-droid-fonts_files}"

PKG_google-droid-fonts= "google-droid-fonts"

require google-droid-fonts-extraconf.inc
