DESCRIPTION = "Login manager for Tizen"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "LGPL-2.1+"
PV = "1.0.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by tlm-config-common
PROVIDES += "tlm-config-common"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-common += "tlm-config"


#PROVIDES by tlm-dev
PROVIDES += "tlm-dev"


#PROVIDES by tlm


#PROVIDES by tlm-doc
PROVIDES += "tlm-doc"


RDEPENDS = ""
#RDEPENDS of tlm-config-common (${PN}-config-common)
RDEPENDS_${PN}-config-common += "tlm"

#RDEPENDS of tlm-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "tlm"

#RDEPENDS of tlm (${PN})
RDEPENDS_${PN} += "libsystemd"
RDEPENDS_${PN} += "glibc"
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "gumd"

#RDEPENDS of tlm-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "tlm"


DEPENDS = ""
#DEPENDS of tlm
DEPENDS += "gumd"
inherit pkgconfig
DEPENDS += "libpam"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n tlm-1.0.1
 cp ${S}/packaging/tlm.manifest .
 
 
 
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
EXTRA_OECONF += " --enable-gum "

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
 rm -f ${D}${sysconfdir}/tlm.conf
 install -m 755 -d ${D}${systemd_unitdir}/system
 install -m 644 data/tlm.service ${D}${systemd_unitdir}/system
 install -m 755 -d ${D}${sysconfdir}/pam.d
 install -m 644 data/tlm-login ${D}${sysconfdir}/pam.d/
 install -m 644 data/tlm-default-login ${D}${sysconfdir}/pam.d/
 install -m 644 data/tlm-system-login ${D}${sysconfdir}/pam.d/
 install -m 755 -d ${D}${sysconfdir}/session.d
 install -m 644 data/tizen-common/etc/tlm.conf ${D}${sysconfdir}
 install -m 755 data/tizen-common/etc/session.d/* ${D}${sysconfdir}/session.d/
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    systemctl enable tlm
    systemctl daemon-reload

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig

}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    if [ $1 == 0 ]; then
      systemctl disable tlm
      systemctl daemon-reload
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h /etc/tlm.conf ]; then
    rm -f /etc/tlm.conf
    fi

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " tlm-config-common "
PACKAGES += " tlm-dev "
PACKAGES += " tlm "

tlm-config-common_files = ""
tlm-config-common_files += "${sysconfdir}/tlm.conf"
tlm-config-common_files += "${sysconfdir}/session.d/*"
MANIFESTFILES_${PN}-config-common = "tlm.manifest"

tlm-dev_files = ""
tlm-dev_files += "${prefix}/include/tlm/*.h"
tlm-dev_files += "${prefix}/lib/libtlm*.so"
tlm-dev_files += "${prefix}/lib/pkgconfig/tlm.pc"

tlm_files = ""
tlm_files += "AUTHORS NEWS README"
tlm_files += "${prefix}/bin/tlm"
tlm_files += "${prefix}/bin/tlm-sessiond"
tlm_files += "${prefix}/bin/tlm-client"
tlm_files += "${prefix}/bin/tlm-weston-launch"
tlm_files += "${prefix}/lib/libtlm*.so.*"
tlm_files += "${prefix}/lib/tlm/plugins/*.so*"
tlm_files += "${systemd_unitdir}/system/tlm.service"
tlm_files += "${sysconfdir}/pam.d/tlm-login"
tlm_files += "${sysconfdir}/pam.d/tlm-default-login"
tlm_files += "${sysconfdir}/pam.d/tlm-system-login"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-login"
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-default-login"
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-system-login"
MANIFESTFILES_${PN} = "tlm.manifest"

tlm-doc_files = ""
tlm-doc_files += "${prefix}/share/gtk-doc/html/tlm/*"

FILES_${PN}-config-common = "${tlm-config-common_files}"
FILES_${PN}-dev = "${tlm-dev_files}"
FILES_${PN} = "${tlm_files}"
FILES_${PN}-doc = "${tlm-doc_files}"

PKG_tlm-config-common= "tlm-config-common"
PKG_tlm-dev= "tlm-dev"
PKG_tlm= "tlm"
PKG_tlm-doc= "tlm-doc"

require tlm-extraconf.inc

