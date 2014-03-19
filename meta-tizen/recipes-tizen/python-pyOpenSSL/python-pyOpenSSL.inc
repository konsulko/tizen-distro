DESCRIPTION = "Python wrapper module around the OpenSSL library"
HOMEPAGE = "http://launchpad.net/pyopenssl"
SECTION = "Development/Languages/Python"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-pyOpenSSL 
PROVIDES += "python-pyOpenSSL"
RPROVIDES_python-pyOpenSSL += "python-pyOpenSSL"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-pyOpenSSL 
inherit pythonnative
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n pyOpenSSL-0.13
 cp ${S}/packaging/python-pyOpenSSL.manifest .
 
 
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
 
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing" python setup.py build
 
 
 
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
PACKAGES += "python-pyOpenSSL"

python-pyOpenSSL_files = ""
python-pyOpenSSL_files += "python-pyOpenSSL.manifest"
python-pyOpenSSL_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-pyOpenSSL_files}"

PKG_python-pyOpenSSL= "python-pyOpenSSL"

require python-pyOpenSSL-extraconf.inc
