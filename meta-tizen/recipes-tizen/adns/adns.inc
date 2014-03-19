DESCRIPTION = "Advanced Easy-to-Use Asynchronous-Capable DNS Utilities"
HOMEPAGE = "http://www.chiark.greenend.org.uk/~ian/adns/"
SECTION = "Productivity/Networking/DNS/Utilities"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libadns 
PROVIDES += "libadns"
RPROVIDES_libadns += "libadns"

#PROVIDES by adns 
PROVIDES += "adns"
RPROVIDES_adns += "adns"

#PROVIDES by libadns-devel 
PROVIDES += "libadns-devel"
RPROVIDES_libadns-devel += "libadns-devel"
RPROVIDES_libadns-devel += "libadns-dev"

RDEPENDS = ""
#RDEPENDS of libadns-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libadns"
RDEPENDS_lib${PN}-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of adns 
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/adns.manifest .
 
 
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
 
 autoreconf -fiv
 
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
 make -j16 all
 
 
 
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
PACKAGES += "libadns"
PACKAGES += "adns"
PACKAGES += "libadns-devel"

libadns_files = ""
libadns_files += "adns.manifest"
libadns_files += "/usr/lib/libadns.so.1*"

adns_files = ""
adns_files += "adns.manifest"
adns_files += "/usr/bin/adns*"

libadns-devel_files = ""
libadns-devel_files += "adns.manifest"
libadns-devel_files += "/usr/include/adns.h"
libadns-devel_files += "/usr/lib/libadns.so"

FILES_lib${PN} = "${libadns_files}"
FILES_${PN} = "${adns_files}"
FILES_lib${PN}-devel = "${libadns-devel_files}"

PKG_libadns= "libadns"
PKG_adns= "adns"
PKG_libadns-devel= "libadns-devel"

require adns-extraconf.inc
