DESCRIPTION = "A fast metadata parser for yum"
HOMEPAGE = "http://linux.duke.edu/projects/yum/"
SECTION = "Development/Libraries"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by yum-metadata-parser 
PROVIDES += "yum-metadata-parser"
RPROVIDES_yum-metadata-parser += "yum-metadata-parser"

RDEPENDS = ""
#RDEPENDS of yum-metadata-parser (${PN})
RDEPENDS_${PN} += "glib2"


DEPENDS = ""
#DEPENDS of yum-metadata-parser 
inherit pythonnative
DEPENDS += "sqlite"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/yum-metadata-parser.manifest .
 
 
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
 
 rm -rf ${D}
 python setup.py install -O1 --root=${D}
 
 
}

PACKAGES = ""
PACKAGES += "yum-metadata-parser"

yum-metadata-parser_files = ""
yum-metadata-parser_files += "yum-metadata-parser.manifest"
yum-metadata-parser_files += "/usr/lib64/python2.7/site-packages/_sqlitecache.so"
yum-metadata-parser_files += "/usr/lib64/python2.7/site-packages/sqlitecachec.py"
yum-metadata-parser_files += "/usr/lib64/python2.7/site-packages/sqlitecachec.pyc"
yum-metadata-parser_files += "/usr/lib64/python2.7/site-packages/sqlitecachec.pyo"
yum-metadata-parser_files += "/usr/lib64/python2.7/site-packages/*egg-info"

FILES_${PN} = "${yum-metadata-parser_files}"

PKG_yum-metadata-parser= "yum-metadata-parser"

require yum-metadata-parser-extraconf.inc
