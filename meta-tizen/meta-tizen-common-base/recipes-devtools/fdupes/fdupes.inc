DESCRIPTION = "Identifying or deleting duplicate files"
HOMEPAGE = "http://premium.caribe.net/~adrian2/fdupes.html"
SECTION = "Base/Compression"
LICENSE = "MIT"
PV = "1.40"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by fdupes


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/fdupes.manifest .
 
 
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
 
 install -D -m755 fdupes ${D}${prefix}/bin/fdupes
 install -D -m644 fdupes.1 ${D}${mandir}/man1/fdupes.1
 install -D -m644 ${S}/packaging/macros.fdupes ${D}${sysconfdir}/rpm/macros.fdupes
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " fdupes "

fdupes_files = ""
fdupes_files += "CHANGES"
fdupes_files += "${prefix}/bin/fdupes"
fdupes_files += "${mandir}/*/*"
fdupes_files += "${sysconfdir}/rpm"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/rpm"
MANIFESTFILES_${PN} = "fdupes.manifest"

FILES_${PN} = "${fdupes_files}"

PKG_fdupes= "fdupes"

require fdupes-extraconf.inc

