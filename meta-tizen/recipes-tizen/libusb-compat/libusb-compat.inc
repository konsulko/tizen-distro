DESCRIPTION = "libusb-1.0 Compatibility Layer for libusb-0.1"
HOMEPAGE = "http://libusb.wiki.sourceforge.net/LibusbCompat0.1"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libusb-compat 
PROVIDES += "libusb-compat"
RPROVIDES_libusb-compat += "libusb-compat"

#PROVIDES by libusb-compat-devel 
PROVIDES += "libusb-compat-devel"
RPROVIDES_libusb-compat-devel += "libusb-compat-devel"
RPROVIDES_libusb-compat-devel += "libusb-compat-dev"

RDEPENDS = ""
#RDEPENDS of libusb-compat-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libusb-compat"


DEPENDS = ""
#DEPENDS of libusb-compat 
DEPENDS += "pkgconfig(libusb-1.0)"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libusb-compat.manifest .
 
 
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
 
 cp ${S}/packaging/libusb-compat.manifest .
 
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
         --infodir=/usr/share/info\
 	--disable-static\
 	--disable-build-docs
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
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 rm ${D}/usr/lib/*.la
 
 
}

PACKAGES = ""
PACKAGES += "libusb-compat"
PACKAGES += "libusb-compat-devel"

libusb-compat_files = ""
libusb-compat_files += "libusb-compat.manifest"
libusb-compat_files += "AUTHORS COPYING ChangeLog LICENSE NEWS README"
libusb-compat_files += "/usr/lib/*.so.*"

libusb-compat-devel_files = ""
libusb-compat-devel_files += "libusb-compat.manifest"
libusb-compat-devel_files += "/usr/bin/*-config"
libusb-compat-devel_files += "/usr/include/*.h"
libusb-compat-devel_files += "/usr/lib/*.so"
libusb-compat-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libusb-compat_files}"
FILES_${PN}-devel = "${libusb-compat-devel_files}"

PKG_libusb-compat= "libusb-compat"
PKG_libusb-compat-devel= "libusb-compat-devel"

require libusb-compat-extraconf.inc
