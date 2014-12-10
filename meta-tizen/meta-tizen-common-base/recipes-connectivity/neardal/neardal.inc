DESCRIPTION = "Neard Abstraction Library (for Neard v0.7)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/NFC"
LICENSE = "LGPL-2.0"
PV = "0.14"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by neardal-dev
PROVIDES += "neardal-dev"


#PROVIDES by neardal


RDEPENDS = ""
#RDEPENDS of neardal-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "neardal"

#RDEPENDS of neardal (${PN})
RDEPENDS_${PN} += "glibc"


DEPENDS = ""
#DEPENDS of neardal
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
inherit pythonnative
inherit pkgconfig
DEPENDS += "dlog"
DEPENDS_append_class-native = " automake-native"
DEPENDS_append_class-target = " automake-native"
DEPENDS += "glib-2.0"
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"
DEPENDS += "python-xml"
DEPENDS_append_class-native = " readline-native"
DEPENDS_append_class-target = " readline-native"
DEPENDS_append_class-native = " autoconf-native"
DEPENDS_append_class-target = " autoconf-native"
DEPENDS += "dbus-glib"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n neardal-0.14
 cp ${S}/packaging/neardal.manifest .
 
 
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
  
  
  autotools_do_configure
  oe_runmake
  
  
}
EXTRA_OECONF += " --disable-traces --prefix=/usr"

do_install() {
 export RPM_BUILD_ROOT=${D}
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

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " neardal-dev "
PACKAGES += " neardal "

neardal-dev_files = ""
neardal-dev_files += "${prefix}/include/neardal/*.h"
neardal-dev_files += "${prefix}/lib/pkgconfig/neardal.pc"
neardal-dev_files += "${prefix}/lib/libneardal.so"
MANIFESTFILES_${PN}-dev = "neardal.manifest"

neardal_files = ""
neardal_files += "README AUTHORS"
neardal_files += "${prefix}/lib/libneardal.so.0"
neardal_files += "${prefix}/lib/libneardal.so.0.0.*"
neardal_files += "${sysconfdir}/dbus-1/system.d/org.neardal.conf"
MANIFESTFILES_${PN} = "neardal.manifest"

FILES_${PN}-dev = "${neardal-dev_files}"
FILES_${PN} = "${neardal_files}"

PKG_neardal-dev= "neardal-dev"
PKG_neardal= "neardal"

require neardal-extraconf.inc

