DESCRIPTION = "MPEG-4 library"
HOMEPAGE = "http://code.google.com/p/mp4v2/"
SECTION = "Multimedia/Libraries"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmp4v2-devel 
PROVIDES += "libmp4v2-devel"
RPROVIDES_libmp4v2-devel += "libmp4v2-devel"
RPROVIDES_libmp4v2-devel += "libmp4v2-dev"

#PROVIDES by libmp4v2 
PROVIDES += "libmp4v2"
RPROVIDES_libmp4v2 += "libmp4v2"

RDEPENDS = ""
#RDEPENDS of libmp4v2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmp4v2"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libmp4v2-2.0.0
 
 
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
         --infodir=/usr/share/info
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
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
PACKAGES += "libmp4v2-devel"
PACKAGES += "libmp4v2"

libmp4v2-devel_files = ""
libmp4v2-devel_files += "/usr/include/*"
libmp4v2-devel_files += "/usr/lib/*.so"

libmp4v2_files = ""
libmp4v2_files += "README"
libmp4v2_files += "/usr/lib/*.so.*"
libmp4v2_files += "/usr/bin/*"
libmp4v2_files += "/usr/share/man/man1/*"

FILES_${PN}-devel = "${libmp4v2-devel_files}"
FILES_${PN} = "${libmp4v2_files}"

PKG_libmp4v2-devel= "libmp4v2-devel"
PKG_libmp4v2= "libmp4v2"

require libmp4v2-extraconf.inc
