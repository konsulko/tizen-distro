DESCRIPTION = "Pulseaudio module for enforcing policy decisions in the audio domain"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Resource Policy"
LICENSE = "LGPL-2.1"
PV = "0.9.32"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by pulseaudio-module-murphy-ivi


RDEPENDS = ""
#RDEPENDS of pulseaudio-module-murphy-ivi (${PN})
RDEPENDS_${PN} += "pulseaudio"
RDEPENDS_${PN} += "aul"


DEPENDS = ""
#DEPENDS of pulseaudio-module-murphy-ivi
DEPENDS += "pulseaudio"
DEPENDS += "dbus"
DEPENDS += "murphy"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "lua"
DEPENDS += "aul"
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
  
  PAVER="`/usr/bin/pkg-config --silence-errors --modversion libpulse |   tr -d \\n | sed -e 's/\([0123456789.]\+\).*/\1/'`"
  ./bootstrap.sh
  
  unset LD_AS_NEEDED
  
  autotools_do_configure
  oe_runmake
  
  
  
}
EXTRA_OECONF += " --disable-static --with-module-dir=${prefix}/lib/pulse-$PAVER/modules --with-dbus --with-documentation=no --with-murphyif"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf $RPM_BUILD_ROOT
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 rm -f ${prefix}/lib/pulse-*/modules/module-*.la
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " pulseaudio-module-murphy-ivi "

pulseaudio-module-murphy-ivi_files = ""
pulseaudio-module-murphy-ivi_files += "${prefix}/lib/pulse-*/modules/module-*.so"
pulseaudio-module-murphy-ivi_files += "${sysconfdir}/dbus-1/system.d/pulseaudio-murphy-ivi.conf"
pulseaudio-module-murphy-ivi_files += "${sysconfdir}/pulse/murphy-ivi.lua"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/dbus-1/system.d/pulseaudio-murphy-ivi.conf"

FILES_${PN} = "${pulseaudio-module-murphy-ivi_files}"

PKG_pulseaudio-module-murphy-ivi= "pulseaudio-module-murphy-ivi"

require pulseaudio-module-murphy-ivi-extraconf.inc

