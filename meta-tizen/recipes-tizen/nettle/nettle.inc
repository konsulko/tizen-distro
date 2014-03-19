DESCRIPTION = "Cryptographic Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Crypto Libraries"
LICENSE = "LGPL-2.1+ and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by nettle 
PROVIDES += "nettle"
RPROVIDES_nettle += "nettle"

#PROVIDES by libhogweed 
PROVIDES += "libhogweed"
RPROVIDES_libhogweed += "libhogweed"

#PROVIDES by libnettle-devel 
PROVIDES += "libnettle-devel"
RPROVIDES_libnettle-devel += "libnettle-devel"
RPROVIDES_libnettle-devel += "libnettle-dev"

#PROVIDES by libnettle 
PROVIDES += "libnettle"
RPROVIDES_libnettle += "libnettle"

RDEPENDS = ""
#RDEPENDS of libnettle-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "gmp-dev"
RDEPENDS_lib${PN}-devel += "libhogweed"
RDEPENDS_lib${PN}-devel += "libnettle"


DEPENDS = ""
#DEPENDS of nettle 
DEPENDS += "gmp"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/nettle.manifest .
 
 
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
 	 --enable-shared
 
 make -j16
 
 exit 0
 make check
 
 
 
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
PACKAGES += "nettle"
PACKAGES += "libhogweed"
PACKAGES += "libnettle-devel"
PACKAGES += "libnettle"

nettle_files = ""
nettle_files += "nettle.manifest"
nettle_files += "/usr/bin/nettle-lfib-stream"
nettle_files += "/usr/bin/pkcs1-conv"
nettle_files += "/usr/bin/sexp-conv"
nettle_files += "/usr/bin/nettle-hash"

libhogweed_files = ""
libhogweed_files += "nettle.manifest"
libhogweed_files += "/usr/lib/libhogweed.so.*"

libnettle-devel_files = ""
libnettle-devel_files += "nettle.manifest"
libnettle-devel_files += "/usr/include/nettle"
libnettle-devel_files += "/usr/lib/libnettle.so"
libnettle-devel_files += "/usr/lib/libhogweed.so"
libnettle-devel_files += "/usr/share/info/nettle.info.gz"
libnettle-devel_files += "/usr/lib/pkgconfig/hogweed.pc"
libnettle-devel_files += "/usr/lib/pkgconfig/nettle.pc"

libnettle_files = ""
libnettle_files += "nettle.manifest"
libnettle_files += "/usr/lib/libnettle.so.*"

FILES_${PN} = "${nettle_files}"
FILES_libhogweed = "${libhogweed_files}"
FILES_lib${PN}-devel = "${libnettle-devel_files}"
FILES_lib${PN} = "${libnettle_files}"

PKG_nettle= "nettle"
PKG_libhogweed= "libhogweed"
PKG_libnettle-devel= "libnettle-devel"
PKG_libnettle= "libnettle"

require nettle-extraconf.inc
