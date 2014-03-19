DESCRIPTION = "Command Line Editing and History Library"
HOMEPAGE = "http://www.thrysoee.dk/editline/"
SECTION = "Development/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libedit-devel 
PROVIDES += "libedit-devel"
RPROVIDES_libedit-devel += "libedit-devel"
RPROVIDES_libedit-devel += "libedit-dev"

#PROVIDES by libedit 
PROVIDES += "libedit"
RPROVIDES_libedit += "libedit"

RDEPENDS = ""
#RDEPENDS of libedit-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libedit"


DEPENDS = ""
#DEPENDS of libedit 
DEPENDS += "gcc-cross"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"
DEPENDS += "ncurses-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libedit-20130712-3.1
 
 
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
 
 NOCONFIGURE=1 autoreconf -fiv
 
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
         --infodir=/usr/share/info --disable-static --with-pic \
     --disable-silent-rules \
     --enable-widec
 
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
PACKAGES += "libedit-devel"
PACKAGES += "libedit"

libedit-devel_files = ""
libedit-devel_files += "/usr/lib/libedit.so"
libedit-devel_files += "/usr/include/histedit.h"
libedit-devel_files += "/usr/include/editline/"
libedit-devel_files += "/usr/share/man/man3/*.3.gz"
libedit-devel_files += "/usr/lib/pkgconfig/libedit.pc"

libedit_files = ""
libedit_files += "/usr/lib/libedit.so.*"
libedit_files += "/usr/share/man/man5/editrc.5*"

FILES_${PN}-devel = "${libedit-devel_files}"
FILES_${PN} = "${libedit_files}"

PKG_libedit-devel= "libedit-devel"
PKG_libedit= "libedit"

require libedit-extraconf.inc
