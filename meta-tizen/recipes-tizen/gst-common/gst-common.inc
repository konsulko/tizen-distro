DESCRIPTION = "Gstreamer Common Files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Development"
LICENSE = "LGPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gst-common 
PROVIDES += "gst-common"
RPROVIDES_gst-common += "gst-common"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gst-common.manifest .
 
 
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
 
 rm -rf .gitignore
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}//usr/share/gst-common
 cp -a . ${D}//usr/share/gst-common
 
 
}

PACKAGES = ""
PACKAGES += "gst-common"

gst-common_files = ""
gst-common_files += "gst-common.manifest"
gst-common_files += "/usr/share/gst-common"

FILES_${PN} = "${gst-common_files}"

PKG_gst-common= "gst-common"

require gst-common-extraconf.inc
