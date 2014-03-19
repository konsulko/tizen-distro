DESCRIPTION = "Fonts package that provides the Clear Sans font"
HOMEPAGE = "https://01.org/clear-sans"
SECTION = "Graphics & UI Framework/Fonts"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by monotype-fonts 
PROVIDES += "monotype-fonts"
RPROVIDES_monotype-fonts += "monotype-fonts"

RDEPENDS = ""
#RDEPENDS of monotype-fonts (${PN})
RDEPENDS_${PN} += "/usr/bin/fc-cache"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/monotype-fonts.manifest .
 
 
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
 install -m 0644 TTF/*.ttf ${D}/usr/share/fonts/truetype/
 
 
}

PACKAGES = ""
PACKAGES += "monotype-fonts"

monotype-fonts_files = ""
monotype-fonts_files += "monotype-fonts.manifest"
monotype-fonts_files += "/usr/share/fonts/truetype/*.ttf"

FILES_${PN} = "${monotype-fonts_files}"

PKG_monotype-fonts= "monotype-fonts"

require monotype-fonts-extraconf.inc
