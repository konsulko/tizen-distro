DESCRIPTION = "The ZeroMQ messaging library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libzmq 
PROVIDES += "libzmq"
RPROVIDES_libzmq += "libzmq"

#PROVIDES by zeromq 
PROVIDES += "zeromq"
RPROVIDES_zeromq += "zeromq"

#PROVIDES by zeromq-devel 
PROVIDES += "zeromq-devel"
RPROVIDES_zeromq-devel += "zeromq-devel"
RPROVIDES_zeromq-devel += "zeromq-dev"

RDEPENDS = ""
#RDEPENDS of zeromq (${PN})
RDEPENDS_${PN} += "libuuid"

#RDEPENDS of zeromq-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libzmq"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of zeromq 
inherit pythonnative
DEPENDS += "util-linux"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/zeromq.manifest .
 
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
         --infodir=/usr/share/info
 
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/zeromq 
   rm -rf ${D}/usr/share/doc/zeromq-3.2.2 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libzmq"
PACKAGES += "zeromq-devel"

libzmq_files = ""
libzmq_files += "zeromq.manifest"
libzmq_files += "/usr/lib/libzmq.so.3"
libzmq_files += "/usr/lib/libzmq.so.3.0.0"

zeromq-devel_files = ""
zeromq-devel_files += "zeromq.manifest"
zeromq-devel_files += "/usr/include/zmq.h"
zeromq-devel_files += "/usr/include/zmq_utils.h"
zeromq-devel_files += "/usr/lib/pkgconfig/libzmq.pc"
zeromq-devel_files += "/usr/lib/libzmq.so"

FILES_libzmq = "${libzmq_files}"
FILES_${PN}-devel = "${zeromq-devel_files}"

PKG_libzmq= "libzmq"
PKG_zeromq-devel= "zeromq-devel"

require zeromq-extraconf.inc
