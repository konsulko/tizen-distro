DESCRIPTION = "Crypto and SSL toolkit for Python"
HOMEPAGE = "http://chandlerproject.org/bin/view/Projects/MeTooCrypto"
SECTION = "Platfrom Development/Python"
LICENSE = "MIT and ZPL-2.0 and BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-M2Crypto 
PROVIDES += "python-M2Crypto"
RPROVIDES_python-M2Crypto += "python-M2Crypto"
# the PROVIDES rules is ignore "python-m2crypto = 0.21.1"
PROVIDES += "python-m2crypto"
RPROVIDES_python-M2Crypto += "python-m2crypto"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-M2Crypto 
inherit pythonnative
DEPENDS += "swig"
DEPENDS += "python-distribute"
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n M2Crypto-0.21.1
 cp ${S}/packaging/python-M2Crypto.manifest .
 
 
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
 
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" python setup.py build
 
 
 
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
PACKAGES += "python-M2Crypto"

python-M2Crypto_files = ""
python-M2Crypto_files += "python-M2Crypto.manifest"
python-M2Crypto_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-M2Crypto_files}"

PKG_python-M2Crypto= "python-M2Crypto"

require python-M2Crypto-extraconf.inc
