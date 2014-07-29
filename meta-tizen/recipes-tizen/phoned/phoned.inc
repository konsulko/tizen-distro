DESCRIPTION = "OFono/Obex business logic for phone web APIs"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by phoned


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of phoned
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "evolution-data-server"
DEPENDS += "dbus"
DEPENDS += "expat"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "json-glib"

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
 
 
 
 export LDFLAGS+="-Wl,--rpath="${prefix}/lib/wrt-plugins" -Wl,--as-needed"
 
 cmake . -DCMAKE_INSTALL_PREFIX=${prefix} -DENABLE_TIME_TRACER="OFF"
 
 make  VERBOSE=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " phoned "

phoned_files = ""
phoned_files += "${prefix}/lib/pkgconfig/phoned.pc"
phoned_files += "${prefix}/sbin/phoned"
phoned_files += "${prefix}/share/dbus-1/services/org.tizen.phone.service"
phoned_files += "${prefix}/lib/systemd/user/phoned.service"

FILES_${PN} = "${phoned_files}"

PKG_phoned= "phoned"

require phoned-extraconf.inc

