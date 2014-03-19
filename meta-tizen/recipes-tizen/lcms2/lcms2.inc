DESCRIPTION = "Little CMS Engine - A color managment library and tools"
HOMEPAGE = "http://www.littlecms.com/"
SECTION = "Graphics/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lcms2-docs  
PROVIDES += "lcms2-docs "
RPROVIDES_lcms2-docs  += "lcms2-docs "

#PROVIDES by libcms2 
PROVIDES += "libcms2"
RPROVIDES_libcms2 += "libcms2"

#PROVIDES by lcms2 
PROVIDES += "lcms2"
RPROVIDES_lcms2 += "lcms2"

#PROVIDES by liblcms2-devel 
PROVIDES += "liblcms2-devel"
RPROVIDES_liblcms2-devel += "liblcms2-devel"
RPROVIDES_liblcms2-devel += "liblcms2-dev"

RDEPENDS = ""
#RDEPENDS of liblcms2-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libcms2"


DEPENDS = ""
#DEPENDS of lcms2 
DEPENDS += "zlib-devel"
DEPENDS += "libtiff-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "libjpeg-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/lcms2.manifest .
 
 chmod a-x doc/* COPYING AUTHORS
 
 
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
         --infodir=/usr/share/info --disable-static
 make 
 
 
 
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
PACKAGES += "lcms2-docs"
PACKAGES += "libcms2"
PACKAGES += "lcms2"
PACKAGES += "liblcms2-devel"

lcms2-docs_files = ""
lcms2-docs_files += "/usr/share/info"
lcms2-docs_files += "/usr/share/man"

libcms2_files = ""
libcms2_files += "lcms2.manifest"
libcms2_files += "/usr/lib/liblcms2.so.2*"

lcms2_files = ""
lcms2_files += "lcms2.manifest"
lcms2_files += "/usr/bin/*"

liblcms2-devel_files = ""
liblcms2-devel_files += "lcms2.manifest"
liblcms2-devel_files += "/usr/include/*.h"
liblcms2-devel_files += "/usr/lib/*.so"
liblcms2-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN}-docs = "${lcms2-docs_files}"
FILES_libcms2 = "${libcms2_files}"
FILES_${PN} = "${lcms2_files}"
FILES_lib${PN}-devel = "${liblcms2-devel_files}"

PKG_lcms2-docs= "lcms2-docs"
PKG_libcms2= "libcms2"
PKG_lcms2= "lcms2"
PKG_liblcms2-devel= "liblcms2-devel"

require lcms2-extraconf.inc
