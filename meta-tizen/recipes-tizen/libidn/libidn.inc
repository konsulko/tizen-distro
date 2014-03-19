DESCRIPTION = "Support for Internationalized Domain Names (IDN)"
HOMEPAGE = "http://www.gnu.org/software/libidn/"
SECTION = "System/Libraries"
LICENSE = "(GPL-2.0+ or LGPL-3.0+) and GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libidn-docs  
PROVIDES += "libidn-docs "
RPROVIDES_libidn-docs  += "libidn-docs "

#PROVIDES by libidn 
PROVIDES += "libidn"
RPROVIDES_libidn += "libidn"

#PROVIDES by libidn-locale  
PROVIDES += "libidn-locale "
RPROVIDES_libidn-locale  += "libidn-locale "
# the PROVIDES rules is ignore "libidn-lang-all = 1.25"
PROVIDES += "libidn-lang-all"
RPROVIDES_libidn-locale  += "libidn-lang-all"

#PROVIDES by libidn-devel 
PROVIDES += "libidn-devel"
RPROVIDES_libidn-devel += "libidn-devel"
RPROVIDES_libidn-devel += "libidn-dev"

RDEPENDS = ""
#RDEPENDS of libidn-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "libidn"

#RDEPENDS of libidn-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libidn"


DEPENDS = ""
#DEPENDS of libidn 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libidn.manifest .
 
 
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
         --infodir=/usr/share/info --with-pic --disable-static --disable-gtk-doc
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
 rm -f ${D}//usr/share/info/dir
 rm -f ${D}/usr/lib/libidn.la
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libidn
 
 
 
}

PACKAGES = ""
PACKAGES += "libidn-locale"
PACKAGES += "libidn-devel"
PACKAGES += "libidn"
PACKAGES += "libidn-docs"

libidn-locale_files = ""

libidn-devel_files = ""
libidn-devel_files += "libidn.manifest"
libidn-devel_files += "/usr/lib/libidn.so"
libidn-devel_files += "/usr/include/*.h"
libidn-devel_files += "/usr/lib/pkgconfig/libidn.pc"

libidn_files = ""
libidn_files += "libidn.manifest"
libidn_files += "LGPL-2.1+ COPYING"
libidn_files += "/usr/lib/libidn.so.*"
libidn_files += "/usr/share/info/libidn*"
libidn_files += "/usr/bin/idn"
libidn_files += "/usr/share/emacs/site-lisp/idna.el"
libidn_files += "/usr/share/emacs/site-lisp/punycode.el"

libidn-docs_files = ""
libidn-docs_files += "/usr/share/info"
libidn-docs_files += "/usr/share/man"

FILES_${PN}-locale = "${libidn-locale_files}"
FILES_${PN}-devel = "${libidn-devel_files}"
FILES_${PN} = "${libidn_files}"
FILES_${PN}-docs = "${libidn-docs_files}"

PKG_libidn-locale= "libidn-locale"
PKG_libidn-devel= "libidn-devel"
PKG_libidn= "libidn"
PKG_libidn-docs= "libidn-docs"

require libidn-extraconf.inc
