DESCRIPTION = "Application Information Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ail 
PROVIDES += "ail"
RPROVIDES_ail += "ail"
# the PROVIDES rules is ignore "libail = 0.2.73-1"
PROVIDES += "libail"
RPROVIDES_ail += "libail"

#PROVIDES by ail-devel 
PROVIDES += "ail-devel"
RPROVIDES_ail-devel += "ail-devel"
RPROVIDES_ail-devel += "ail-dev"

RDEPENDS = ""
#RDEPENDS of ail-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libail"


DEPENDS = ""
#DEPENDS of ail 
DEPENDS += "vconf-keys-devel"
DEPENDS += "pkgconfig(xdgmime)"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(db-util)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ail.manifest .
 
 
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
 
 CFLAGS+=" -fpic"
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .  -DBUILD_PKGTYPE=rpm \
 		  -DSMACK=Off
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/opt/dbspace/
 mkdir -p ${D}/opt/share/applications/
 
 
}

PACKAGES = ""
PACKAGES += "ail"
PACKAGES += "ail-devel"

ail_files = ""
ail_files += "ail.manifest"
ail_files += "/opt/share/applications"
ail_files += "/usr/bin/ail_initdb"
ail_files += "/usr/share/install-info/*"
ail_files += "/usr/lib/libail.so.0"
ail_files += "/usr/lib/libail.so.0.1.0"

ail-devel_files = ""
ail-devel_files += "ail.manifest"
ail-devel_files += "/usr/include/ail.h"
ail-devel_files += "/usr/lib/libail.so"
ail-devel_files += "/usr/lib/pkgconfig/ail.pc"

FILES_${PN} = "${ail_files}"
FILES_${PN}-devel = "${ail-devel_files}"

PKG_ail= "ail"
PKG_ail-devel= "ail-devel"

require ail-extraconf.inc
