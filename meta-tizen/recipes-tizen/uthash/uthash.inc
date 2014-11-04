DESCRIPTION = "A hash table for C structures"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Kernel"
LICENSE = "BSD-style single-clause"
PV = "1.9.7"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by uthash


#PROVIDES by uthash-dev
PROVIDES += "uthash-dev"


RDEPENDS = ""

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/uthash.manifest .
 
 
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
 
 #empty
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p  ${D}${prefix}/include
 cd src
 cp utarray.h uthash.h utlist.h utstring.h ${D}${prefix}/include
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " uthash-dev "

uthash-dev_files = ""
uthash-dev_files += "${prefix}/include/utarray.h"
uthash-dev_files += "${prefix}/include/uthash.h"
uthash-dev_files += "${prefix}/include/utlist.h"
uthash-dev_files += "${prefix}/include/utstring.h"
MANIFESTFILES_${PN}-dev = "uthash.manifest"

FILES_${PN}-dev = "${uthash-dev_files}"

PKG_uthash-dev= "uthash-dev"

require uthash-extraconf.inc

