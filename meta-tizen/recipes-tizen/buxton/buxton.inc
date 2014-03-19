DESCRIPTION = "A security-enabled configuration system"
HOMEPAGE = "https://github.com/sofar/buxton"
SECTION = "System/Configuration"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by buxton-devel 
PROVIDES += "buxton-devel"
RPROVIDES_buxton-devel += "buxton-devel"
RPROVIDES_buxton-devel += "buxton-dev"

#PROVIDES by buxton-docs  
PROVIDES += "buxton-docs "
RPROVIDES_buxton-docs  += "buxton-docs "

#PROVIDES by buxton 
PROVIDES += "buxton"
RPROVIDES_buxton += "buxton"

RDEPENDS = ""
#RDEPENDS of buxton-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "buxton"

#RDEPENDS of buxton (${PN})
RDEPENDS_${PN} += "/usr/bin/chown"
RDEPENDS_${PN} += "smack"
RDEPENDS_${PN} += "buxton"


DEPENDS = ""
#DEPENDS of buxton 
DEPENDS += "pkgconfig(systemd)"
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(check)"
DEPENDS += "attr"
DEPENDS += "gdbm-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/buxton.manifest .
 
 
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
 # TODO: need to define needed layers for Tizen in tizen.conf
 install -m 0644 ${S}/packaging/tizen.conf ${D}/etc/buxton.conf
 
 
}

PACKAGES = ""
PACKAGES += "buxton-devel"
PACKAGES += "buxton-docs"
PACKAGES += "buxton"

buxton-devel_files = ""
buxton-devel_files += "buxton.manifest"
buxton-devel_files += "/usr/include/buxton.h"
buxton-devel_files += "/usr/lib/libbuxton.so"
buxton-devel_files += "/usr/lib/pkgconfig/*.pc"

buxton-docs_files = ""
buxton-docs_files += "/usr/share/info"
buxton-docs_files += "/usr/share/man"

buxton_files = ""
buxton_files += "buxton.manifest"
buxton_files += "/etc/buxton.conf"
buxton_files += "/usr/bin/buxtonctl"
buxton_files += "/usr/lib/buxton/*.so"
buxton_files += "/usr/lib/libbuxton.so.*"
buxton_files += "/usr/lib/systemd/system/buxton.service"
buxton_files += "/usr/lib/systemd/system/buxton.socket"
buxton_files += "/usr/lib/systemd/system/sockets.target.wants/buxton.socket"
buxton_files += "/usr/sbin/buxtond"

FILES_${PN}-devel = "${buxton-devel_files}"
FILES_${PN}-docs = "${buxton-docs_files}"
FILES_${PN} = "${buxton_files}"

PKG_buxton-devel= "buxton-devel"
PKG_buxton-docs= "buxton-docs"
PKG_buxton= "buxton"

require buxton-extraconf.inc
