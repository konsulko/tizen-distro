DESCRIPTION = "GNU Portable Threads"
HOMEPAGE = "http://www.gnu.org/software/pth/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpth-devel 
PROVIDES += "libpth-devel"
RPROVIDES_libpth-devel += "libpth-devel"
RPROVIDES_libpth-devel += "libpth-dev"
# the PROVIDES rules is ignore "pth-devel = 2.0.7"
PROVIDES += "pth-devel"
RPROVIDES_libpth-devel += "pth-devel"
RPROVIDES_libpth-devel += "pth-dev"

#PROVIDES by libpth 
PROVIDES += "libpth"
RPROVIDES_libpth += "libpth"
# the PROVIDES rules is ignore "pth  "
PROVIDES += "pth"
RPROVIDES_libpth += "pth"

#PROVIDES by pth 
PROVIDES += "pth"
RPROVIDES_pth += "pth"

RDEPENDS = ""
#RDEPENDS of libpth-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libpth"


DEPENDS = ""
#DEPENDS of pth 
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pth.manifest .
 
 
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
 
 autoconf
 
 
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
             --enable-optimize=yes \
             --enable-pthread=no \
             --with-gnu-ld
 make pth_p.h
 make -j16
 
 exit 0
 make test
 
 
 
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
 #empty dependency_libs
 rm -f ${D}/usr/lib/libpth.la
 
 
}

PACKAGES = ""
PACKAGES += "libpth-devel"
PACKAGES += "libpth"

libpth-devel_files = ""
libpth-devel_files += "pth.manifest"
libpth-devel_files += "/usr/bin/pth-config"
libpth-devel_files += "/usr/include/pth.h"
libpth-devel_files += "/usr/share/aclocal"
libpth-devel_files += "/usr/share/aclocal/pth.m4"
libpth-devel_files += "/usr/lib/libpth*.so"
libpth-devel_files += "/usr/share/man/man1/*"
libpth-devel_files += "/usr/share/man/man3/*"

libpth_files = ""
libpth_files += "pth.manifest"
libpth_files += "COPYING"
libpth_files += "/usr/lib/libpth*.so.*"

FILES_lib${PN}-devel = "${libpth-devel_files}"
FILES_lib${PN} = "${libpth_files}"

PKG_libpth-devel= "libpth-devel"
PKG_libpth= "libpth"

require pth-extraconf.inc
