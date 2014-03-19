DESCRIPTION = "A new approach to package dependency solving"
HOMEPAGE = "https://github.com/openSUSE/libsolv"
SECTION = "System/Package Management"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsolv-demo 
PROVIDES += "libsolv-demo"
RPROVIDES_libsolv-demo += "libsolv-demo"

#PROVIDES by libsolv 
PROVIDES += "libsolv"
RPROVIDES_libsolv += "libsolv"

#PROVIDES by perl-solv 
PROVIDES += "perl-solv"
RPROVIDES_perl-solv += "perl-solv"

#PROVIDES by libsolv-tools 
PROVIDES += "libsolv-tools"
RPROVIDES_libsolv-tools += "libsolv-tools"
# the PROVIDES rules is ignore "satsolver-tools = 0.18"
PROVIDES += "satsolver-tools"
RPROVIDES_libsolv-tools += "satsolver-tools"

#PROVIDES by python-solv 
PROVIDES += "python-solv"
RPROVIDES_python-solv += "python-solv"

#PROVIDES by libsolv-devel 
PROVIDES += "libsolv-devel"
RPROVIDES_libsolv-devel += "libsolv-devel"
RPROVIDES_libsolv-devel += "libsolv-dev"

RDEPENDS = ""
#RDEPENDS of libsolv-demo (${PN}-demo)
RDEPENDS_${PN}-demo += "curl"

#RDEPENDS of perl-solv (perl-solv)
RDEPENDS_perl-solv += "perl"

#RDEPENDS of libsolv-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "gzip"
RDEPENDS_${PN}-tools += "coreutils"
RDEPENDS_${PN}-tools += "bzip2"
RDEPENDS_${PN}-tools += "findutils"

#RDEPENDS of python-solv (python-solv)
RDEPENDS_python-solv += "python"

#RDEPENDS of libsolv-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsolv-tools"
RDEPENDS_${PN}-devel += "rpm-dev"
RDEPENDS_${PN}-devel += "libsolv"


DEPENDS = ""
#DEPENDS of libsolv 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "python-devel"
DEPENDS += "cmake"
DEPENDS += "swig"
DEPENDS += "expat"
inherit perlnative
DEPENDS += "rpm-devel"
DEPENDS += "fdupes-native"
DEPENDS += "db4"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n libsolv-0.3.0
 cp ${S}/packaging/libsolv.manifest .
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS"
 export CXXFLAGS="$CFLAGS"
 
 CMAKE_FLAGS=
 CMAKE_FLAGS="-DSUSE=1"
 
 cmake   $CMAKE_FLAGS \
 	-DCMAKE_INSTALL_PREFIX=/usr \
 	-DLIB=lib \
 	-DCMAKE_VERBOSE_MAKEFILE=TRUE \
 	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
 	-DENABLE_STATIC=1 \
 	-DENABLE_PERL=1 \
 	-DENABLE_PYTHON=1 \
 	-DUSE_VENDORDIRS=1 \
 	-DCMAKE_SKIP_RPATH=1
 make -j 16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install
 pushd $RPM_BUILD_ROOT//usr/lib64/python2.7/site-packages
 python /usr/lib/python2.7/py_compile.py *.py
 python -O /usr/lib/python2.7/py_compile.py *.py
 popd
 # we want to leave the .a file untouched
 export NO_BRP_STRIP_DEBUG=true
 
 
}

PACKAGES = ""
PACKAGES += "libsolv-demo"
PACKAGES += "libsolv"
PACKAGES += "perl-solv"
PACKAGES += "libsolv-tools"
PACKAGES += "python-solv"
PACKAGES += "libsolv-devel"

libsolv-demo_files = ""
libsolv-demo_files += "libsolv.manifest"
libsolv-demo_files += "/usr/bin/solv"

libsolv_files = ""
libsolv_files += "libsolv.manifest"
libsolv_files += "/usr/lib/libsolv.so.*"
libsolv_files += "/usr/lib/libsolvext.so.*"

perl-solv_files = ""
perl-solv_files += "libsolv.manifest"
perl-solv_files += "/usr/lib/perl/5.14.3/*"

libsolv-tools_files = ""
libsolv-tools_files += "libsolv.manifest"
libsolv-tools_files += "/usr/bin/solv"
libsolv-tools_files += "/usr/bin/*"

python-solv_files = ""
python-solv_files += "libsolv.manifest"
python-solv_files += "/usr/lib64/python2.7/site-packages/*"

libsolv-devel_files = ""
libsolv-devel_files += "libsolv.manifest"
libsolv-devel_files += "/usr/lib/libsolv.a"
libsolv-devel_files += "/usr/lib/libsolvext.a"
libsolv-devel_files += "/usr/lib/libsolv.so"
libsolv-devel_files += "/usr/lib/libsolvext.so"
libsolv-devel_files += "/usr/include/solv"
libsolv-devel_files += "/usr/bin/helix2solv"
libsolv-devel_files += "/usr/share/cmake/Modules/*"

FILES_${PN}-demo = "${libsolv-demo_files}"
FILES_${PN} = "${libsolv_files}"
FILES_perl-solv = "${perl-solv_files}"
FILES_${PN}-tools = "${libsolv-tools_files}"
FILES_python-solv = "${python-solv_files}"
FILES_${PN}-devel = "${libsolv-devel_files}"

PKG_libsolv-demo= "libsolv-demo"
PKG_libsolv= "libsolv"
PKG_perl-solv= "perl-solv"
PKG_libsolv-tools= "libsolv-tools"
PKG_python-solv= "python-solv"
PKG_libsolv-devel= "libsolv-devel"

require libsolv-extraconf.inc
