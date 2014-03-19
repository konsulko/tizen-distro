DESCRIPTION = "The libatasmart"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libatasmart 
PROVIDES += "libatasmart"
RPROVIDES_libatasmart += "libatasmart"

#PROVIDES by libatasmart-devel 
PROVIDES += "libatasmart-devel"
RPROVIDES_libatasmart-devel += "libatasmart-devel"
RPROVIDES_libatasmart-devel += "libatasmart-dev"

RDEPENDS = ""
#RDEPENDS of libatasmart (${PN})
RDEPENDS_${PN} += "libdevmapper"

#RDEPENDS of libatasmart-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libatasmart"


DEPENDS = ""
#DEPENDS of libatasmart 
DEPENDS += "pkgconfig(systemd)"
DEPENDS += "pkgconfig(libudev)"
DEPENDS += "device-mapper"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 ./autogen.sh
 
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
         --infodir=/usr/share/info CFLAGS='-g -O0 -Wp,-U_FORTIFY_SOURCE' --sysconfdir=/etc --localstatedir=/var --libdir=/usr/lib --libexecdir=/usr/lib
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
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
PACKAGES += "libatasmart"
PACKAGES += "libatasmart-devel"

libatasmart_files = ""
libatasmart_files += "/usr/lib/libatasmart.so"
libatasmart_files += "/usr/lib/libatasmart.so.4"
libatasmart_files += "/usr/lib/libatasmart.so.4.0.5"
libatasmart_files += "/usr/sbin/skdump"
libatasmart_files += "/usr/sbin/sktest"
libatasmart_files += "/usr/share/doc/libatasmart/README"
libatasmart_files += "/usr/share/vala/vapi/atasmart.vapi"

libatasmart-devel_files = ""
libatasmart-devel_files += "/usr/include/atasmart.h"
libatasmart-devel_files += "/usr/lib/libatasmart.so"
libatasmart-devel_files += "/usr/lib/pkgconfig/libatasmart.pc"

FILES_${PN} = "${libatasmart_files}"
FILES_${PN}-devel = "${libatasmart-devel_files}"

PKG_libatasmart= "libatasmart"
PKG_libatasmart-devel= "libatasmart-devel"

require libatasmart-extraconf.inc
