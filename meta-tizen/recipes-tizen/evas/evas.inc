DESCRIPTION = "Multi-platform Canvas Library"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics & UI Framework/Libraries"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by evas 
PROVIDES += "evas"
RPROVIDES_evas += "evas"

#PROVIDES by evas-examples 
PROVIDES += "evas-examples"
RPROVIDES_evas-examples += "evas-examples"

#PROVIDES by evas-devel 
PROVIDES += "evas-devel"
RPROVIDES_evas-devel += "evas-devel"
RPROVIDES_evas-devel += "evas-dev"

RDEPENDS = ""
#RDEPENDS of evas-examples (${PN}-examples)
RDEPENDS_${PN}-examples += "evas-dev"

#RDEPENDS of evas-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "evas"


DEPENDS = ""
#DEPENDS of evas 
DEPENDS += "pkgconfig(xkbcommon)"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(harfbuzz)"
DEPENDS += "pkgconfig(fontconfig)"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "libjpeg-devel"
DEPENDS += "pkgconfig(eet)"
DEPENDS += "pkgconfig(wayland-cursor)"
DEPENDS += "pkgconfig(freetype2)"
DEPENDS += "pkgconfig(glesv2)"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "pkgconfig(pixman-1)"
DEPENDS += "pkgconfig(wayland-egl)"
DEPENDS += "pkgconfig(ice)"
DEPENDS += "pkgconfig(fribidi)"
DEPENDS += "pkgconfig(egl)"
DEPENDS += "pkgconfig(libtiff-4)"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "giflib-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/evas.manifest .
 
 
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
         --infodir=/usr/share/info --enable-pthreads \
            --without-x             \
            --disable-software-xcb  \
            --disable-software-xlib \
            --enable-gl-flavor-gles \
             --enable-gles-variety-sgx \
             --enable-wayland-egl \
 
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
PACKAGES += "evas"
PACKAGES += "evas-devel"
PACKAGES += "evas-examples"

evas_files = ""
evas_files += "evas.manifest"
evas_files += "/usr/bin/evas_cserve*"
evas_files += "/usr/lib/evas/modules/*/*/*/module.so"
evas_files += "/usr/lib/libevas.so.*"
evas_files += "/usr/lib/evas/cserve2"
evas_files += "/usr/libexec/*"
evas_files += "/usr/share/evas/checkme"

evas-devel_files = ""
evas-devel_files += "evas.manifest"
evas-devel_files += "/usr/include/evas-1/*.h"
evas-devel_files += "/usr/lib/*.so"
evas-devel_files += "/usr/lib/pkgconfig/*.pc"

evas-examples_files = ""
evas-examples_files += "evas.manifest"
evas-examples_files += "/usr/share/evas/examples/*"

FILES_${PN} = "${evas_files}"
FILES_${PN}-devel = "${evas-devel_files}"
FILES_${PN}-examples = "${evas-examples_files}"

PKG_evas= "evas"
PKG_evas-devel= "evas-devel"
PKG_evas-examples= "evas-examples"

require evas-extraconf.inc
