DESCRIPTION = "Tizen-specific CA certificate installation"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Certificate Management"
LICENSE = "Apache-2.0"
PV = "0.1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ca-certificates-tizen


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ca-certificates-tizen.manifest .
 
 
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
 
 rm -fr ${D}
 mkdir -p ${D}/usr/share/ca-certificates/tizen
 mkdir -p ${D}/usr/share/ca-certificates/wac
 cp -arf certificates/tizen*.pem ${D}/usr/share/ca-certificates/tizen/
 cp -arf certificates/wac*.pem ${D}/usr/share/ca-certificates/wac/
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " ca-certificates-tizen "

ca-certificates-tizen_files = ""
ca-certificates-tizen_files += "/usr/share/ca-certificates/tizen/*"
ca-certificates-tizen_files += "/usr/share/ca-certificates/wac/*"
MANIFESTFILES_${PN} = "ca-certificates-tizen.manifest"

FILES_${PN} = "${ca-certificates-tizen_files}"

PKG_ca-certificates-tizen= "ca-certificates-tizen"

require ca-certificates-tizen-extraconf.inc

