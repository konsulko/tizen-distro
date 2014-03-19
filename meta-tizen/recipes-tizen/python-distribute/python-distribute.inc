DESCRIPTION = "Easily download, build, install, upgrade, and uninstall Python packages"
HOMEPAGE = "http://packages.python.org/distribute"
SECTION = "Development/Languages/Python"
LICENSE = "Python-2.0 or ZPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-distribute 
PROVIDES += "python-distribute"
RPROVIDES_python-distribute += "python-distribute"
# the PROVIDES rules is ignore "python-setuptools = 0.6.30"
PROVIDES += "python-setuptools"
RPROVIDES_python-distribute += "python-setuptools"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-distribute 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n distribute-0.6.30
 cp ${S}/packaging/python-distribute.manifest .
 rm -f distribute.egg-info/*.orig
 chmod -x {.,docs}/*.txt # Fix executable bits for documentation
 
 
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
 
 python setup.py install --prefix=/usr --root=${D}
 rm -rf ${D}/usr/lib/python2.7/site-packages/setuptools/tests # Don't install tests
 rm -rf ${D}/usr/lib/python2.7/site-packages/setuptools/*.exe # Remove unneeded files
 
 
}

PACKAGES = ""
PACKAGES += "python-distribute"

python-distribute_files = ""
python-distribute_files += "python-distribute.manifest"
python-distribute_files += "/usr/bin/easy_install"
python-distribute_files += "/usr/bin/easy_install-2.7"
python-distribute_files += "/usr/lib/python2.7/site-packages/easy_install.py*"
python-distribute_files += "/usr/lib/python2.7/site-packages/pkg_resources.py*"
python-distribute_files += "/usr/lib/python2.7/site-packages/_markerlib/"
python-distribute_files += "/usr/lib/python2.7/site-packages/setuptools.pth"
python-distribute_files += "/usr/lib/python2.7/site-packages/setuptools/"
python-distribute_files += "/usr/lib/python2.7/site-packages/site.py*"
python-distribute_files += "/usr/lib/python2.7/site-packages/distribute-0.6.30-py2.7.egg-info/"
python-distribute_files += "/usr/lib/python2.7/site-packages/setuptools-*-py2.7.egg-info"

FILES_${PN} = "${python-distribute_files}"

PKG_python-distribute= "python-distribute"

require python-distribute-extraconf.inc
