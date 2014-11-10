DESCRIPTION = "Common Meta Data"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Configuration"
LICENSE = "GPL-2.0"
PV = "001"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by meta-common


RDEPENDS = ""
#RDEPENDS of meta-common (${PN})
RDEPENDS_${PN} += "meta-generic"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/meta-common.manifest .
 
 
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
 
 oe_runmake
 
 
 
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
PACKAGES += " meta-common "

meta-common_files = ""
meta-common_files += "${prefix}/share/package-groups/common/*.yaml"
meta-common_files += "${prefix}/share/image-configurations/common/*.yaml"
meta-common_files += "${prefix}/share/image-configurations/common/configs/*.yaml"
meta-common_files += "${prefix}/share/image-configurations/common/partitions"
meta-common_files += "${prefix}/share/image-configurations/common/scripts"
MANIFESTFILES_${PN} = "meta-common.manifest"

FILES_${PN} = "${meta-common_files}"

PKG_meta-common= "meta-common"

require meta-common-extraconf.inc

