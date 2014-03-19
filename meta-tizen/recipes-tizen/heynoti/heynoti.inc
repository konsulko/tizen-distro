DESCRIPTION = "HEY (ligHt Easy speedy) notification library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by heynoti 
PROVIDES += "heynoti"
RPROVIDES_heynoti += "heynoti"

#PROVIDES by heynoti-devel 
PROVIDES += "heynoti-devel"
RPROVIDES_heynoti-devel += "heynoti-devel"
RPROVIDES_heynoti-devel += "heynoti-dev"

RDEPENDS = ""
#RDEPENDS of heynoti-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "heynoti"


DEPENDS = ""
#DEPENDS of heynoti 
DEPENDS += "ecore"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/heynoti.manifest .
 
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DCMAKE_BUILD_TYPE="Debug"
 
 
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
 
 mkdir -p ${D}/opt/share/noti
 
 
}

PACKAGES = ""
PACKAGES += "heynoti"
PACKAGES += "heynoti-devel"

heynoti_files = ""
heynoti_files += "heynoti.manifest"
heynoti_files += "/usr/lib/libheynoti.so.0"
heynoti_files += "/usr/lib/libheynoti.so.0.0.2"
heynoti_files += "/usr/bin/heynotitool"

heynoti-devel_files = ""
heynoti-devel_files += "heynoti.manifest"
heynoti-devel_files += "/usr/include/heynoti/SLP_Heynoti_PG.h"
heynoti-devel_files += "/usr/include/heynoti/heynoti.h"
heynoti-devel_files += "/usr/lib/pkgconfig/heynoti.pc"
heynoti-devel_files += "/usr/lib/libheynoti.so"

FILES_${PN} = "${heynoti_files}"
FILES_${PN}-devel = "${heynoti-devel_files}"

PKG_heynoti= "heynoti"
PKG_heynoti-devel= "heynoti-devel"

require heynoti-extraconf.inc
