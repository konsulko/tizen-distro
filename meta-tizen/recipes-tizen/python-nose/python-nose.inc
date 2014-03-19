DESCRIPTION = "Nose extends unittest to make testing easier"
HOMEPAGE = "http://readthedocs.org/docs/nose/"
SECTION = "Development/Languages/Python"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-nose 
PROVIDES += "python-nose"
RPROVIDES_python-nose += "python-nose"

RDEPENDS = ""
#RDEPENDS of python-nose (${PN})
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "python-distribute"


DEPENDS = ""
#DEPENDS of python-nose 
inherit pythonnative
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n nose-1.1.2
 cp ${S}/packaging/python-nose.manifest .
 sed -i 's,man/man1,share/man/man1,' setup.py
 
 
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
 
 exit 0
 python setup.py test
 
 
 
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
PACKAGES += "python-nose"

python-nose_files = ""
python-nose_files += "python-nose.manifest"
python-nose_files += "NEWS README.txt lgpl.txt"
python-nose_files += "/usr/bin/nosetests*"
python-nose_files += "/usr/share/man/man*/nosetests*"
python-nose_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-nose_files}"

PKG_python-nose= "python-nose"

require python-nose-extraconf.inc
