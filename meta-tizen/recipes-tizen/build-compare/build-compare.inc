DESCRIPTION = "Build Result Compare Script"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by build-compare 
PROVIDES += "build-compare"
RPROVIDES_build-compare += "build-compare"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 mkdir $RPM_BUILD_DIR/build-compare-2012.01.26
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -T 0 -D
 cp ${S}/packaging/build-compare.manifest .
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/usr/lib/build/ $RPM_BUILD_ROOT//usr/share/doc/packages/build-compare
 install -m 0755 ${S}/packaging/same-build-result.sh ${S}/packaging/rpm-check.sh ${S}/packaging/functions.sh ${S}/packaging/srpm-check.sh $RPM_BUILD_ROOT/usr/lib/build/
 install -m 0644 ${S}/packaging/COPYING $RPM_BUILD_ROOT//usr/share/doc/packages/build-compare/
 
 
}

PACKAGES = ""
PACKAGES += "build-compare"

build-compare_files = ""
build-compare_files += "build-compare.manifest"
build-compare_files += "/usr/share/doc/packages/build-compare"
build-compare_files += "/usr/lib/build"

FILES_${PN} = "${build-compare_files}"

PKG_build-compare= "build-compare"

require build-compare-extraconf.inc
