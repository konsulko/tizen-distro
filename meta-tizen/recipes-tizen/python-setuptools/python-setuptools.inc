DESCRIPTION = "Easily build and distribute Python packages"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "Python or ZPLv2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-setuptools-devel 
PROVIDES += "python-setuptools-devel"
RPROVIDES_python-setuptools-devel += "python-setuptools-devel"
RPROVIDES_python-setuptools-devel += "python-setuptools-dev"

#PROVIDES by python-setuptools 
PROVIDES += "python-setuptools"
RPROVIDES_python-setuptools += "python-setuptools"

RDEPENDS = ""
#RDEPENDS of python-setuptools-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "python-setuptools"
RDEPENDS_${PN}-devel += "python-dev"


DEPENDS = ""
#DEPENDS of python-setuptools 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n setuptools-0.6c11
 
 
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
 
 cp ${S}/packaging/python-setuptools.manifest .
 find -name '*.txt' | xargs chmod -x
 find -name '*.py' | xargs sed -i '1s|^#!python|#!/usr/bin/python|'
 CFLAGS="$RPM_OPT_FLAGS" /usr/bin/python setup.py build
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 /usr/bin/python setup.py install -O1 --skip-build \
     --root $RPM_BUILD_ROOT \
     --prefix /usr \
     --single-version-externally-managed
 
 rm -rf $RPM_BUILD_ROOT/usr/lib/python2.7/site-packages/setuptools/tests
 
 install -p -m 0644 ${S}/packaging/psfl.txt ${S}/packaging/zpl.txt .
 find $RPM_BUILD_ROOT/usr/lib/python2.7/site-packages -name '*.exe' | xargs rm -f
 chmod +x $RPM_BUILD_ROOT/usr/lib/python2.7/site-packages/setuptools/command/easy_install.py
 
 
 
}

PACKAGES = ""
PACKAGES += "python-setuptools-devel"
PACKAGES += "python-setuptools"

python-setuptools-devel_files = ""
python-setuptools-devel_files += "python-setuptools.manifest"
python-setuptools-devel_files += "/usr/lib/python2.7/site-packages/easy_install*"
python-setuptools-devel_files += "/usr/bin/*"

python-setuptools_files = ""
python-setuptools_files += "python-setuptools.manifest"
python-setuptools_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN}-devel = "${python-setuptools-devel_files}"
FILES_${PN} = "${python-setuptools_files}"

PKG_python-setuptools-devel= "python-setuptools-devel"
PKG_python-setuptools= "python-setuptools"

require python-setuptools-extraconf.inc
