DESCRIPTION = "A syntax highlighting engine written in Python"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "BSD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-pygments 
PROVIDES += "python-pygments"
RPROVIDES_python-pygments += "python-pygments"

RDEPENDS = ""
#RDEPENDS of python-pygments (${PN})
RDEPENDS_${PN} += "python-setuptools"


DEPENDS = ""
#DEPENDS of python-pygments 
inherit pythonnative
DEPENDS += "python-distribute"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cp ${S}/packaging/python-pygments.manifest .
 /usr/bin/python setup.py build
 /bin/sed -i 's/\r//' LICENSE
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 /usr/bin/python setup.py install -O1 --skip-build --root ${D} --prefix=/usr
 
 
}

PACKAGES = ""
PACKAGES += "python-pygments"

python-pygments_files = ""
python-pygments_files += "python-pygments.manifest"
python-pygments_files += "/usr/lib/python2.7/site-packages/*"
python-pygments_files += "/usr/bin/pygmentize"

FILES_${PN} = "${python-pygments_files}"

PKG_python-pygments= "python-pygments"

require python-pygments-extraconf.inc
