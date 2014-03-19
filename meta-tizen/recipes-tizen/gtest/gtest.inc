DESCRIPTION = "Google Test Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Testing"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gtest-devel 
PROVIDES += "gtest-devel"
RPROVIDES_gtest-devel += "gtest-devel"
RPROVIDES_gtest-devel += "gtest-dev"

#PROVIDES by gtest 
PROVIDES += "gtest"
RPROVIDES_gtest += "gtest"
# the PROVIDES rules is ignore "libgtest_main.so.0  "
PROVIDES += "libgtest_main.so.0"
RPROVIDES_gtest += "libgtest_main.so.0"
# the PROVIDES rules is ignore "libgtest.so.0  "
PROVIDES += "libgtest.so.0"
RPROVIDES_gtest += "libgtest.so.0"

RDEPENDS = ""
#RDEPENDS of gtest-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gtest"


DEPENDS = ""
#DEPENDS of gtest 
DEPENDS += "pkgconfig(python)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gtest.manifest .
 
 
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
 
 ./configure --prefix=/usr
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install
 
 
}

PACKAGES = ""
PACKAGES += "gtest-devel"
PACKAGES += "gtest"

gtest-devel_files = ""
gtest-devel_files += "gtest.manifest"
gtest-devel_files += "/usr/include/gtest/*.h"
gtest-devel_files += "/usr/include/gtest/internal/*.h"
gtest-devel_files += "/usr/lib/libgtest_main.so"
gtest-devel_files += "/usr/lib/libgtest.so"
gtest-devel_files += "/usr/lib/libgtest_main.la"
gtest-devel_files += "/usr/lib/libgtest_main.a"
gtest-devel_files += "/usr/lib/libgtest.la"
gtest-devel_files += "/usr/lib/libgtest.a"
gtest-devel_files += "/usr/share/aclocal/gtest.m4"

gtest_files = ""
gtest_files += "gtest.manifest"
gtest_files += "/usr/lib/libgtest_main.so.*"
gtest_files += "/usr/lib/libgtest.so.*"

FILES_${PN}-devel = "${gtest-devel_files}"
FILES_${PN} = "${gtest_files}"

PKG_gtest-devel= "gtest-devel"
PKG_gtest= "gtest"

require gtest-extraconf.inc
