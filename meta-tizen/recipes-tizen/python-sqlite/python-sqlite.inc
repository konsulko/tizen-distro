DESCRIPTION = "DB-API 2.0 interface for SQLite 3.x"
HOMEPAGE = "http://pysqlite.googlecode.com/"
SECTION = "Platform Development/Python"
LICENSE = "Zlib"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-sqlite 
PROVIDES += "python-sqlite"
RPROVIDES_python-sqlite += "python-sqlite"

RDEPENDS = ""
#RDEPENDS of python-sqlite (${PN})
RDEPENDS_${PN} += "sqlite3"


DEPENDS = ""
#DEPENDS of python-sqlite 
inherit pythonnative
DEPENDS += "sqlite3-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n pysqlite-2.6.3
 cp ${S}/packaging/python-sqlite.manifest .
 
 
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
 rm -rf ${D}/usr/pysqlite2-doc # Remove wrongly installed junk
 
 
}

PACKAGES = ""
PACKAGES += "python-sqlite"

python-sqlite_files = ""
python-sqlite_files += "python-sqlite.manifest"
python-sqlite_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${python-sqlite_files}"

PKG_python-sqlite= "python-sqlite"

require python-sqlite-extraconf.inc
