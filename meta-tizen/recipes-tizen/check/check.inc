DESCRIPTION = "Unit Test Framework for C"
HOMEPAGE = "http://check.sourceforge.net/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by check 
PROVIDES += "check"
RPROVIDES_check += "check"

#PROVIDES by check-devel 
PROVIDES += "check-devel"
RPROVIDES_check-devel += "check-devel"
RPROVIDES_check-devel += "check-dev"

RDEPENDS = ""
#RDEPENDS of check-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "check"


DEPENDS = ""
#DEPENDS of check 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/check.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -std=gnu99"
 export CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -std=gnu99"
 export FFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -std=gnu99"
 
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/check 
   rm -rf ${D}/usr/share/doc/check-0.9.8 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
}

PACKAGES = ""
PACKAGES += "check"
PACKAGES += "check-devel"

check_files = ""
check_files += "check.manifest"
check_files += "/usr/lib/*.so.*"

check-devel_files = ""
check-devel_files += "check.manifest"
check-devel_files += "/usr/share/aclocal"
check-devel_files += "/usr/share/aclocal/*.m4"
check-devel_files += "/usr/include/*.h"
check-devel_files += "/usr/lib/*.so"
check-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${check_files}"
FILES_${PN}-devel = "${check-devel_files}"

PKG_check= "check"
PKG_check-devel= "check-devel"

require check-extraconf.inc
