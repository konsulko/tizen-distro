DESCRIPTION = "Easily build and distribute Python packages"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "Python or ZPLv2.0"
PV = "0.6c11"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by python-setuptools-dev
PROVIDES += "python-setuptools-dev"


#PROVIDES by python-setuptools


RDEPENDS = ""
#RDEPENDS of python-setuptools-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "python"
RDEPENDS_${PN}-dev += "python-setuptools"


DEPENDS = ""
#DEPENDS of python-setuptools
inherit pythonnative

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n setuptools-0.6c11
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 cp ${S}/packaging/python-setuptools.manifest .
 find -name '*.txt' | xargs chmod -x
 find -name '*.py' | xargs sed -i '1s|^#!python|#!python|'
 CFLAGS="$RPM_OPT_FLAGS" python setup.py build
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 python setup.py install -O1 --skip-build \
     --root $RPM_BUILD_ROOT \
     --prefix ${prefix} \
     --single-version-externally-managed
 
 rm -rf $RPM_BUILD_ROOT${prefix}/lib/python2.7/site-packages/setuptools/tests
 
 install -p -m 0644 ${S}/packaging/psfl.txt ${S}/packaging/zpl.txt .
 find $RPM_BUILD_ROOT${prefix}/lib/python2.7/site-packages -name '*.exe' | xargs rm -f
 chmod +x $RPM_BUILD_ROOT${prefix}/lib/python2.7/site-packages/setuptools/command/easy_install.py
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " python-setuptools-dev "
PACKAGES += " python-setuptools "

python-setuptools-dev_files = ""
python-setuptools-dev_files += "${prefix}/lib/python2.7/site-packages/easy_install*"
python-setuptools-dev_files += "${prefix}/bin/*"
MANIFESTFILES_${PN}-dev = "python-setuptools.manifest"

python-setuptools_files = ""
python-setuptools_files += "${prefix}/lib/python2.7/site-packages/*"
MANIFESTFILES_${PN} = "python-setuptools.manifest"

FILES_${PN}-dev = "${python-setuptools-dev_files}"
FILES_${PN} = "${python-setuptools_files}"

PKG_python-setuptools-dev= "python-setuptools-dev"
PKG_python-setuptools= "python-setuptools"

require python-setuptools-extraconf.inc

