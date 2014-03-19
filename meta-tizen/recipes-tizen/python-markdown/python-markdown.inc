DESCRIPTION = "Markdown implementation in Python"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Languages"
LICENSE = "BSD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-markdown 
PROVIDES += "python-markdown"
RPROVIDES_python-markdown += "python-markdown"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-markdown 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Markdown-2.0.3
 
 # remove shebangs
 find markdown -type f -name '*.py' \
   -exec sed -i -e '/^#!/{1D}' {} \;
 
 
 
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
 
 cp ${S}/packaging/python-markdown.manifest .
 /usr/bin/python setup.py build
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 /usr/bin/python setup.py install -O1 --skip-build --root ${D} --prefix /usr
 
 
 
}

PACKAGES = ""
PACKAGES += "python-markdown"

python-markdown_files = ""
python-markdown_files += "python-markdown.manifest"
python-markdown_files += "/usr/lib/python2.7/site-packages/*"
python-markdown_files += "/usr/bin/markdown"

FILES_${PN} = "${python-markdown_files}"

PKG_python-markdown= "python-markdown"

require python-markdown-extraconf.inc
