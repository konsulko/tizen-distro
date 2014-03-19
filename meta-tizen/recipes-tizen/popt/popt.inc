DESCRIPTION = "A C library for parsing command line parameters"
HOMEPAGE = "http://www.rpm5.org/"
SECTION = "Base/Libraries"
LICENSE = "XFree86-1.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpopt 
PROVIDES += "libpopt"
RPROVIDES_libpopt += "libpopt"
# the PROVIDES rules is ignore "popt = 1.16"
PROVIDES += "popt"
RPROVIDES_libpopt += "popt"

#PROVIDES by popt-locale  
PROVIDES += "popt-locale "
RPROVIDES_popt-locale  += "popt-locale "
# the PROVIDES rules is ignore "popt-lang-all = 1.16"
PROVIDES += "popt-lang-all"
RPROVIDES_popt-locale  += "popt-lang-all"

#PROVIDES by popt-devel 
PROVIDES += "popt-devel"
RPROVIDES_popt-devel += "popt-devel"
RPROVIDES_popt-devel += "popt-dev"

#PROVIDES by popt 
PROVIDES += "popt"
RPROVIDES_popt += "popt"

RDEPENDS = ""
#RDEPENDS of popt-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "popt"

#RDEPENDS of popt-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpopt"


DEPENDS = ""
#DEPENDS of popt 

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/popt.manifest .
 
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
         --infodir=/usr/share/info --with-pic --disable-static
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
 
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} popt
 
 
}

PACKAGES = ""
PACKAGES += "libpopt"
PACKAGES += "popt-devel"
PACKAGES += "popt-locale"

libpopt_files = ""
libpopt_files += "popt.manifest"
libpopt_files += "/usr/lib/libpopt.so.*"

popt-devel_files = ""
popt-devel_files += "popt.manifest"
popt-devel_files += "README"
popt-devel_files += "/usr/lib/libpopt.so"
popt-devel_files += "/usr/include/popt.h"
popt-devel_files += "/usr/share/man/man3/popt.3*"
popt-devel_files += "/usr/lib/pkgconfig/popt.pc"

popt-locale_files = ""

FILES_lib${PN} = "${libpopt_files}"
FILES_${PN}-devel = "${popt-devel_files}"
FILES_${PN}-locale = "${popt-locale_files}"

PKG_libpopt= "libpopt"
PKG_popt-devel= "popt-devel"
PKG_popt-locale= "popt-locale"

require popt-extraconf.inc
