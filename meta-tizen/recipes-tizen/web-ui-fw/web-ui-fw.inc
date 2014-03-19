DESCRIPTION = "Tizen Web UI Framework Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Other"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by web-ui-fw-demo-tizen-winsets 
PROVIDES += "web-ui-fw-demo-tizen-winsets"
RPROVIDES_web-ui-fw-demo-tizen-winsets += "web-ui-fw-demo-tizen-winsets"

#PROVIDES by web-ui-fw-theme-tizen-black 
PROVIDES += "web-ui-fw-theme-tizen-black"
RPROVIDES_web-ui-fw-theme-tizen-black += "web-ui-fw-theme-tizen-black"

#PROVIDES by web-ui-fw-theme-tizen-gray 
PROVIDES += "web-ui-fw-theme-tizen-gray"
RPROVIDES_web-ui-fw-theme-tizen-gray += "web-ui-fw-theme-tizen-gray"

#PROVIDES by web-ui-fw-theme-default 
PROVIDES += "web-ui-fw-theme-default"
RPROVIDES_web-ui-fw-theme-default += "web-ui-fw-theme-default"

#PROVIDES by web-ui-fw-devel 
PROVIDES += "web-ui-fw-devel"
RPROVIDES_web-ui-fw-devel += "web-ui-fw-devel"
RPROVIDES_web-ui-fw-devel += "web-ui-fw-dev"

#PROVIDES by web-ui-fw 
PROVIDES += "web-ui-fw"
RPROVIDES_web-ui-fw += "web-ui-fw"

#PROVIDES by web-ui-fw-theme-tizen-white 
PROVIDES += "web-ui-fw-theme-tizen-white"
RPROVIDES_web-ui-fw-theme-tizen-white += "web-ui-fw-theme-tizen-white"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of web-ui-fw 
DEPENDS += "make"
DEPENDS += "nodejs"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/web-ui-fw.manifest ${S}/packaging/web-ui-fw-theme-tizen-white.manifest ${S}/packaging/web-ui-fw-theme-tizen-black.manifest ${S}/packaging/web-ui-fw-theme-default.manifest ${S}/packaging/web-ui-fw-devel.manifest ${S}/packaging/web-ui-fw-demo-tizen-winsets.manifest .
 
 
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
 
 make all
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D} install
 
 
}

PACKAGES = ""
PACKAGES += "web-ui-fw-demo-tizen-winsets"
PACKAGES += "web-ui-fw-theme-tizen-black"
PACKAGES += "web-ui-fw-theme-default"
PACKAGES += "web-ui-fw-devel"
PACKAGES += "web-ui-fw"
PACKAGES += "web-ui-fw-theme-tizen-white"

web-ui-fw-demo-tizen-winsets_files = ""
web-ui-fw-demo-tizen-winsets_files += "web-ui-fw-demo-tizen-winsets.manifest"
web-ui-fw-demo-tizen-winsets_files += "/usr/share/tizen-web-ui-fw/demos/tizen-winsets"

web-ui-fw-theme-tizen-black_files = ""
web-ui-fw-theme-tizen-black_files += "web-ui-fw-theme-tizen-black.manifest"
web-ui-fw-theme-tizen-black_files += "/usr/share/tizen-web-ui-fw/*/themes/tizen-black"

web-ui-fw-theme-default_files = ""
web-ui-fw-theme-default_files += "web-ui-fw-theme-default.manifest"
web-ui-fw-theme-default_files += "/usr/share/tizen-web-ui-fw/*/themes/default"

web-ui-fw-devel_files = ""
web-ui-fw-devel_files += "web-ui-fw-devel.manifest"
web-ui-fw-devel_files += "/usr/share/tizen-web-ui-fw/bin"
web-ui-fw-devel_files += "/usr/share/tizen-web-ui-fw/template"
web-ui-fw-devel_files += "/usr/share/tizen-web-ui-fw/*/js/src"
web-ui-fw-devel_files += "/usr/share/tizen-web-ui-fw/*/js/depData.json"

web-ui-fw_files = ""
web-ui-fw_files += "web-ui-fw.manifest"
web-ui-fw_files += "/usr/share/tizen-web-ui-fw/*/js/*.js"
web-ui-fw_files += "/usr/share/tizen-web-ui-fw/*/js/cultures"
web-ui-fw_files += "/usr/share/tizen-web-ui-fw/latest"
web-ui-fw_files += "/usr/share/tizen-web-ui-fw/VERSION"

web-ui-fw-theme-tizen-white_files = ""
web-ui-fw-theme-tizen-white_files += "web-ui-fw-theme-tizen-white.manifest"
web-ui-fw-theme-tizen-white_files += "/usr/share/tizen-web-ui-fw/*/themes/tizen-white"
web-ui-fw-theme-tizen-white_files += "/usr/share/tizen-web-ui-fw/*/themes/tizen-tizen"

FILES_${PN}-demo-tizen-winsets = "${web-ui-fw-demo-tizen-winsets_files}"
FILES_${PN}-theme-tizen-black = "${web-ui-fw-theme-tizen-black_files}"
FILES_${PN}-theme-default = "${web-ui-fw-theme-default_files}"
FILES_${PN}-devel = "${web-ui-fw-devel_files}"
FILES_${PN} = "${web-ui-fw_files}"
FILES_${PN}-theme-tizen-white = "${web-ui-fw-theme-tizen-white_files}"

PKG_web-ui-fw-demo-tizen-winsets= "web-ui-fw-demo-tizen-winsets"
PKG_web-ui-fw-theme-tizen-black= "web-ui-fw-theme-tizen-black"
PKG_web-ui-fw-theme-default= "web-ui-fw-theme-default"
PKG_web-ui-fw-devel= "web-ui-fw-devel"
PKG_web-ui-fw= "web-ui-fw"
PKG_web-ui-fw-theme-tizen-white= "web-ui-fw-theme-tizen-white"

require web-ui-fw-extraconf.inc
