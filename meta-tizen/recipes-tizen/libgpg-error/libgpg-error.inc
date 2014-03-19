DESCRIPTION = "Library That Defines Common Error Values for All GnuPG Components"
HOMEPAGE = "http://www.gnupg.org/"
SECTION = "Security/Crypto Libraries"
LICENSE = "GPL-2.0+  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgpg-error-devel 
PROVIDES += "libgpg-error-devel"
RPROVIDES_libgpg-error-devel += "libgpg-error-devel"
RPROVIDES_libgpg-error-devel += "libgpg-error-dev"

#PROVIDES by libgpg-error 
PROVIDES += "libgpg-error"
RPROVIDES_libgpg-error += "libgpg-error"

#PROVIDES by libgpg-error-locale  
PROVIDES += "libgpg-error-locale "
RPROVIDES_libgpg-error-locale  += "libgpg-error-locale "
# the PROVIDES rules is ignore "libgpg-error-lang-all = 1.10"
PROVIDES += "libgpg-error-lang-all"
RPROVIDES_libgpg-error-locale  += "libgpg-error-lang-all"

RDEPENDS = ""
#RDEPENDS of libgpg-error-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libgpg-error"

#RDEPENDS of libgpg-error-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "libgpg-error"


DEPENDS = ""
#DEPENDS of libgpg-error 
DEPENDS += "libtool-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libgpg-error-1.10
 cp ${S}/packaging/libgpg-error.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic
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
 rm -r ${D}/usr/share/common-lisp
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libgpg-error
 
 
}

PACKAGES = ""
PACKAGES += "libgpg-error-devel"
PACKAGES += "libgpg-error-locale"
PACKAGES += "libgpg-error"

libgpg-error-devel_files = ""
libgpg-error-devel_files += "libgpg-error.manifest"
libgpg-error-devel_files += "/usr/share/aclocal/gpg-error.m4"
libgpg-error-devel_files += "/usr/include/*"
libgpg-error-devel_files += "/usr/bin/*"
libgpg-error-devel_files += "/usr/lib/libgpg-error*.so"

libgpg-error-locale_files = ""

libgpg-error_files = ""
libgpg-error_files += "libgpg-error.manifest"
libgpg-error_files += "GPL-2.0+ ; LGPL-2.1+ ; MIT COPYING.LIB COPYING"
libgpg-error_files += "/usr/lib/libgpg-error*.so.*"

FILES_${PN}-devel = "${libgpg-error-devel_files}"
FILES_${PN}-locale = "${libgpg-error-locale_files}"
FILES_${PN} = "${libgpg-error_files}"

PKG_libgpg-error-devel= "libgpg-error-devel"
PKG_libgpg-error-locale= "libgpg-error-locale"
PKG_libgpg-error= "libgpg-error"

require libgpg-error-extraconf.inc
