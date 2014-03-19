DESCRIPTION = "The GNU multiple-precision floating-point library"
HOMEPAGE = "http://www.mpfr.org/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmpfr 
PROVIDES += "libmpfr"
RPROVIDES_libmpfr += "libmpfr"

#PROVIDES by mpfr-devel 
PROVIDES += "mpfr-devel"
RPROVIDES_mpfr-devel += "mpfr-devel"
RPROVIDES_mpfr-devel += "mpfr-dev"

#PROVIDES by mpfr 
PROVIDES += "mpfr"
RPROVIDES_mpfr += "mpfr"

RDEPENDS = ""
#RDEPENDS of mpfr-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmpfr"
RDEPENDS_${PN}-devel += "gmp-dev"


DEPENDS = ""
#DEPENDS of mpfr 
DEPENDS += "gmp"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/mpfr.manifest .
 
 
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
         --infodir=/usr/share/info \
 	--enable-thread-safe \
 	--enable-shared
 make -j16
 
 exit 0
 make check -j16
 
 
 
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
   
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/mpfr 
   rm -rf ${D}/usr/share/doc/mpfr-3.1.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libmpfr"
PACKAGES += "mpfr-devel"

libmpfr_files = ""
libmpfr_files += "mpfr.manifest"
libmpfr_files += "/usr/lib/libmpfr.so.4*"

mpfr-devel_files = ""
mpfr-devel_files += "mpfr.manifest"
mpfr-devel_files += "/usr/lib/libmpfr.a"
mpfr-devel_files += "/usr/lib/libmpfr.so"
mpfr-devel_files += "/usr/include/mpf2mpfr.h"
mpfr-devel_files += "/usr/include/mpfr.h"

FILES_lib${PN} = "${libmpfr_files}"
FILES_${PN}-devel = "${mpfr-devel_files}"

PKG_libmpfr= "libmpfr"
PKG_mpfr-devel= "mpfr-devel"

require mpfr-extraconf.inc
