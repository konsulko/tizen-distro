DESCRIPTION = "An IRI parsing library"
HOMEPAGE = "http://code.google.com/p/libiri/"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libiri-devel 
PROVIDES += "libiri-devel"
RPROVIDES_libiri-devel += "libiri-devel"
RPROVIDES_libiri-devel += "libiri-dev"

#PROVIDES by libiri 
PROVIDES += "libiri"
RPROVIDES_libiri += "libiri"

RDEPENDS = ""
#RDEPENDS of libiri-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libiri"


DEPENDS = ""
#DEPENDS of libiri 
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libiri.manifest .
 
 
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
 
 sh ./autogen.sh
 
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
PACKAGES += "libiri-devel"
PACKAGES += "libiri"

libiri-devel_files = ""
libiri-devel_files += "libiri.manifest"
libiri-devel_files += "/usr/lib/pkgconfig/*.pc"
libiri-devel_files += "/usr/include/*.h"
libiri-devel_files += "/usr/bin/iri-config"

libiri_files = ""
libiri_files += "libiri.manifest"
libiri_files += "/usr/lib/*.so"

FILES_${PN}-devel = "${libiri-devel_files}"
FILES_${PN} = "${libiri_files}"

PKG_libiri-devel= "libiri-devel"
PKG_libiri= "libiri"

require libiri-extraconf.inc
