DESCRIPTION = "Lightweight C library That Eases the Writing of UNIX Daemons"
HOMEPAGE = "http://0pointer.de/lennart/projects/libdaemon/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdaemon-devel 
PROVIDES += "libdaemon-devel"
RPROVIDES_libdaemon-devel += "libdaemon-devel"
RPROVIDES_libdaemon-devel += "libdaemon-dev"

#PROVIDES by libdaemon 
PROVIDES += "libdaemon"
RPROVIDES_libdaemon += "libdaemon"

RDEPENDS = ""
#RDEPENDS of libdaemon-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libdaemon"


DEPENDS = ""
#DEPENDS of libdaemon 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libdaemon.manifest .
 
 
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
         --disable-static --with-pic \
         --disable-lynx
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
 # We don't care about the HTML README
 rm ${D}/usr/share/doc/libdaemon/{README.html,style.css}
 
 
}

PACKAGES = ""
PACKAGES += "libdaemon-devel"
PACKAGES += "libdaemon"

libdaemon-devel_files = ""
libdaemon-devel_files += "libdaemon.manifest"
libdaemon-devel_files += "/usr/lib/libdaemon.so"
libdaemon-devel_files += "/usr/lib/pkgconfig/libdaemon.pc"
libdaemon-devel_files += "/usr/include/libdaemon"
libdaemon-devel_files += "/usr/include/libdaemon/*.h"

libdaemon_files = ""
libdaemon_files += "libdaemon.manifest"
libdaemon_files += "LICENSE"
libdaemon_files += "/usr/lib/libdaemon.so.0*"

FILES_${PN}-devel = "${libdaemon-devel_files}"
FILES_${PN} = "${libdaemon_files}"

PKG_libdaemon-devel= "libdaemon-devel"
PKG_libdaemon= "libdaemon"

require libdaemon-extraconf.inc
