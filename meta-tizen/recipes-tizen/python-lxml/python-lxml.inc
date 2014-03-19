DESCRIPTION = "Powerful and Pythonic XML processing library"
HOMEPAGE = "http://lxml.de/"
SECTION = "Development/Languages/Python"
LICENSE = "BSD-3-Clause and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-lxml 
PROVIDES += "python-lxml"
RPROVIDES_python-lxml += "python-lxml"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-lxml 
inherit pythonnative
DEPENDS += "libxslt"
DEPENDS += "pkgconfig(libxml-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n lxml-2.3.4
 cp ${S}/packaging/python-lxml.manifest .
 
 
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
PACKAGES += "python-lxml"

python-lxml_files = ""
python-lxml_files += "python-lxml.manifest"
python-lxml_files += "LICENSES.txt"
python-lxml_files += "/usr/lib/python2.7/site-packages/lxml/"
python-lxml_files += "/usr/lib/python2.7/site-packages/lxml-2.3.4-py2.7.egg-info"

FILES_${PN} = "${python-lxml_files}"

PKG_python-lxml= "python-lxml"

require python-lxml-extraconf.inc
