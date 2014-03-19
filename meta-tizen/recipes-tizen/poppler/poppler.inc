DESCRIPTION = "PDF rendering library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpoppler-glib 
PROVIDES += "libpoppler-glib"
RPROVIDES_libpoppler-glib += "libpoppler-glib"
# the PROVIDES rules is ignore "poppler-glib = 0.24.1"
PROVIDES += "poppler-glib"
RPROVIDES_libpoppler-glib += "poppler-glib"

#PROVIDES by libpoppler-glib-devel 
PROVIDES += "libpoppler-glib-devel"
RPROVIDES_libpoppler-glib-devel += "libpoppler-glib-devel"
RPROVIDES_libpoppler-glib-devel += "libpoppler-glib-dev"
# the PROVIDES rules is ignore "poppler-glib-devel = 0.24.1-1"
PROVIDES += "poppler-glib-devel"
RPROVIDES_libpoppler-glib-devel += "poppler-glib-devel"
RPROVIDES_libpoppler-glib-devel += "poppler-glib-dev"

#PROVIDES by libpoppler 
PROVIDES += "libpoppler"
RPROVIDES_libpoppler += "libpoppler"
# the PROVIDES rules is ignore "poppler = 0.24.1"
PROVIDES += "poppler"
RPROVIDES_libpoppler += "poppler"

#PROVIDES by libpoppler-devel 
PROVIDES += "libpoppler-devel"
RPROVIDES_libpoppler-devel += "libpoppler-devel"
RPROVIDES_libpoppler-devel += "libpoppler-dev"
# the PROVIDES rules is ignore "poppler-devel = 0.24.1-1"
PROVIDES += "poppler-devel"
RPROVIDES_libpoppler-devel += "poppler-devel"
RPROVIDES_libpoppler-devel += "poppler-dev"

#PROVIDES by poppler 
PROVIDES += "poppler"
RPROVIDES_poppler += "poppler"

#PROVIDES by poppler-tools 
PROVIDES += "poppler-tools"
RPROVIDES_poppler-tools += "poppler-tools"
# the PROVIDES rules is ignore "poppler-tools = 0.24.1"
PROVIDES += "poppler-tools"
RPROVIDES_poppler-tools += "poppler-tools"
# the PROVIDES rules is ignore "xpdf-tools  "
PROVIDES += "xpdf-tools"
RPROVIDES_poppler-tools += "xpdf-tools"
# the PROVIDES rules is ignore "pdftohtml  "
PROVIDES += "pdftohtml"
RPROVIDES_poppler-tools += "pdftohtml"

RDEPENDS = ""
#RDEPENDS of libpoppler-glib-devel (lib${PN}-glib-devel)
RDEPENDS_lib${PN}-glib-devel += "libpoppler-dev"
RDEPENDS_lib${PN}-glib-devel += "libpoppler-glib"

#RDEPENDS of libpoppler-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libpoppler"

#RDEPENDS of poppler-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libpoppler"


