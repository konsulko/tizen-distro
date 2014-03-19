DESCRIPTION = "A pipeline manipulation library"
HOMEPAGE = "http://www.nongnu.org/libpipeline/"
SECTION = "System/Libraries"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpipeline 
PROVIDES += "libpipeline"
RPROVIDES_libpipeline += "libpipeline"

#PROVIDES by libpipeline-devel 
PROVIDES += "libpipeline-devel"
RPROVIDES_libpipeline-devel += "libpipeline-devel"
RPROVIDES_libpipeline-devel += "libpipeline-dev"
# the PROVIDES rules is ignore "pkgconfig(libpipeline) = 1.2.2"
PROVIDES += "pkgconfig(libpipeline)"
RPROVIDES_libpipeline-devel += "pkgconfig(libpipeline)"

RDEPENDS = ""
#RDEPENDS of libpipeline-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpipeline"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpipeline.manifest .
 
 
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
         --infodir=/usr/share/info			\
   --enable-shared		\
   --enable-threads=posix	\
   --disable-rpath		\
   --enable-socketpair-pipe	\
   --with-pic=yes		\
   --with-gnu-ld
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
 
 
}

PACKAGES = ""
PACKAGES += "libpipeline"
PACKAGES += "libpipeline-devel"

libpipeline_files = ""
libpipeline_files += "libpipeline.manifest"
libpipeline_files += "/usr/lib/libpipeline.so.*"

libpipeline-devel_files = ""
libpipeline-devel_files += "libpipeline.manifest"
libpipeline-devel_files += "/usr/lib/libpipeline.so"
libpipeline-devel_files += "/usr/lib/pkgconfig/libpipeline.pc"
libpipeline-devel_files += "/usr/include/pipeline.h"
libpipeline-devel_files += "/usr/share/man/man3/*.3*"

FILES_${PN} = "${libpipeline_files}"
FILES_${PN}-devel = "${libpipeline-devel_files}"

PKG_libpipeline= "libpipeline"
PKG_libpipeline-devel= "libpipeline-devel"

require libpipeline-extraconf.inc
