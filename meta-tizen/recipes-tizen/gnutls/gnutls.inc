DESCRIPTION = "The GNU Transport Layer Security Library"
HOMEPAGE = "http://www.gnutls.org/"
SECTION = "Security/Crypto Libraries"
LICENSE = "LGPL-3.0+ and GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgnutlsxx 
PROVIDES += "libgnutlsxx"
RPROVIDES_libgnutlsxx += "libgnutlsxx"

#PROVIDES by libgnutls 
PROVIDES += "libgnutls"
RPROVIDES_libgnutls += "libgnutls"

#PROVIDES by libgnutls-devel 
PROVIDES += "libgnutls-devel"
RPROVIDES_libgnutls-devel += "libgnutls-devel"
RPROVIDES_libgnutls-devel += "libgnutls-dev"
# the PROVIDES rules is ignore "gnutls-devel = 3.0.30-0"
PROVIDES += "gnutls-devel"
RPROVIDES_libgnutls-devel += "gnutls-devel"
RPROVIDES_libgnutls-devel += "gnutls-dev"

#PROVIDES by libgnutls-openssl-devel 
PROVIDES += "libgnutls-openssl-devel"
RPROVIDES_libgnutls-openssl-devel += "libgnutls-openssl-devel"
RPROVIDES_libgnutls-openssl-devel += "libgnutls-openssl-dev"

#PROVIDES by libgnutlsxx-devel 
PROVIDES += "libgnutlsxx-devel"
RPROVIDES_libgnutlsxx-devel += "libgnutlsxx-devel"
RPROVIDES_libgnutlsxx-devel += "libgnutlsxx-dev"

#PROVIDES by gnutls 
PROVIDES += "gnutls"
RPROVIDES_gnutls += "gnutls"

#PROVIDES by libgnutls-openssl 
PROVIDES += "libgnutls-openssl"
RPROVIDES_libgnutls-openssl += "libgnutls-openssl"

RDEPENDS = ""
#RDEPENDS of libgnutls-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libgnutls"

#RDEPENDS of libgnutls-openssl-devel (lib${PN}-openssl-devel)
RDEPENDS_lib${PN}-openssl-devel += "libgnutls-dev"
RDEPENDS_lib${PN}-openssl-devel += "libgnutls-openssl"

