DESCRIPTION = "Library for netlink sockets"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Network"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libnl3 
PROVIDES += "libnl3"
RPROVIDES_libnl3 += "libnl3"

#PROVIDES by libnl3-cli 
PROVIDES += "libnl3-cli"
RPROVIDES_libnl3-cli += "libnl3-cli"

#PROVIDES by libnl3-devel 
PROVIDES += "libnl3-devel"
RPROVIDES_libnl3-devel += "libnl3-devel"
RPROVIDES_libnl3-devel += "libnl3-dev"

RDEPENDS = ""
#RDEPENDS of libnl3-cli (${PN}-cli)
RDEPENDS_${PN}-cli += "libnl3"

#RDEPENDS of libnl3-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libnl3"


DEPENDS = ""
#DEPENDS of libnl3 
DEPENDS += "flex"
DEPENDS += "bison-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libnl3.manifest .
 
 
 
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
 
 chmod +x autogen.sh
 
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
         --infodir=/usr/share/info.sh
 
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
 
 make -j1
 
 
 
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
 rm -f ${D}/etc/libnl/pktloc
 
 
}

PACKAGES = ""
PACKAGES += "libnl3"
PACKAGES += "libnl3-cli"
PACKAGES += "libnl3-devel"

libnl3_files = ""
libnl3_files += "libnl3.manifest"
libnl3_files += "/usr/lib/libnl*.so.*"
libnl3_files += "/etc/*"

libnl3-cli_files = ""
libnl3-cli_files += "/usr/lib/libnl-cli*.so.*"
libnl3-cli_files += "/usr/lib/libnl/"
libnl3-cli_files += "/usr/sbin/*"
libnl3-cli_files += "/usr/share/man/man8/*"

libnl3-devel_files = ""
libnl3-devel_files += "libnl3.manifest"
libnl3-devel_files += "/usr/include/*"
libnl3-devel_files += "/usr/lib/pkgconfig/*"
libnl3-devel_files += "/usr/lib/libnl*.so"

FILES_${PN} = "${libnl3_files}"
FILES_${PN}-cli = "${libnl3-cli_files}"
FILES_${PN}-devel = "${libnl3-devel_files}"

PKG_libnl3= "libnl3"
PKG_libnl3-cli= "libnl3-cli"
PKG_libnl3-devel= "libnl3-devel"

require libnl3-extraconf.inc
