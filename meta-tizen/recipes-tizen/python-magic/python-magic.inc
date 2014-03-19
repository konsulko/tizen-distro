DESCRIPTION = "Python module to use libmagic"
HOMEPAGE = "http://www.darwinsys.com/file/"
SECTION = "Development/Languages/Python"
LICENSE = "BSD-3-Clause and BSD-4-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-magic 
PROVIDES += "python-magic"
RPROVIDES_python-magic += "python-magic"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-magic 
inherit pythonnative
DEPENDS += "zlib-devel"
DEPENDS += "libtool-cross"
DEPENDS += "findutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n file-5.11
 
 
 
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
 
 pushd python
 python setup.py install --root=${D}	\
 			--prefix=/usr	\
 			--record-rpm=../python_files
 popd
 
 
}

PACKAGES = ""
PACKAGES += "python-magic"

python-magic_files = ""

FILES_${PN} = "${python-magic_files}"

PKG_python-magic= "python-magic"

require python-magic-extraconf.inc
