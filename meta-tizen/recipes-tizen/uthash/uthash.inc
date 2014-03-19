DESCRIPTION = "A hash table for C structures"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Kernel"
LICENSE = "BSD-style single-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by uthash 
PROVIDES += "uthash"
RPROVIDES_uthash += "uthash"

#PROVIDES by uthash-devel 
PROVIDES += "uthash-devel"
RPROVIDES_uthash-devel += "uthash-devel"
RPROVIDES_uthash-devel += "uthash-dev"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/uthash.manifest .
 
}

do_configure() {
}

do_compile() {
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 mkdir -p  ${D}/usr/include
 cd src
 cp utarray.h uthash.h utlist.h utstring.h ${D}/usr/include
 
 
 
}

PACKAGES = ""
PACKAGES += "uthash-devel"

uthash-devel_files = ""
uthash-devel_files += "uthash.manifest"
uthash-devel_files += "/usr/include/utarray.h"
uthash-devel_files += "/usr/include/uthash.h"
uthash-devel_files += "/usr/include/utlist.h"
uthash-devel_files += "/usr/include/utstring.h"

FILES_${PN}-devel = "${uthash-devel_files}"

PKG_uthash-devel= "uthash-devel"

require uthash-extraconf.inc
