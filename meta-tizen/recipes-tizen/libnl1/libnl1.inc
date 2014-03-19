DESCRIPTION = "Convenience library for kernel netlink sockets"
HOMEPAGE = "http://people.suug.ch/~tgr/libnl/"
SECTION = "System/Network"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libnl1 
PROVIDES += "libnl1"
RPROVIDES_libnl1 += "libnl1"

#PROVIDES by libnl1-devel 
PROVIDES += "libnl1-devel"
RPROVIDES_libnl1-devel += "libnl1-devel"
RPROVIDES_libnl1-devel += "libnl1-dev"
# the PROVIDES rules is ignore "libnl-devel = 1-1.1"
PROVIDES += "libnl-devel"
RPROVIDES_libnl1-devel += "libnl-devel"
RPROVIDES_libnl1-devel += "libnl-dev"

RDEPENDS = ""
#RDEPENDS of libnl1-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libnl1"


DEPENDS = ""
#DEPENDS of libnl1 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libnl-1.1
 cp ${S}/packaging/libnl1.manifest .
 
 
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
     --prefix=/usr \
     --libdir=/usr/lib \
     --includedir=/usr/include
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
 mkdir -p ${D}//usr/lib/pkgconfig
 
 
}

PACKAGES = ""
PACKAGES += "libnl1"
PACKAGES += "libnl1-devel"

libnl1_files = ""
libnl1_files += "libnl1.manifest"
libnl1_files += "/usr/lib/libnl*.so.*"

libnl1-devel_files = ""
libnl1-devel_files += "libnl1.manifest"
libnl1-devel_files += "/usr/include/netlink/"
libnl1-devel_files += "/usr/lib/libnl*.so"
libnl1-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libnl1_files}"
FILES_${PN}-devel = "${libnl1-devel_files}"

PKG_libnl1= "libnl1"
PKG_libnl1-devel= "libnl1-devel"

require libnl1-extraconf.inc
