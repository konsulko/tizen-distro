DESCRIPTION = "Weston IVI Shell"
HOMEPAGE = "https://github.com/ntanibata/weston-ivi-shell/"
SECTION = "Graphics & UI Framework/Wayland Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by weston-ivi-shell-dev
PROVIDES += "weston-ivi-shell-dev"


#PROVIDES by weston-ivi-shell-config
PROVIDES += "weston-ivi-shell-config"


#PROVIDES by weston-ivi-shell


RDEPENDS = ""
#RDEPENDS of weston-ivi-shell-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "weston-ivi-shell"

#RDEPENDS of weston-ivi-shell-config (${PN}-config)
RDEPENDS_${PN}-config += "weekeyboard"
RDEPENDS_${PN}-config += "wayland-ivi-extension"
RDEPENDS_${PN}-config += "weston-clients"

#RDEPENDS of weston-ivi-shell (${PN})
RDEPENDS_${PN} += "weston"


DEPENDS = ""
#DEPENDS of weston-ivi-shell
DEPENDS += "mtdev"
DEPENDS += "libxkbcommon"
DEPENDS += "libjpeg-turbo"
DEPENDS_append_class-native = " pkgconfig-native"
DEPENDS_append_class-target = " pkgconfig-native"
DEPENDS_append_class-native = " automake-native"
DEPENDS_append_class-target = " automake-native"
DEPENDS += "weston"
DEPENDS += "wayland"
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"
DEPENDS += "cairo"
DEPENDS += "mesa"
DEPENDS_append_class-native = " autoconf-native"
DEPENDS_append_class-target = " autoconf-native"
DEPENDS += "pango"
DEPENDS += "pixman"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/weston-ivi-shell.manifest .
 
 
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
  
  # We only care about the ivi-shell related bits so disable anything
  # unrelated.
  
   
  autotools_do_configure
  make -j16
  
  
  
}
EXTRA_OECONF += " --disable-static --disable-egl --disable-libunwind --disable-xwayland --disable-xwayland-test --disable-drm-compositor --disable-x11-compositor --disable-rpi-compositor --disable-fbdev-compositor --disable-wayland-compositor --disable-headless-compositor --disable-weston-launch --enable-clients --disable-wcap-tools --disable-demo-clients-install --disable-libinput-backend --disable-fullscreen-shell"

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 install -d ${D}/${prefix}/share/weston-ivi-shell/protocol/
 
 install -m 644 protocol/*.xml \
     ${D}/${prefix}/share/weston-ivi-shell/protocol/
 
 install -m 644 protocol/*.h \
     ${D}/${prefix}/share/weston-ivi-shell/protocol/
 
 install -m 644 protocol/*.c \
     ${D}/${prefix}/share/weston-ivi-shell/protocol/
 
 mkdir -p ${D}${sysconfdir}/xdg/weston
 install -m 0644 ${S}/packaging/weston.ini ${D}${sysconfdir}/xdg/weston
 install -d ${D}/${prefix}/share/weston/
 cp -rfva data/* ${D}/${prefix}/share/weston/
 
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " weston-ivi-shell-dev "
PACKAGES += " weston-ivi-shell-config "
PACKAGES += " weston-ivi-shell "

weston-ivi-shell-dev_files = ""
weston-ivi-shell-dev_files += "${prefix}/include/weston/ivi-layout-export.h"
weston-ivi-shell-dev_files += "${prefix}/include/weston/ivi-layout.h"
weston-ivi-shell-dev_files += "${prefix}/include/weston/ivi-shell.h"
weston-ivi-shell-dev_files += "${prefix}/include/weston/ivi-layout-transition.h"
weston-ivi-shell-dev_files += "${prefix}/share/weston-ivi-shell/protocol/*"
MANIFESTFILES_${PN}-dev = "weston-ivi-shell.manifest"

weston-ivi-shell-config_files = ""
weston-ivi-shell-config_files += "${sysconfdir}/xdg/weston/weston.ini"
CONFFILES_${PN}-config = ""
CONFFILES_${PN}-config += "${sysconfdir}/xdg/weston/weston.ini"
MANIFESTFILES_${PN}-config = "weston-ivi-shell.manifest"

weston-ivi-shell_files = ""
weston-ivi-shell_files += "${prefix}/lib/weston"
weston-ivi-shell_files += "${prefix}/libexec/weston-ivi-shell-user-interface"
weston-ivi-shell_files += "${prefix}/share/weston/*"
MANIFESTFILES_${PN} = "weston-ivi-shell.manifest"

FILES_${PN}-dev = "${weston-ivi-shell-dev_files}"
FILES_${PN}-config = "${weston-ivi-shell-config_files}"
FILES_${PN} = "${weston-ivi-shell_files}"

PKG_weston-ivi-shell-dev= "weston-ivi-shell-dev"
PKG_weston-ivi-shell-config= "weston-ivi-shell-config"
PKG_weston-ivi-shell= "weston-ivi-shell"

require weston-ivi-shell-extraconf.inc

