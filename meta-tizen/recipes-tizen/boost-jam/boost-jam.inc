DESCRIPTION = "An Enhanced Make Replacement"
HOMEPAGE = "http://www.boost.org/"
SECTION = "Development/Tools/Building"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by boost-jam 
PROVIDES += "boost-jam"
RPROVIDES_boost-jam += "boost-jam"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of boost-jam 
DEPENDS += "xz"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/boost-jam.manifest .
 find . -type f|xargs chmod -R u+w
 
 
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
 
 export RPM_OPT_FLAGS="$RPM_OPT_FLAGS -Wall -fno-strict-aliasing"
 export CFLAGS="$RPM_OPT_FLAGS"
 LOCATE_TARGET=bin ./build.sh gcc --symbols
 # Trivial test: -- Documented used of bjam -v: Print the version of jam and exit:
 bin/bjam -v
 ln  -s bin bin.linux
 cd ..
 tar xvf ${S}/packaging/test.tar.gz
 ln -s boost-jam-201104 src
 cd test
 sh test.sh || if [ $? -gt 5 ]; then sh test.sh;fi
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 mkdir -p $RPM_BUILD_ROOT/usr/share/doc/packages/boost-jam-201104
 install -m 755 bin/bjam ${D}/usr/bin/bjam-201104
 ln -sf bjam-201104 ${D}/usr/bin/bjam
 ln -sf bjam-201104 ${D}/usr/bin/jam
 
 
}

PACKAGES = ""
PACKAGES += "boost-jam"

boost-jam_files = ""
boost-jam_files += "boost-jam.manifest"

FILES_${PN} = "${boost-jam_files}"

PKG_boost-jam= "boost-jam"

require boost-jam-extraconf.inc
