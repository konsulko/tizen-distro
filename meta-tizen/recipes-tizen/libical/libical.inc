DESCRIPTION = "An Implementation of Basic iCAL Protocols"
HOMEPAGE = "http://sourceforge.net/projects/freeassociation/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MPL-1.1 or LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libical-doc 
PROVIDES += "libical-doc"
RPROVIDES_libical-doc += "libical-doc"

#PROVIDES by libical 
PROVIDES += "libical"
RPROVIDES_libical += "libical"

#PROVIDES by libical-devel 
PROVIDES += "libical-devel"
RPROVIDES_libical-devel += "libical-devel"
RPROVIDES_libical-devel += "libical-dev"

RDEPENDS = ""
#RDEPENDS of libical-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "libical"

#RDEPENDS of libical-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libical"


DEPENDS = ""
#DEPENDS of libical 
DEPENDS += "python-devel"
DEPENDS += "libtool-cross"
DEPENDS += "db4"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libical.manifest .
 
 
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
 
 # triger autoreconf since the 0.46 tarball is missing autotools bootstrap files
 autoreconf -f -i
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info \
 	--with-bdb4 \
 	--with-bdb4-dir=/usr \
 	--without-builtintz \
 	--enable-shared \
 	--disable-static
 oe_runmake -j16
 
 
 
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
 /bin/rm doc/Makefile*
 /bin/rm -rf examples/.deps
 /bin/rm -rf examples/.libs
 /bin/rm examples/*.o
 /bin/rm examples/doesnothing
 /bin/rm scripts/Makefile*
 /bin/sed -i -e '1s,.*,#!/usr/bin/perl,' scripts/mkneticali.pl
 
 
}

PACKAGES = ""
PACKAGES += "libical-doc"
PACKAGES += "libical"
PACKAGES += "libical-devel"

libical-doc_files = ""
libical-doc_files += "libical.manifest"
libical-doc_files += "doc examples scripts"

libical_files = ""
libical_files += "libical.manifest"
libical_files += "/usr/lib/*.so.*"

libical-devel_files = ""
libical-devel_files += "libical.manifest"
libical-devel_files += "/usr/lib/*.so"
libical-devel_files += "/usr/lib/pkgconfig/libical.pc"
libical-devel_files += "/usr/include/ical.h"
libical-devel_files += "/usr/include/libical"

FILES_${PN}-doc = "${libical-doc_files}"
FILES_${PN} = "${libical_files}"
FILES_${PN}-devel = "${libical-devel_files}"

PKG_libical-doc= "libical-doc"
PKG_libical= "libical"
PKG_libical-devel= "libical-devel"

require libical-extraconf.inc
