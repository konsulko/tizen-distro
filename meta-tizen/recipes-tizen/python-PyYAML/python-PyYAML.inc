DESCRIPTION = "YAML parser and emitter for Python"
HOMEPAGE = "http://pyyaml.org/wiki/PyYAML"
SECTION = "Development/Languages/Python"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-PyYAML 
PROVIDES += "python-PyYAML"
RPROVIDES_python-PyYAML += "python-PyYAML"
# the PROVIDES rules is ignore "python-yaml = 3.10"
PROVIDES += "python-yaml"
RPROVIDES_python-PyYAML += "python-yaml"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-PyYAML 
inherit pythonnative
DEPENDS += "python-nose"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n PyYAML-3.10
 cp ${S}/packaging/python-PyYAML.manifest .
 
 
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
 find examples -type f | xargs chmod -x # Fix example permissions
 
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
PACKAGES += "python-PyYAML"

python-PyYAML_files = ""
python-PyYAML_files += "python-PyYAML.manifest"
python-PyYAML_files += "LICENSE"
python-PyYAML_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-PyYAML_files}"

PKG_python-PyYAML= "python-PyYAML"

require python-PyYAML-extraconf.inc
