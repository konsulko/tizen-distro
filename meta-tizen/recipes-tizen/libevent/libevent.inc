DESCRIPTION = "Library Providing an Event Handling API"
HOMEPAGE = "http://monkey.org/~provos/libevent/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libevent-devel 
PROVIDES += "libevent-devel"
RPROVIDES_libevent-devel += "libevent-devel"
RPROVIDES_libevent-devel += "libevent-dev"
# the PROVIDES rules is ignore "libevent:/usr/include/event.h  "
PROVIDES += "libevent:/usr/include/event.h"
RPROVIDES_libevent-devel += "libevent:/usr/include/event.h"

#PROVIDES by libevent 
PROVIDES += "libevent"
RPROVIDES_libevent += "libevent"

RDEPENDS = ""
#RDEPENDS of libevent-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libevent"


DEPENDS = ""
#DEPENDS of libevent 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q  -n libevent-2.0.20-stable
 cp ${S}/packaging/libevent.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
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
 
 
}

PACKAGES = ""
PACKAGES += "libevent-devel"
PACKAGES += "libevent"

libevent-devel_files = ""
libevent-devel_files += "libevent.manifest"
libevent-devel_files += "/usr/bin/event_rpcgen.py"
libevent-devel_files += "/usr/include/*.h"
libevent-devel_files += "/usr/include/event2"
libevent-devel_files += "/usr/lib/libevent.so"
libevent-devel_files += "/usr/lib/libevent_core.so"
libevent-devel_files += "/usr/lib/libevent_extra.so"
libevent-devel_files += "/usr/lib/libevent_pthreads.so"
libevent-devel_files += "/usr/lib/pkgconfig/libevent.pc"
libevent-devel_files += "/usr/lib/pkgconfig/libevent_pthreads.pc"

libevent_files = ""
libevent_files += "libevent.manifest"
libevent_files += "/usr/lib/libevent-2.0.so.5*"
libevent_files += "/usr/lib/libevent_core-2.0.so.5*"
libevent_files += "/usr/lib/libevent_extra-2.0.so.5*"
libevent_files += "/usr/lib/libevent_pthreads-2.0.so.5*"

FILES_${PN}-devel = "${libevent-devel_files}"
FILES_${PN} = "${libevent_files}"

PKG_libevent-devel= "libevent-devel"
PKG_libevent= "libevent"

require libevent-extraconf.inc
