DESCRIPTION = "Code coverage measurement for Python"
HOMEPAGE = "http://nedbatchelder.com/code/coverage"
SECTION = "Platform Development/Python"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-coverage 
PROVIDES += "python-coverage"
RPROVIDES_python-coverage += "python-coverage"

RDEPENDS = ""
#RDEPENDS of python-coverage (${PN})
RDEPENDS_${PN} += "python-xml"


DEPENDS = ""
#DEPENDS of python-coverage 
inherit pythonnative
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n coverage-3.6
 cp ${S}/packaging/python-coverage.manifest .
 
 
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
 
 python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 python setup.py install --prefix=/usr --root=${D}
 
 
}

PACKAGES = ""
PACKAGES += "python-coverage"

python-coverage_files = ""
python-coverage_files += "python-coverage.manifest"
python-coverage_files += "/usr/bin/coverage*"
python-coverage_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-coverage_files}"

PKG_python-coverage= "python-coverage"

require python-coverage-extraconf.inc