DEPENDS = ""
#DEPENDS of poppler 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(cairo-pdf)"
DEPENDS += "freetype2"
DEPENDS += "pkgconfig(cairo-svg)"
DEPENDS += "pkgconfig(fontconfig)"
DEPENDS += "pkgconfig(cairo-ps)"
DEPENDS += "pkgconfig(cairo)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(cairo-ft)"
DEPENDS += "pkgconfig(lcms2)"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "libjpeg-turbo"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "curl"
DEPENDS += "libtiff-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libpoppler-cpp.manifest .
 cp ${S}/packaging/libpoppler-glib.manifest .
 cp ${S}/packaging/libpoppler.manifest .
 cp ${S}/packaging/poppler-tools.manifest .
 
 
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
         --infodir=/usr/share/info \
     --prefix=/usr --localstatedir=/opt/var --sysconfdir=/opt/etc --datarootdir=/usr/share \
     --enable-shared --disable-static \
     --enable-libjpeg --disable-libopenjpeg --enable-libtiff \
     --enable-largefile \
     --enable-zlib --disable-libcurl \
     --enable-libpng \
     --enable-cairo-output \
     --enable-splash-output \
     --enable-poppler-glib \
     --enable-introspection=auto \
     --disable-gtk-doc --disable-gtk-doc-html --disable-gtk-doc-pdf \
     --disable-poppler-qt4 --disable-poppler-qt5 \
     --disable-gtk-test \
     --enable-xpdf-headers \
     --enable-compile-warnings=yes \
     --enable-cms=lcms2 --without-x --with-font-configuration=fontconfig
 
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
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 /bin/cp -a config.h ${D}/usr/include/poppler/
 
 rm ${D}/usr/lib/*.la
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/libpoppler
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/libpoppler-glib
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/poppler-tools
 
 
 
}

PACKAGES = ""
PACKAGES += "libpoppler-glib-devel"
PACKAGES += "libpoppler"
PACKAGES += "libpoppler-glib"
PACKAGES += "libpoppler-devel"
PACKAGES += "poppler-tools"

libpoppler-glib-devel_files = ""
libpoppler-glib-devel_files += "/usr/lib/libpoppler-glib.so"
libpoppler-glib-devel_files += "/usr/lib/pkgconfig/poppler-glib.pc"
libpoppler-glib-devel_files += "/usr/include/poppler/glib/*.h"

libpoppler_files = ""
libpoppler_files += "libpoppler.manifest"
libpoppler_files += "/usr/share/license/libpoppler"
libpoppler_files += "/usr/lib/libpoppler.so.43*"

libpoppler-glib_files = ""
libpoppler-glib_files += "libpoppler-glib.manifest"
libpoppler-glib_files += "/usr/share/license/libpoppler-glib"
libpoppler-glib_files += "/usr/lib/libpoppler-glib.so.8*"

libpoppler-devel_files = ""
libpoppler-devel_files += "/usr/lib/libpoppler.so"
libpoppler-devel_files += "/usr/include/poppler/"
libpoppler-devel_files += "/usr/include/poppler/config.h"
libpoppler-devel_files += "/usr/include/poppler/[A-Z]*"
libpoppler-devel_files += "/usr/include/poppler/fofi"
libpoppler-devel_files += "/usr/include/poppler/goo"
libpoppler-devel_files += "/usr/include/poppler/splash"
libpoppler-devel_files += "/usr/include/poppler/poppler-config.h"
libpoppler-devel_files += "/usr/lib/pkgconfig/poppler-cairo.pc"
libpoppler-devel_files += "/usr/lib/pkgconfig/poppler-splash.pc"
libpoppler-devel_files += "/usr/lib/pkgconfig/poppler.pc"

poppler-tools_files = ""
poppler-tools_files += "poppler-tools.manifest"
poppler-tools_files += "/usr/share/license/poppler-tools"
poppler-tools_files += "/usr/bin/pdfinfo"
poppler-tools_files += "/usr/bin/pdfseparate"
poppler-tools_files += "/usr/bin/pdftoppm"
poppler-tools_files += "/usr/bin/pdftops"
poppler-tools_files += "/usr/bin/pdfunite"

FILES_lib${PN}-glib-devel = "${libpoppler-glib-devel_files}"
FILES_lib${PN} = "${libpoppler_files}"
FILES_lib${PN}-glib = "${libpoppler-glib_files}"
FILES_lib${PN}-devel = "${libpoppler-devel_files}"
FILES_${PN}-tools = "${poppler-tools_files}"

PKG_libpoppler-glib-devel= "libpoppler-glib-devel"
PKG_libpoppler= "libpoppler"
PKG_libpoppler-glib= "libpoppler-glib"
PKG_libpoppler-devel= "libpoppler-devel"
PKG_poppler-tools= "poppler-tools"

require poppler-extraconf.inc
