DESCRIPTION = "Library for monitoring the heap usage"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libheap-monitor 
PROVIDES += "libheap-monitor"
RPROVIDES_libheap-monitor += "libheap-monitor"

#PROVIDES by libheap-monitor-devel 
PROVIDES += "libheap-monitor-devel"
RPROVIDES_libheap-monitor-devel += "libheap-monitor-devel"
RPROVIDES_libheap-monitor-devel += "libheap-monitor-dev"

RDEPENDS = ""
#RDEPENDS of libheap-monitor-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libheap-monitor"


DEPENDS = ""
#DEPENDS of libheap-monitor 
DEPENDS += "cmake"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libheap-monitor.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DCMAKE_INSTALL_PREFIX=/usr
 CFLAGS+="${CFLAGS} -fvisibility=hidden -Wall -Werror -Winline -fno-builtin-malloc" make -j16
 
 
 
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
 mkdir -p ${D}//usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "libheap-monitor"
PACKAGES += "libheap-monitor-devel"

libheap-monitor_files = ""
libheap-monitor_files += "libheap-monitor.manifest"
libheap-monitor_files += "/usr/lib/*.so*"
libheap-monitor_files += "/usr/share/license/*"

libheap-monitor-devel_files = ""
libheap-monitor-devel_files += "libheap-monitor.manifest"
libheap-monitor-devel_files += "/usr/include/heap-monitor/heap-monitor.h"
libheap-monitor-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libheap-monitor_files}"
FILES_${PN}-devel = "${libheap-monitor-devel_files}"

PKG_libheap-monitor= "libheap-monitor"
PKG_libheap-monitor-devel= "libheap-monitor-devel"

require heap-monitor-extraconf.inc
