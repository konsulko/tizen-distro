DESCRIPTION = "Ninja build system"
HOMEPAGE = "http://martine.github.com/ninja/"
SECTION = "System/Utilities"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ninja 
PROVIDES += "ninja"
RPROVIDES_ninja += "ninja"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of ninja 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ninja.manifest .
 
 
 
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
 
 python ./bootstrap.py 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 install -m 0755 ninja ${D}/usr/bin/ninja
 
 
}

PACKAGES = ""
PACKAGES += "ninja"

ninja_files = ""
ninja_files += "ninja.manifest"
ninja_files += "/usr/bin/ninja"

FILES_${PN} = "${ninja_files}"

PKG_ninja= "ninja"

require ninja-extraconf.inc
