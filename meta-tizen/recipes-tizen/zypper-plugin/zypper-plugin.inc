DESCRIPTION = "Helper that makes writing ZYpp plugins easier"
HOMEPAGE = "https://gitorious.org/opensuse/zypp-plugin"
SECTION = "System/Packages"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by zypp-plugin 
PROVIDES += "zypp-plugin"
RPROVIDES_zypp-plugin += "zypp-plugin"

#PROVIDES by zypp-plugin-python 
PROVIDES += "zypp-plugin-python"
RPROVIDES_zypp-plugin-python += "zypp-plugin-python"

RDEPENDS = ""
#RDEPENDS of zypp-plugin (zypp-plugin)
RDEPENDS_zypp-plugin += "python"


DEPENDS = ""
#DEPENDS of zypp-plugin 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n zypp-plugin
 cp ${S}/packaging/zypp-plugin.manifest .
 
 
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
 
 /bin/mkdir -p ${D}/usr/lib/python2.7/site-packages
 /bin/install python/zypp_plugin.py ${D}/usr/lib/python2.7/site-packages/zypp_plugin.py
 
 
}

PACKAGES = ""
PACKAGES += "zypp-plugin-python"

zypp-plugin-python_files = ""
zypp-plugin-python_files += "zypp-plugin.manifest"
zypp-plugin-python_files += "/usr/lib/python2.7/site-packages/zypp_plugin.py"

FILES_${PN}-python = "${zypp-plugin-python_files}"

PKG_zypp-plugin-python= "zypp-plugin-python"

require zypper-plugin-extraconf.inc
