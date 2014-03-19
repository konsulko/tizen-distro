DESCRIPTION = "KSBA Library"
HOMEPAGE = "http://www.gnupg.org/aegypten/"
SECTION = "Security/Libraries"
LICENSE = "GPL-3.0+ and LGPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libksba 
PROVIDES += "libksba"
RPROVIDES_libksba += "libksba"

#PROVIDES by libksba-devel 
PROVIDES += "libksba-devel"
RPROVIDES_libksba-devel += "libksba-devel"
RPROVIDES_libksba-devel += "libksba-dev"
# the PROVIDES rules is ignore "libksba:/usr/include/ksba.h  "
PROVIDES += "libksba:/usr/include/ksba.h"
RPROVIDES_libksba-devel += "libksba:/usr/include/ksba.h"

RDEPENDS = ""
#RDEPENDS of libksba-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libgpg-error-dev"
RDEPENDS_${PN}-devel += "libksba"


DEPENDS = ""
#DEPENDS of libksba 
DEPENDS += "libtool-cross"
DEPENDS += "libgpg-error"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libksba-1.3.0
 cp ${S}/packaging/libksba.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic
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
PACKAGES += "libksba"
PACKAGES += "libksba-devel"

libksba_files = ""
libksba_files += "libksba.manifest"
libksba_files += "/usr/lib/libksba*.so.*"

libksba-devel_files = ""
libksba-devel_files += "libksba.manifest"
libksba-devel_files += "/usr/bin/*"
libksba-devel_files += "/usr/lib/libksba*.so"
libksba-devel_files += "/usr/include/*"
libksba-devel_files += "/usr/share/info/ksba*"
libksba-devel_files += "/usr/share/aclocal/*"

FILES_${PN} = "${libksba_files}"
FILES_${PN}-devel = "${libksba-devel_files}"

PKG_libksba= "libksba"
PKG_libksba-devel= "libksba-devel"

require libksba-extraconf.inc
