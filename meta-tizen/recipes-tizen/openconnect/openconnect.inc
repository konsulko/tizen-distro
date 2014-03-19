DESCRIPTION = "Open client for Cisco AnyConnect VPN"
HOMEPAGE = "http://www.infradead.org/openconnect.html"
SECTION = "Networking/Security"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by openconnect 
PROVIDES += "openconnect"
RPROVIDES_openconnect += "openconnect"

#PROVIDES by openconnect-devel 
PROVIDES += "openconnect-devel"
RPROVIDES_openconnect-devel += "openconnect-devel"
RPROVIDES_openconnect-devel += "openconnect-dev"

#PROVIDES by openconnect-docs  
PROVIDES += "openconnect-docs "
RPROVIDES_openconnect-docs  += "openconnect-docs "

RDEPENDS = ""
#RDEPENDS of openconnect (${PN})
RDEPENDS_${PN} += "vpnc"

#RDEPENDS of openconnect-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "openconnect"


DEPENDS = ""
#DEPENDS of openconnect 
DEPENDS += "pkgconfig(libproxy-1.0)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig-native"
DEPENDS += "openssl-devel"
DEPENDS += "vpnc"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/openconnect.manifest .
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info --docdir=/usr/share/doc/packages/openconnect/ --disable-nls
 make
 
 
 
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
PACKAGES += "openconnect"
PACKAGES += "openconnect-docs"
PACKAGES += "openconnect-devel"

openconnect_files = ""
openconnect_files += "openconnect.manifest"
openconnect_files += "/usr/lib/libopenconnect.so.*"
openconnect_files += "/usr/share/man/man8/*"
openconnect_files += "/usr/sbin/openconnect"

openconnect-docs_files = ""
openconnect-docs_files += "/usr/share/info"
openconnect-docs_files += "/usr/share/man"

openconnect-devel_files = ""
openconnect-devel_files += "openconnect.manifest"
openconnect-devel_files += "/usr/include/openconnect.h"
openconnect-devel_files += "/usr/lib/libopenconnect.so"
openconnect-devel_files += "/usr/lib/pkgconfig/openconnect.pc"

FILES_${PN} = "${openconnect_files}"
FILES_${PN}-docs = "${openconnect-docs_files}"
FILES_${PN}-devel = "${openconnect-devel_files}"

PKG_openconnect= "openconnect"
PKG_openconnect-docs= "openconnect-docs"
PKG_openconnect-devel= "openconnect-devel"

require openconnect-extraconf.inc