#RDEPENDS of libgnutlsxx-devel (lib${PN}xx-devel)
RDEPENDS_lib${PN}xx-devel += "libgnutls-dev"
RDEPENDS_lib${PN}xx-devel += "libgnutlsxx"
RDEPENDS_lib${PN}xx-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of gnutls 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(nettle)"
DEPENDS += "libtasn1-devel"
DEPENDS += "pkgconfig-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"
DEPENDS += "xz"
DEPENDS += "libtool-cross"
DEPENDS += "libidn-devel"
DEPENDS += "p11-kit-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gnutls.manifest .
 echo /usr/include/gnutls/abstract.h
 
 
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
 
 autoreconf -if
 
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
         --disable-static \
         --with-pic \
         --disable-rpath \
         --disable-silent-rules \
 	--with-default-trust-store-dir=/etc/ssl/certs \
         --with-sysroot=/
 make -j16
 
 # 17-ago-2011, Test suite passes in factory, just not
 #in the build system due to some broken code requiring both networking
 #and fixes.
 #make check
 
 
 
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
 rm -rf doc/examples/.deps doc/examples/.libs doc/examples/*.{o,lo,la} doc/examples/Makefile{,.in}
 find doc/examples -perm -111 -exec rm {} \;
 rm -rf ${D}/usr/share/locale/en@{,bold}quot
 # Do not package static libs and libtool files
 rm -f ${D}/usr/lib/*.la
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libgnutls --all-name
 
 
}

PACKAGES = ""
PACKAGES += "libgnutlsxx"
PACKAGES += "libgnutls"
PACKAGES += "libgnutls-devel"
PACKAGES += "libgnutls-openssl-devel"
PACKAGES += "libgnutlsxx-devel"
PACKAGES += "gnutls"
PACKAGES += "libgnutls-openssl"

libgnutlsxx_files = ""
libgnutlsxx_files += "gnutls.manifest"
libgnutlsxx_files += "/usr/lib/libgnutlsxx.so.*"

libgnutls_files = ""
libgnutls_files += "gnutls.manifest"
libgnutls_files += "/usr/lib/libgnutls.so.*"

libgnutls-devel_files = ""
libgnutls-devel_files += "gnutls.manifest"
libgnutls-devel_files += "/usr/include/gnutls"
libgnutls-devel_files += "/usr/include/gnutls/abstract.h"
libgnutls-devel_files += "/usr/include/gnutls/crypto.h"
libgnutls-devel_files += "/usr/include/gnutls/compat.h"
libgnutls-devel_files += "/usr/include/gnutls/dtls.h"
libgnutls-devel_files += "/usr/include/gnutls/gnutls.h"
libgnutls-devel_files += "/usr/include/gnutls/openpgp.h"
libgnutls-devel_files += "/usr/include/gnutls/ocsp.h"
libgnutls-devel_files += "/usr/include/gnutls/pkcs11.h"
libgnutls-devel_files += "/usr/include/gnutls/pkcs12.h"
libgnutls-devel_files += "/usr/include/gnutls/x509.h"
libgnutls-devel_files += "/usr/lib/libgnutls.so"
libgnutls-devel_files += "/usr/lib/pkgconfig/gnutls.pc"
libgnutls-devel_files += "/usr/share/man/man3/*"
libgnutls-devel_files += "/usr/share/info/*.*"
libgnutls-devel_files += "doc/examples doc/gnutls.html doc/*.png doc/gnutls.pdf doc/reference/html/*"

libgnutls-openssl-devel_files = ""
libgnutls-openssl-devel_files += "gnutls.manifest"
libgnutls-openssl-devel_files += "/usr/lib/libgnutls-openssl.so"
libgnutls-openssl-devel_files += "/usr/include/gnutls"
libgnutls-openssl-devel_files += "/usr/include/gnutls/openssl.h"

libgnutlsxx-devel_files = ""
libgnutlsxx-devel_files += "gnutls.manifest"
libgnutlsxx-devel_files += "/usr/lib/libgnutlsxx.so"
libgnutlsxx-devel_files += "/usr/include/gnutls"
libgnutlsxx-devel_files += "/usr/include/gnutls/gnutlsxx.h"

gnutls_files = ""
gnutls_files += "gnutls.manifest"
gnutls_files += "GPL-3.0+ COPYING"
gnutls_files += "/usr/bin/certtool"
gnutls_files += "/usr/bin/crywrap"
gnutls_files += "/usr/bin/gnutls-cli"
gnutls_files += "/usr/bin/gnutls-cli-debug"
gnutls_files += "/usr/bin/gnutls-serv"
gnutls_files += "/usr/bin/ocsptool"
gnutls_files += "/usr/bin/psktool"
gnutls_files += "/usr/bin/p11tool"
gnutls_files += "/usr/bin/srptool"
gnutls_files += "/usr/share/man/man1/*"

libgnutls-openssl_files = ""
libgnutls-openssl_files += "gnutls.manifest"
libgnutls-openssl_files += "/usr/lib/libgnutls-openssl.so.*"

FILES_lib${PN}xx = "${libgnutlsxx_files}"
FILES_lib${PN} = "${libgnutls_files}"
FILES_lib${PN}-devel = "${libgnutls-devel_files}"
FILES_lib${PN}-openssl-devel = "${libgnutls-openssl-devel_files}"
FILES_lib${PN}xx-devel = "${libgnutlsxx-devel_files}"
FILES_${PN} = "${gnutls_files}"
FILES_lib${PN}-openssl = "${libgnutls-openssl_files}"

PKG_libgnutlsxx= "libgnutlsxx"
PKG_libgnutls= "libgnutls"
PKG_libgnutls-devel= "libgnutls-devel"
PKG_libgnutls-openssl-devel= "libgnutls-openssl-devel"
PKG_libgnutlsxx-devel= "libgnutlsxx-devel"
PKG_gnutls= "gnutls"
PKG_libgnutls-openssl= "libgnutls-openssl"

require gnutls-extraconf.inc
