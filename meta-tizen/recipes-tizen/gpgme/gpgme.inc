DESCRIPTION = "A Library Designed to Give Applications Easy Access to GnuPG"
HOMEPAGE = "http://www.gnupg.org/related_software/gpgme/"
SECTION = "Productivity/Security"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgpgme-devel 
PROVIDES += "libgpgme-devel"
RPROVIDES_libgpgme-devel += "libgpgme-devel"
RPROVIDES_libgpgme-devel += "libgpgme-dev"

#PROVIDES by libgpgme 
PROVIDES += "libgpgme"
RPROVIDES_libgpgme += "libgpgme"

#PROVIDES by gpgme 
PROVIDES += "gpgme"
RPROVIDES_gpgme += "gpgme"

RDEPENDS = ""
#RDEPENDS of libgpgme-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libgpgme"
RDEPENDS_lib${PN}-devel += "libgpg-error-dev"

#RDEPENDS of libgpgme (lib${PN})
RDEPENDS_lib${PN} += "gpg2"


DEPENDS = ""
#DEPENDS of gpgme 
DEPENDS += "libgpg-error-devel"
DEPENDS += "libassuan-devel"
DEPENDS += "gpg2"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gpgme.manifest .
 
 
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
 
 sh autogen.sh
 # Ensure that a (re)build uses fixed binaries with minimum version because
 # in case configure picks GnuPG-1.x, e.g. from /usr/local, this would cause
 # testsuite failures:
 
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
         --infodir=/usr/share/info --without-pth --disable-static \
 	--with-gpg-version=2.0.10	\
 	--with-gpgsm-version=2.0.10	\
 	--with-gpgconf-version=2.0.10	\
 	--with-gpg=/usr/bin/gpg2	\
 	--with-gpgsm=/usr/bin/gpgsm	\
 	--with-gpgconf=/usr/bin/gpgconf
 
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
PACKAGES += "libgpgme-devel"
PACKAGES += "libgpgme"
PACKAGES += "gpgme"

libgpgme-devel_files = ""
libgpgme-devel_files += "gpgme.manifest"
libgpgme-devel_files += "/usr/lib/libgpgme.so"
libgpgme-devel_files += "/usr/lib/libgpgme-pthread.so"
libgpgme-devel_files += "/usr/bin/gpgme-config"
libgpgme-devel_files += "/usr/share/aclocal/gpgme.m4"
libgpgme-devel_files += "/usr/include/gpgme.h"

libgpgme_files = ""
libgpgme_files += "gpgme.manifest"
libgpgme_files += "/usr/lib/libgpgme.so.*"
libgpgme_files += "/usr/lib/libgpgme-pthread.so.*"

gpgme_files = ""
gpgme_files += "gpgme.manifest"
gpgme_files += "/usr/share/common-lisp"
gpgme_files += "/usr/share/info/gpgme*"

FILES_lib${PN}-devel = "${libgpgme-devel_files}"
FILES_lib${PN} = "${libgpgme_files}"
FILES_${PN} = "${gpgme_files}"

PKG_libgpgme-devel= "libgpgme-devel"
PKG_libgpgme= "libgpgme"
PKG_gpgme= "gpgme"

require gpgme-extraconf.inc
