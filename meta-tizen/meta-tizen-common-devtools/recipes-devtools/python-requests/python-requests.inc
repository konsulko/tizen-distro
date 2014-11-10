DESCRIPTION = "Awesome Python HTTP Library That's Actually Usable"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "Apache-2.0"
PV = "2.2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by python-requests


RDEPENDS = ""
#RDEPENDS of python-requests (${PN})
RDEPENDS_${PN} += "python"


DEPENDS = ""
#DEPENDS of python-requests
inherit pythonnative
DEPENDS += "python-setuptools"
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n requests-2.2.1
 cp  ${S}/packaging/python-requests.manifest .
 # for rpmlint warning: remove shebang from python library
 sed -i '/^#!/d' ./requests/certs.py
 sed -i '/^#!/d' ./requests/packages/chardet/chardetect.py
 
 
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
 
 python setup.py build
 
 exit 0
 python setup.py test
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 python setup.py install --skip-build --prefix=${prefix} --root=${D}
 #fdupes $RPM_BUILD_ROOT
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " python-requests "

python-requests_files = ""
python-requests_files += "${prefix}/lib/python2.7/site-packages/*"
MANIFESTFILES_${PN} = "python-requests.manifest"

FILES_${PN} = "${python-requests_files}"

PKG_python-requests= "python-requests"

require python-requests-extraconf.inc

