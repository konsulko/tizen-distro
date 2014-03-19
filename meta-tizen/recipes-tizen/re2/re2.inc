DESCRIPTION = "An efficient, principled regular expression library"
HOMEPAGE = "http://code.google.com/p/re2/"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by re2 
PROVIDES += "re2"
RPROVIDES_re2 += "re2"

#PROVIDES by libre2 
PROVIDES += "libre2"
RPROVIDES_libre2 += "libre2"

#PROVIDES by re2-devel 
PROVIDES += "re2-devel"
RPROVIDES_re2-devel += "re2-devel"
RPROVIDES_re2-devel += "re2-dev"

RDEPENDS = ""
#RDEPENDS of re2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libre2"


DEPENDS = ""
#DEPENDS of re2 
DEPENDS += "gcc-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n re2
 
 
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
 
 make -j16 CXXFLAGS="$RPM_OPT_FLAGS -Wall -pthread" libdir=/usr/lib prefix=/usr
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT libdir=/usr/lib prefix=/usr install
 rm $RPM_BUILD_ROOT/usr/lib/libre2.a
 
 
 
}

PACKAGES = ""
PACKAGES += "libre2"
PACKAGES += "re2-devel"

libre2_files = ""
libre2_files += "AUTHORS README"
libre2_files += "/usr/lib/libre2.so.0"
libre2_files += "/usr/lib/libre2.so.0.0.0"

re2-devel_files = ""
re2-devel_files += "/usr/include/re2"
re2-devel_files += "/usr/lib/libre2.so"

FILES_lib${PN} = "${libre2_files}"
FILES_${PN}-devel = "${re2-devel_files}"

PKG_libre2= "libre2"
PKG_re2-devel= "re2-devel"

require re2-extraconf.inc
