DESCRIPTION = "The GNU Crypto Library"
HOMEPAGE = "http://directory.fsf.org/wiki/Libgcrypt"
SECTION = "Security/Crypto Libraries"
LICENSE = "GPL-2.0+  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgcrypt 
PROVIDES += "libgcrypt"
RPROVIDES_libgcrypt += "libgcrypt"

#PROVIDES by libgcrypt-devel 
PROVIDES += "libgcrypt-devel"
RPROVIDES_libgcrypt-devel += "libgcrypt-devel"
RPROVIDES_libgcrypt-devel += "libgcrypt-dev"

RDEPENDS = ""
#RDEPENDS of libgcrypt-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libgcrypt"
RDEPENDS_${PN}-devel += "libgpg-error-dev"


DEPENDS = ""
#DEPENDS of libgcrypt 
DEPENDS += "libgpg-error-devel"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libgcrypt.manifest .
 
 
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
 
 # define ciphers to build
 ENABLE_CIPHER="arcfour blowfish cast5 des aes twofish serpent rfc2268 seed camellia"
 ENABLE_PUBKEY="dsa elgamal rsa ecc"
 ENABLE_DIGEST="crc md4 md5 rmd160 sha1 sha256 sha512 tiger whirlpool"
 #
 autoreconf -fi
 
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
         --infodir=/usr/share/info --with-pic \
 		--enable-noexecstack \
 		--disable-static \
 		--enable-ciphers="$ENABLE_CIPHER" \
 		--enable-pubkey-ciphers="$ENABLE_PUBKEY" \
 		--enable-digests="$ENABLE_DIGEST"
 make -j16
 
 exit 0
 # Nice idea. however this uses /dev/random, which hangs
 # on hardware without random feeds.
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
 
 
}

PACKAGES = ""
PACKAGES += "libgcrypt"
PACKAGES += "libgcrypt-devel"

libgcrypt_files = ""
libgcrypt_files += "libgcrypt.manifest"
libgcrypt_files += "GFDL-1.1 ; GPL-2.0+ ; LGPL-2.1+ ; MIT COPYING COPYING.LIB"
libgcrypt_files += "/usr/lib/libgcrypt.so.11*"

libgcrypt-devel_files = ""
libgcrypt-devel_files += "libgcrypt.manifest"
libgcrypt-devel_files += "/usr/share/info/gcrypt.info.gz"
libgcrypt-devel_files += "/usr/share/info/gcrypt.info-1.gz"
libgcrypt-devel_files += "/usr/bin/dumpsexp"
libgcrypt-devel_files += "/usr/bin/hmac256"
libgcrypt-devel_files += "/usr/bin/libgcrypt-config"
libgcrypt-devel_files += "/usr/lib/libgcrypt.so"
libgcrypt-devel_files += "/usr/include/gcrypt*.h"
libgcrypt-devel_files += "/usr/share/aclocal/libgcrypt.m4"

FILES_${PN} = "${libgcrypt_files}"
FILES_${PN}-devel = "${libgcrypt-devel_files}"

PKG_libgcrypt= "libgcrypt"
PKG_libgcrypt-devel= "libgcrypt-devel"

require libgcrypt-extraconf.inc
