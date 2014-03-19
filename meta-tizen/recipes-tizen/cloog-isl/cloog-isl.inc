DESCRIPTION = "The Chunky Loop Generator"
HOMEPAGE = "http://www.cloog.org/"
SECTION = "Development/Toolchain"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cloog-isl-devel 
PROVIDES += "cloog-isl-devel"
RPROVIDES_cloog-isl-devel += "cloog-isl-devel"
RPROVIDES_cloog-isl-devel += "cloog-isl-dev"

#PROVIDES by cloog-isl 
PROVIDES += "cloog-isl"
RPROVIDES_cloog-isl += "cloog-isl"

#PROVIDES by libcloog-isl 
PROVIDES += "libcloog-isl"
RPROVIDES_libcloog-isl += "libcloog-isl"

RDEPENDS = ""
#RDEPENDS of cloog-isl-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcloog-isl"


DEPENDS = ""
#DEPENDS of cloog-isl 
DEPENDS += "isl-devel"
DEPENDS += "gmp-devel"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n cloog-0.18.0
 
 
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
         --infodir=/usr/share/info --with-isl=system --disable-static
 make -j16
 
 exit 0
 make -j16 check
 
 
 
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
   
 
 
}

PACKAGES = ""
PACKAGES += "cloog-isl-devel"
PACKAGES += "cloog-isl"
PACKAGES += "libcloog-isl"

cloog-isl-devel_files = ""
cloog-isl-devel_files += "/usr/include/cloog"
cloog-isl-devel_files += "/usr/lib/libcloog-isl.so"
cloog-isl-devel_files += "/usr/lib/pkgconfig/*.pc"

cloog-isl_files = ""
cloog-isl_files += "/usr/bin/cloog"

libcloog-isl_files = ""
libcloog-isl_files += "/usr/lib/libcloog-isl.so.*"

FILES_${PN}-devel = "${cloog-isl-devel_files}"
FILES_${PN} = "${cloog-isl_files}"
FILES_lib${PN} = "${libcloog-isl_files}"

PKG_cloog-isl-devel= "cloog-isl-devel"
PKG_cloog-isl= "cloog-isl"
PKG_libcloog-isl= "libcloog-isl"

require cloog-isl-extraconf.inc
