DESCRIPTION = "PCI access library"
HOMEPAGE = "http://gitweb.freedesktop.org/?p=xorg/lib/libpciaccess.git"
SECTION = "Base/Device Management"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpciaccess 
PROVIDES += "libpciaccess"
RPROVIDES_libpciaccess += "libpciaccess"

#PROVIDES by libpciaccess-devel 
PROVIDES += "libpciaccess-devel"
RPROVIDES_libpciaccess-devel += "libpciaccess-devel"
RPROVIDES_libpciaccess-devel += "libpciaccess-dev"

RDEPENDS = ""
#RDEPENDS of libpciaccess-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpciaccess"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of libpciaccess 
DEPENDS += "zlib-devel"
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpciaccess.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static \
            --with-pciids-path=/usr/share/misc --with-zlib
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/libpciaccess 
   rm -rf ${D}/usr/share/doc/libpciaccess-0.13.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libpciaccess"
PACKAGES += "libpciaccess-devel"

libpciaccess_files = ""
libpciaccess_files += "libpciaccess.manifest"
libpciaccess_files += "/usr/lib/libpciaccess.so.0"
libpciaccess_files += "/usr/lib/libpciaccess.so.0.11.*"

libpciaccess-devel_files = ""
libpciaccess-devel_files += "libpciaccess.manifest"
libpciaccess-devel_files += "/usr/include/pciaccess.h"
libpciaccess-devel_files += "/usr/lib/libpciaccess.so"
libpciaccess-devel_files += "/usr/lib/pkgconfig/pciaccess.pc"

FILES_${PN} = "${libpciaccess_files}"
FILES_${PN}-devel = "${libpciaccess-devel_files}"

PKG_libpciaccess= "libpciaccess"
PKG_libpciaccess-devel= "libpciaccess-devel"

require libpciaccess-extraconf.inc
