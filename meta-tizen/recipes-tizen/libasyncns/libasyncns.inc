DESCRIPTION = "A C library for executing name service queries asynchronously"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libasyncns 
PROVIDES += "libasyncns"
RPROVIDES_libasyncns += "libasyncns"

#PROVIDES by libasyncns-devel 
PROVIDES += "libasyncns-devel"
RPROVIDES_libasyncns-devel += "libasyncns-devel"
RPROVIDES_libasyncns-devel += "libasyncns-dev"

RDEPENDS = ""
#RDEPENDS of libasyncns-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libasyncns"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libasyncns.manifest .
 
 
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
 
 rm -rf ${D}/usr/share/doc
 
 
 
}

PACKAGES = ""
PACKAGES += "libasyncns"
PACKAGES += "libasyncns-devel"

libasyncns_files = ""
libasyncns_files += "libasyncns.manifest"
libasyncns_files += "/usr/lib/libasyncns.so.*"

libasyncns-devel_files = ""
libasyncns-devel_files += "libasyncns.manifest"
libasyncns-devel_files += "/usr/include/asyncns.h"
libasyncns-devel_files += "/usr/lib/libasyncns.so"
libasyncns-devel_files += "/usr/lib/pkgconfig/libasyncns.pc"

FILES_${PN} = "${libasyncns_files}"
FILES_${PN}-devel = "${libasyncns-devel_files}"

PKG_libasyncns= "libasyncns"
PKG_libasyncns-devel= "libasyncns-devel"

require libasyncns-extraconf.inc
