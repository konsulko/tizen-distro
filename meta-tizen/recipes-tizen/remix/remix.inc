DESCRIPTION = "An audio sequencing and mixing library"
HOMEPAGE = "http://www.metadecks.org/software/remix/"
SECTION = "Multimedia/Audio"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libremix 
PROVIDES += "libremix"
RPROVIDES_libremix += "libremix"

#PROVIDES by remix-devel 
PROVIDES += "remix-devel"
RPROVIDES_remix-devel += "remix-devel"
RPROVIDES_remix-devel += "remix-dev"

#PROVIDES by remix 
PROVIDES += "remix"
RPROVIDES_remix += "remix"

RDEPENDS = ""
#RDEPENDS of remix-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libremix"


DEPENDS = ""
#DEPENDS of remix 
DEPENDS += "pkgconfig(sndfile)"
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/remix.manifest .
 
 
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
   rm -rf ${D}/usr/share/doc/remix 
   rm -rf ${D}/usr/share/doc/remix-0.2.4 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libremix"
PACKAGES += "remix-devel"

libremix_files = ""
libremix_files += "remix.manifest"
libremix_files += "/usr/lib/libremix.so.*"
libremix_files += "/usr/lib/libctxdata.so.*"
libremix_files += "/usr/lib/remix"
libremix_files += "/usr/lib/remix/libremix_ladspa*"
libremix_files += "/usr/lib/remix/libremix_noise*"

remix-devel_files = ""
remix-devel_files += "remix.manifest"
remix-devel_files += "/usr/lib/libremix.so"
remix-devel_files += "/usr/lib/libctxdata.so"
remix-devel_files += "/usr/lib/pkgconfig/*.pc"
remix-devel_files += "/usr/include/ctxdata.h"
remix-devel_files += "/usr/include/remix"
remix-devel_files += "/usr/include/remix/*.h"

FILES_lib${PN} = "${libremix_files}"
FILES_${PN}-devel = "${remix-devel_files}"

PKG_libremix= "libremix"
PKG_remix-devel= "remix-devel"

require remix-extraconf.inc
