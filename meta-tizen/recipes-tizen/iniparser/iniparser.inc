DESCRIPTION = "Stand-alone ini file parsing library"
HOMEPAGE = "http://ndevilla.free.fr/iniparser/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iniparser-devel 
PROVIDES += "iniparser-devel"
RPROVIDES_iniparser-devel += "iniparser-devel"
RPROVIDES_iniparser-devel += "iniparser-dev"

#PROVIDES by iniparser 
PROVIDES += "iniparser"
RPROVIDES_iniparser += "iniparser"

RDEPENDS = ""
#RDEPENDS of iniparser-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "iniparser"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/iniparser.manifest .
 
 
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
 
 make prefix=/usr  -j16 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fPIC"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 mkdir -p ${D}//usr/lib
 install -m 755 libiniparser.so.0 ${D}//usr/lib
 ln -s libiniparser.so.0 ${D}//usr/lib/libiniparser.so
 mkdir -p ${D}//usr/include
 install -m 644 src/*.h ${D}//usr/include
 install -m 644 src/*.h ${D}//usr/include
 mkdir -p ${D}//usr/lib/pkgconfig
 cat > ${D}//usr/lib/pkgconfig/iniparser.pc <<EOF
 prefix = /usr
 exec_prefix = /usr
 libdir = /usr/lib
 includedir = /usr/include
 
 Name : iniparser
 Description : a free stand-alone ini file parsing library.
 Version : 2.17
 Libs : -L\${libdir} -liniparser
 Cflags : -I\${includedir}
 
 EOF
 
}

PACKAGES = ""
PACKAGES += "iniparser-devel"
PACKAGES += "iniparser"

iniparser-devel_files = ""
iniparser-devel_files += "iniparser.manifest"
iniparser-devel_files += "/usr/include/*.h"
iniparser-devel_files += "/usr/lib/*.so"
iniparser-devel_files += "/usr/lib/pkgconfig/*.pc"

iniparser_files = ""
iniparser_files += "iniparser.manifest"
iniparser_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${iniparser-devel_files}"
FILES_${PN} = "${iniparser_files}"

PKG_iniparser-devel= "iniparser-devel"
PKG_iniparser= "iniparser"

require iniparser-extraconf.inc
