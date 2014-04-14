DESCRIPTION = "A hash table for C structures"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Kernel"
LICENSE = "BSD-style single-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools

PROVIDES = ""

#PROVIDES by uthash 

#PROVIDES by uthash-dev 

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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 #empty
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
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


uthash-dev_files = ""
uthash-devel_files += "uthash.manifest"
uthash-devel_files += "${prefix}/include/utarray.h"
uthash-devel_files += "${prefix}/include/uthash.h"
uthash-devel_files += "${prefix}/include/utlist.h"
uthash-devel_files += "${prefix}/include/utstring.h"

FILES_${PN}-devel = "${uthash-devel_files}"

PKG_uthash-devel= "uthash-devel"

require uthash-extraconf.inc
