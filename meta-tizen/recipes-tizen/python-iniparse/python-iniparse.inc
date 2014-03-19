DESCRIPTION = "Python Module for Accessing and Modifying Configuration Data in INI files"
HOMEPAGE = "http://code.google.com/p/iniparse/"
SECTION = "Platform Development/Python"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-iniparse 
PROVIDES += "python-iniparse"
RPROVIDES_python-iniparse += "python-iniparse"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-iniparse 
inherit pythonnative
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n iniparse-0.4
 cp ${S}/packaging/python-iniparse.manifest .
 chmod 644 html/index.html
 
 
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
 
 python setup.py install --root ${D} --prefix=/usr
 rm -rf ${D}/usr/share/doc/iniparse-0.4 # Remove unwanted stuff
 
 
}

PACKAGES = ""
PACKAGES += "python-iniparse"

python-iniparse_files = ""
python-iniparse_files += "python-iniparse.manifest"
python-iniparse_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-iniparse_files}"

PKG_python-iniparse= "python-iniparse"

require python-iniparse-extraconf.inc
