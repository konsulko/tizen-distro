DESCRIPTION = "Utilities for SCTP (Stream Control Transmission Protocol)"
HOMEPAGE = "http://lksctp.sourceforge.net"
SECTION = "System/Network"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lksctp-tools-devel 
PROVIDES += "lksctp-tools-devel"
RPROVIDES_lksctp-tools-devel += "lksctp-tools-devel"
RPROVIDES_lksctp-tools-devel += "lksctp-tools-dev"

#PROVIDES by lksctp-tools 
PROVIDES += "lksctp-tools"
RPROVIDES_lksctp-tools += "lksctp-tools"

RDEPENDS = ""
#RDEPENDS of lksctp-tools-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "lksctp-tools"


DEPENDS = ""
#DEPENDS of lksctp-tools 
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/lksctp-tools.manifest .
 
 
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
 
 autoreconf --force --install
 CPPFLAGS="-I`pwd`/include" \
 
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
         --infodir=/usr/share/info --prefix=/usr \
 	--enable-shared \
 	--disable-static
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
 
 
}

PACKAGES = ""
PACKAGES += "lksctp-tools-devel"
PACKAGES += "lksctp-tools"

lksctp-tools-devel_files = ""
lksctp-tools-devel_files += "lksctp-tools.manifest"
lksctp-tools-devel_files += "/usr/include/netinet/sctp.h"
lksctp-tools-devel_files += "/usr/lib/libsctp.so"
lksctp-tools-devel_files += "/usr/lib/lksctp-tools"
lksctp-tools-devel_files += "/usr/lib/lksctp-tools/*.so"
lksctp-tools-devel_files += "/usr/share/lksctp-tools/"
lksctp-tools-devel_files += "/usr/share/man/man3/*"

lksctp-tools_files = ""
lksctp-tools_files += "lksctp-tools.manifest"
lksctp-tools_files += "/usr/bin/*"
lksctp-tools_files += "/usr/lib/libsctp.so.*"
lksctp-tools_files += "/usr/lib/lksctp-tools"
lksctp-tools_files += "/usr/lib/lksctp-tools/*.so.*"
lksctp-tools_files += "/usr/share/man/man7/*"

FILES_${PN}-devel = "${lksctp-tools-devel_files}"
FILES_${PN} = "${lksctp-tools_files}"

PKG_lksctp-tools-devel= "lksctp-tools-devel"
PKG_lksctp-tools= "lksctp-tools"

require lksctp-tools-extraconf.inc
