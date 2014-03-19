DESCRIPTION = "Wrt-widgets Installer"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Web Framework/Web Run Time"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wrt-widgets 
PROVIDES += "wrt-widgets"
RPROVIDES_wrt-widgets += "wrt-widgets"

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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 mkdir -p ${D}//usr/bin
 cp install_widgets.sh ${D}//usr/bin
 cp prepare_widgets.sh ${D}//usr/bin
 
 if [ ! -d ${D}//usr/share/widget_demo ]
 then
     mkdir -p  ${D}//usr/share/widget_demo
 fi
 
 cp -r *.wgt ${D}//usr/share/widget_demo/
 
 
}

PACKAGES = ""
PACKAGES += "wrt-widgets"

wrt-widgets_files = ""
wrt-widgets_files += "/usr/share/widget_demo/*.wgt"

FILES_${PN} = "${wrt-widgets_files}"

PKG_wrt-widgets= "wrt-widgets"

require wrt-widgets-extraconf.inc
