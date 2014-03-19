DESCRIPTION = "A Python module for working with OpenPGP messages"
HOMEPAGE = "http://pypi.python.org/pypi/pygpgme"
SECTION = "Platform Development/Python"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-gpgme 
PROVIDES += "python-gpgme"
RPROVIDES_python-gpgme += "python-gpgme"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-gpgme 
inherit pythonnative
DEPENDS += "gpgme"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n pygpgme-0.1
 cp ${S}/packaging/python-gpgme.manifest .
 
 
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
 
 /usr/bin/python setup.py install --root $RPM_BUILD_ROOT --prefix=/usr
 # No need to ship the tests
 rm -rf $RPM_BUILD_ROOT/usr/lib/python2.7/site-packages/gpgme/tests/
 
 
 
}

PACKAGES = ""
PACKAGES += "python-gpgme"

python-gpgme_files = ""
python-gpgme_files += "python-gpgme.manifest"
python-gpgme_files += "README PKG-INFO"
python-gpgme_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-gpgme_files}"

PKG_python-gpgme= "python-gpgme"

require python-gpgme-extraconf.inc
