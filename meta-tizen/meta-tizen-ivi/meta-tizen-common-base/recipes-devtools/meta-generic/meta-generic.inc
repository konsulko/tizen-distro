DESCRIPTION = "Tizen Package Groups and Images Configurations"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Configuration"
LICENSE = "GPL-2.0"
PV = "0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by meta-generic-adaptation
PROVIDES += "meta-generic-adaptation"


#PROVIDES by meta-generic


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/meta-generic.manifest .
 
 
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
 
 make
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
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
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " meta-generic-adaptation "
PACKAGES += " meta-generic "

meta-generic-adaptation_files = ""
meta-generic-adaptation_files += "${sysconfdir}/profile.d/generic-adaptation.sh"

meta-generic_files = ""
meta-generic_files += "${prefix}/share/package-groups/generic/*.yaml"
meta-generic_files += "${prefix}/share/image-configurations/generic/scripts"
MANIFESTFILES_${PN} = "meta-generic.manifest"

FILES_${PN}-adaptation = "${meta-generic-adaptation_files}"
FILES_${PN} = "${meta-generic_files}"

PKG_meta-generic-adaptation= "meta-generic-adaptation"
PKG_meta-generic= "meta-generic"

require meta-generic-extraconf.inc

