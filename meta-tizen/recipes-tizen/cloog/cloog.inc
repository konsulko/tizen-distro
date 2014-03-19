DESCRIPTION = "The Chunky Loop Generator"
HOMEPAGE = "http://www.cloog.org/"
SECTION = "Development/Languages/C and C++"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cloog-devel 
PROVIDES += "cloog-devel"
RPROVIDES_cloog-devel += "cloog-devel"
RPROVIDES_cloog-devel += "cloog-dev"

#PROVIDES by libcloog 
PROVIDES += "libcloog"
RPROVIDES_libcloog += "libcloog"

#PROVIDES by cloog 
PROVIDES += "cloog"
RPROVIDES_cloog += "cloog"

RDEPENDS = ""
#RDEPENDS of cloog-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcloog"


DEPENDS = ""
#DEPENDS of cloog 
DEPENDS += "ppl-devel"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n cloog-ppl-0.15.10
 cp ${S}/packaging/cloog.manifest .
 
 
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
 
 ./autogen.sh
 
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
         --infodir=/usr/share/info --with-ppl
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
PACKAGES += "cloog-devel"
PACKAGES += "libcloog"
PACKAGES += "cloog"

cloog-devel_files = ""
cloog-devel_files += "cloog.manifest"
cloog-devel_files += "/usr/include/cloog"
cloog-devel_files += "/usr/lib/libcloog.so"
cloog-devel_files += "/usr/lib/libcloog.a"

libcloog_files = ""
libcloog_files += "cloog.manifest"
libcloog_files += "/usr/lib/libcloog.so.*"

cloog_files = ""
cloog_files += "cloog.manifest"
cloog_files += "/usr/bin/cloog"
cloog_files += "/usr/share/info/cloog.info*gz"

FILES_${PN}-devel = "${cloog-devel_files}"
FILES_lib${PN} = "${libcloog_files}"
FILES_${PN} = "${cloog_files}"

PKG_cloog-devel= "cloog-devel"
PKG_libcloog= "libcloog"
PKG_cloog= "cloog"

require cloog-extraconf.inc
