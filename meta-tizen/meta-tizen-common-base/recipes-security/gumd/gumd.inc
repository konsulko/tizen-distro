DESCRIPTION = "User management daemon and client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Accounts"
LICENSE = "LGPL-2.1+"
PV = "1.0.3"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by gum-utils
PROVIDES += "gum-utils"


#PROVIDES by libgum-dev
PROVIDES += "libgum-dev"


#PROVIDES by libgum
PROVIDES += "libgum"


#PROVIDES by gumd-doc
PROVIDES += "gumd-doc"


#PROVIDES by gumd


RDEPENDS = ""
#RDEPENDS of gum-utils (gum-utils)
RDEPENDS_gum-utils += "libgum"

#RDEPENDS of gumd (${PN})
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "libgum"
RDEPENDS_${PN} += "glibc"

#RDEPENDS of libgum (libgum)
RDEPENDS_libgum += "gumd"

#RDEPENDS of gumd-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "libgum"

#RDEPENDS of libgum-dev (libgum-dev)
RDEPENDS_libgum-dev += "libgum"


DEPENDS = ""
#DEPENDS of gumd
DEPENDS += "systemd"
DEPENDS += "dbus"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "gtk-doc-stub"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gumd-1.0.3
 cp -a ${S}/packaging/gumd.manifest gumd.manifest
 cp -a ${S}/packaging/libgum.manifest libgum.manifest
 
 
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
  oe_runmake -j16
  
  
  
}
EXTRA_OECONF += " --enable-dbus-type=system"

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
 cp -a ${S}/packaging/gumd-tizen.conf ${D}${sysconfdir}/gumd/gumd.conf
 
 
}

pkg_postinst_libgum() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
    getent group gumd > /dev/null || groupadd -r gumd
    mkdir -p $D${sysconfdir}/gumd/useradd.d
    mkdir -p $D${sysconfdir}/gumd/userdel.d
    mkdir -p $D${sysconfdir}/gumd/groupadd.d
    mkdir -p $D${sysconfdir}/gumd/groupdel.d

}

pkg_postrm_libgum() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " gum-utils "
PACKAGES += " libgum-dev "
PACKAGES += " libgum "
PACKAGES += " gumd "

gum-utils_files = ""
gum-utils_files += "${prefix}/bin/gum-utils"
MANIFESTFILES_gum-utils = "gumd.manifest"

libgum-dev_files = ""
libgum-dev_files += "${prefix}/include/gum/*"
libgum-dev_files += "${prefix}/lib/libgum*.so"
libgum-dev_files += "${prefix}/lib/pkgconfig/libgum.pc"
libgum-dev_files += "${prefix}/share/dbus-1/interfaces/*UserManagement*.xml"
MANIFESTFILES_libgum-dev = "gumd.manifest"

libgum_files = ""
libgum_files += "${prefix}/lib/libgum*.so.*"
MANIFESTFILES_libgum = "libgum.manifest"

gumd-doc_files = ""
gumd-doc_files += "${prefix}/share/gtk-doc/html/gumd/*"
MANIFESTFILES_${PN}-doc = "gumd.manifest"

gumd_files = ""
gumd_files += "AUTHORS COPYING.LIB NEWS README"
gumd_files += "${prefix}/bin/gumd"
gumd_files += "${sysconfdir}/gumd"
gumd_files += "${sysconfdir}/gumd/gumd.conf"
gumd_files += "${prefix}/share/dbus-1/system-services"
gumd_files += "${prefix}/share/dbus-1/system-services/*UserManagement*.service"
gumd_files += "${sysconfdir}/dbus-1"
gumd_files += "${sysconfdir}/dbus-1/system.d"
gumd_files += "${sysconfdir}/dbus-1/system.d/gumd-dbus.conf"
MANIFESTFILES_${PN} = "gumd.manifest"
DIRFILES_${PN} = ""
DIRFILES_${PN} += "${sysconfdir}/gumd"
DIRFILES_${PN} += "${prefix}/share/dbus-1/system-services"
DIRFILES_${PN} += "${sysconfdir}/dbus-1"
DIRFILES_${PN} += "${sysconfdir}/dbus-1/system.d"

FILES_gum-utils = "${gum-utils_files}"
FILES_libgum-dev = "${libgum-dev_files}"
FILES_libgum = "${libgum_files}"
FILES_${PN}-doc = "${gumd-doc_files}"
FILES_${PN} = "${gumd_files}"

PKG_gum-utils= "gum-utils"
PKG_libgum-dev= "libgum-dev"
PKG_libgum= "libgum"
PKG_gumd-doc= "gumd-doc"
PKG_gumd= "gumd"

require gumd-extraconf.inc

