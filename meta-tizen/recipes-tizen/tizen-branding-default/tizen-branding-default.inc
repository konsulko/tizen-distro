DESCRIPTION = "Default Branding files"
HOMEPAGE = "http://tizen.org"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tizen-branding-default 
PROVIDES += "tizen-branding-default"
RPROVIDES_tizen-branding-default += "tizen-branding-default"

RDEPENDS = ""
#RDEPENDS of tizen-branding-default (${PN})
RDEPENDS_${PN} += "plymouth-plugin-script"


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
 
 cp ${S}/packaging/tizen-branding-default.manifest .
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 /bin/install -d ${D}/usr/share/branding/default/syslinux
 
 /bin/install -d ${D}/usr/share/plymouth/themes
 cp syslinux/* ${D}/usr/share/branding/default/syslinux
 cp -a plymouth/tizen ${D}/usr/share/plymouth/themes
 cp syslinux/syslinux-vesa-splash.jpg ${D}/usr/share/plymouth/themes/tizen/tizen.png
 
 
}

PACKAGES = ""
PACKAGES += "tizen-branding-default"

tizen-branding-default_files = ""
tizen-branding-default_files += "tizen-branding-default.manifest"
tizen-branding-default_files += "/usr/share/branding/default/syslinux"
tizen-branding-default_files += "/usr/share/plymouth/themes/tizen"

FILES_${PN} = "${tizen-branding-default_files}"

PKG_tizen-branding-default= "tizen-branding-default"

require tizen-branding-default-extraconf.inc
