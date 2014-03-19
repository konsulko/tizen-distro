DESCRIPTION = "A fast key-value storage library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libleveldb 
PROVIDES += "libleveldb"
RPROVIDES_libleveldb += "libleveldb"

#PROVIDES by leveldb 
PROVIDES += "leveldb"
RPROVIDES_leveldb += "leveldb"

#PROVIDES by leveldb-devel 
PROVIDES += "leveldb-devel"
RPROVIDES_leveldb-devel += "leveldb-devel"
RPROVIDES_leveldb-devel += "leveldb-dev"

RDEPENDS = ""
#RDEPENDS of leveldb-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libleveldb"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/leveldb.manifest .
 
 
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
 
 make libdir=/usr/lib -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} libdir=/usr/lib
 
 
 
}

PACKAGES = ""
PACKAGES += "libleveldb"
PACKAGES += "leveldb-devel"

libleveldb_files = ""
libleveldb_files += "leveldb.manifest"
libleveldb_files += "/usr/lib/libleveldb.so.0"
libleveldb_files += "/usr/lib/libleveldb.so.1.1.0"
libleveldb_files += "/usr/lib/libmemenv.so.0"
libleveldb_files += "/usr/lib/libmemenv.so.1.1.0"

leveldb-devel_files = ""
leveldb-devel_files += "leveldb.manifest"
leveldb-devel_files += "/usr/lib/libmemenv.so"
leveldb-devel_files += "/usr/lib/pkgconfig/leveldb.pc"
leveldb-devel_files += "/usr/lib/pkgconfig/memenv.pc"
leveldb-devel_files += "/usr/include/leveldb/*.h"
leveldb-devel_files += "/usr/include/helpers/memenv/*.h"
leveldb-devel_files += "/usr/lib/libleveldb.so"

FILES_lib${PN} = "${libleveldb_files}"
FILES_${PN}-devel = "${leveldb-devel_files}"

PKG_libleveldb= "libleveldb"
PKG_leveldb-devel= "leveldb-devel"

require leveldb-extraconf.inc
