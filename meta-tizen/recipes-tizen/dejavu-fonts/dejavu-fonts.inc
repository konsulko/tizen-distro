DESCRIPTION = "DejaVu Truetype Fonts"
HOMEPAGE = "http://dejavu.sourceforge.net/"
SECTION = "System/Fonts"
LICENSE = "Permissive"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dejavu-fonts 
PROVIDES += "dejavu-fonts"
RPROVIDES_dejavu-fonts += "dejavu-fonts"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n dejavu-fonts-ttf-2.33
 cp ${S}/packaging/dejavu-fonts.manifest .
 
 
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
 
 mkdir -p ${D}/usr/share/fonts/truetype/
 install -m 0644 ttf/*.ttf ${D}/usr/share/fonts/truetype/
 
 
 
}

PACKAGES = ""
PACKAGES += "dejavu-fonts"

dejavu-fonts_files = ""
dejavu-fonts_files += "dejavu-fonts.manifest"
dejavu-fonts_files += "/usr/share/fonts/truetype/"

FILES_${PN} = "${dejavu-fonts_files}"

PKG_dejavu-fonts= "dejavu-fonts"

require dejavu-fonts-extraconf.inc
