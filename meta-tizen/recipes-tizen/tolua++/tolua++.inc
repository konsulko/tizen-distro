DESCRIPTION = "C/C++ with Lua Integration Tool"
HOMEPAGE = "http://www.codenix.com/~tolua/"
SECTION = "Development/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tolua++ 
PROVIDES += "tolua++"
RPROVIDES_tolua++ += "tolua++"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of tolua++ 
DEPENDS += "scons"
DEPENDS += "gcc-cross"
DEPENDS += "lua-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tolua++.manifest .
 
 
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
 
 cat <<'EOF' > config_linux.py
 import re,os
 
 CCFLAGS = re.split(r"\s+", os.environ['CCFLAGS'])
 LIBS = re.split(r"\s+", os.environ['LIBS'])
 prefix = "/usr"
 EOF
 
 CCFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables `pkg-config lua --cflags` -fPIC" \
 LIBS="`pkg-config lua --libs-only-l`" \
 scons  \
     prefix="/usr" \
     libdir="/usr/lib" \
     all
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 CCFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables `pkg-config lua --cflags` -fPIC" \
 LIBS="`pkg-config lua --libs-only-l`" \
 scons  \
     prefix="${D}/usr" \
     libdir="${D}/usr/lib" \
     install
 
 
}

PACKAGES = ""
PACKAGES += "tolua++"

tolua++_files = ""
tolua++_files += "tolua++.manifest"
tolua++_files += "/usr/bin/tolua++"
tolua++_files += "/usr/include/tolua++.h"
tolua++_files += "/usr/lib/libtolua++.a"

FILES_${PN} = "${tolua++_files}"

PKG_tolua++= "tolua++"

require tolua++-extraconf.inc
