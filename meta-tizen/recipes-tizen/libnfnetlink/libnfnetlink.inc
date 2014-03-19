DESCRIPTION = "Low-level library for Netfilter-related kernel/userspace communication"
HOMEPAGE = "http://netfilter.org/projects/libnfnetlink/"
SECTION = "Productivity/Networking/Security"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libnfnetlink 
PROVIDES += "libnfnetlink"
RPROVIDES_libnfnetlink += "libnfnetlink"

#PROVIDES by libnfnetlink-devel 
PROVIDES += "libnfnetlink-devel"
RPROVIDES_libnfnetlink-devel += "libnfnetlink-devel"
RPROVIDES_libnfnetlink-devel += "libnfnetlink-dev"

RDEPENDS = ""
#RDEPENDS of libnfnetlink-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libnfnetlink"


DEPENDS = ""
#DEPENDS of libnfnetlink 
DEPENDS += "xz"
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libnfnetlink.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --includedir=/usr/include/libnfnetlink-1.0.1
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
PACKAGES += "libnfnetlink"
PACKAGES += "libnfnetlink-devel"

libnfnetlink_files = ""
libnfnetlink_files += "libnfnetlink.manifest"
libnfnetlink_files += "COPYING"
libnfnetlink_files += "/usr/lib/libnfnetlink.so.*"

libnfnetlink-devel_files = ""
libnfnetlink-devel_files += "libnfnetlink.manifest"
libnfnetlink-devel_files += "/usr/include/libnfnetlink*"
libnfnetlink-devel_files += "/usr/lib/libnfnetlink.so"
libnfnetlink-devel_files += "/usr/lib/pkgconfig/libnfnetlink.pc"

FILES_${PN} = "${libnfnetlink_files}"
FILES_${PN}-devel = "${libnfnetlink-devel_files}"

PKG_libnfnetlink= "libnfnetlink"
PKG_libnfnetlink-devel= "libnfnetlink-devel"

require libnfnetlink-extraconf.inc
