DESCRIPTION = "Wrt-widgets Installer"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Web Framework/Web Run Time"
LICENSE = "Apache-2.0"
PV = "0.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by wrt-widgets


RDEPENDS = ""
#RDEPENDS of wrt-widgets (${PN})
RDEPENDS_${PN} += "libtzplatform-config"
RDEPENDS_${PN} += "desktop-skin"


DEPENDS = ""
#DEPENDS of wrt-widgets
DEPENDS += "tizen-platform-config"
inherit pkgconfig

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wrt-widgets.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
 mkdir -p ${D}${prefix}/bin
 cp install_widgets.sh ${D}${prefix}/bin
 cp prepare_widgets.sh ${D}${prefix}/bin
 
 mkdir -p  ${D}${prefix}/share/widget_demo
 cp -r apps/*.wgt ${D}${prefix}/share/widget_demo/
 #cp -r apps/*.png ${D}${prefix}/share/widget_demo/
 #cp -r apps/*.desktop ${D}${prefix}/share/widget_demo/
 cp install.conf ${D}${prefix}/share/widget_demo/
 
 # install xwalk preinstall service in user session
 mkdir -p ${D}${prefix}/lib/systemd/user
 install -m 644 xwalk_widgets_preinstall.service ${D}${prefix}/lib/systemd/user/
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    # setup xwalk preinstall service (inside user session)
    mkdir -p $D${prefix}/lib/systemd/user/default.target.wants/
    ln -sf ../xwalk_widgets_preinstall.service $D${prefix}/lib/systemd/user/default.target.wants/

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    rm -f $D${prefix}/lib/systemd/user/default.target.wants/xwalk_widgets_preinstall.service

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " wrt-widgets "

wrt-widgets_files = ""
wrt-widgets_files += "${prefix}/share/widget_demo/*"
wrt-widgets_files += "${prefix}/bin/install_widgets.sh"
wrt-widgets_files += "${prefix}/bin/prepare_widgets.sh"
wrt-widgets_files += "${prefix}/lib/systemd/user/xwalk_widgets_preinstall.service"
MANIFESTFILES_${PN} = "wrt-widgets.manifest"

FILES_${PN} = "${wrt-widgets_files}"

PKG_wrt-widgets= "wrt-widgets"

require wrt-widgets-extraconf.inc

