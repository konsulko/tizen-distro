DESCRIPTION = "Library for Layout and Rendering of Text"
HOMEPAGE = "http://www.pango.org/"
SECTION = "System/i18n"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pango-tools 
PROVIDES += "pango-tools"
RPROVIDES_pango-tools += "pango-tools"

#PROVIDES by pango-docs  
PROVIDES += "pango-docs "
RPROVIDES_pango-docs  += "pango-docs "

#PROVIDES by typelib-Pango 
PROVIDES += "typelib-Pango"
RPROVIDES_typelib-Pango += "typelib-Pango"

#PROVIDES by pango-devel 
PROVIDES += "pango-devel"
RPROVIDES_pango-devel += "pango-devel"
RPROVIDES_pango-devel += "pango-dev"

#PROVIDES by pango 
PROVIDES += "pango"
RPROVIDES_pango += "pango"

#PROVIDES by libpango 
PROVIDES += "libpango"
RPROVIDES_libpango += "libpango"
# the PROVIDES rules is ignore "pango = 1.34.1"
PROVIDES += "pango"
RPROVIDES_libpango += "pango"

#PROVIDES by pango-module-thai-lang 
PROVIDES += "pango-module-thai-lang"
RPROVIDES_pango-module-thai-lang += "pango-module-thai-lang"
# the PROVIDES rules is ignore "locale(pango:th_TH)  "
PROVIDES += "locale(pango:th_TH)"
RPROVIDES_pango-module-thai-lang += "locale(pango:th_TH)"

RDEPENDS = ""
#RDEPENDS of pango-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpango"

#RDEPENDS of pango-module-thai-lang (${PN}-module-thai-lang)
RDEPENDS_${PN}-module-thai-lang += "pango-tools"

#RDEPENDS of libpango (lib${PN})
RDEPENDS_lib${PN} += "pango-tools"


DEPENDS = ""
#DEPENDS of pango 
DEPENDS += "gcc-cross"
DEPENDS += "freetype2"
DEPENDS += "pkgconfig(fontconfig)"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "pkgconfig-native"
DEPENDS += "harfbuzz"
DEPENDS += "pkgconfig(libthai)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pango.manifest .
 
 
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
 
 NOCONFIGURE=1 ./autogen.sh
 
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
         --infodir=/usr/share/info --disable-static --with-pic
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
 mkdir -p ${D}/etc/pango/
 touch ${D}/usr/lib/pango/1.8.0/pango.modules
 # Install rpm macros
 mkdir -p ${D}/etc/rpm
 cp ${S}/packaging/macros.pango ${D}/etc/rpm
 # Convenient %define for the scriplets
 
 
}

PACKAGES = ""
PACKAGES += "pango-devel"
PACKAGES += "pango-module-thai-lang"
PACKAGES += "libpango"
PACKAGES += "pango-tools"
PACKAGES += "pango-docs"

pango-devel_files = ""
pango-devel_files += "pango.manifest"
pango-devel_files += "/usr/lib/lib*.so"
pango-devel_files += "/usr/lib/pkgconfig/*.pc"
pango-devel_files += "/usr/include/pango-1.0/"
pango-devel_files += "/etc/rpm/macros.pango"

pango-module-thai-lang_files = ""
pango-module-thai-lang_files += "pango.manifest"
pango-module-thai-lang_files += "/usr/lib/pango/1.8.0/modules/pango-thai-lang.so"

libpango_files = ""
libpango_files += "pango.manifest"
libpango_files += "/usr/lib/pango"
libpango_files += "/usr/lib/pango/1.8.0"
libpango_files += "/usr/lib/pango/1.8.0/modules"
libpango_files += "/usr/lib/pango/1.8.0/modules/pango-arabic-lang.so"
libpango_files += "/usr/lib/pango/1.8.0/modules/pango-basic-fc.so"
libpango_files += "/usr/lib/pango/1.8.0/modules/pango-indic-lang.so"
libpango_files += "/usr/lib/lib*.so.*"
libpango_files += "/etc/pango"

pango-tools_files = ""
pango-tools_files += "pango.manifest"
pango-tools_files += "/usr/bin/pango-querymodules*"
pango-tools_files += "/usr/bin/pango-view"

pango-docs_files = ""
pango-docs_files += "/usr/share/info"
pango-docs_files += "/usr/share/man"
pango-docs_files += ""

FILES_${PN}-devel = "${pango-devel_files}"
FILES_${PN}-module-thai-lang = "${pango-module-thai-lang_files}"
FILES_lib${PN} = "${libpango_files}"
FILES_${PN}-tools = "${pango-tools_files}"
FILES_${PN}-docs = "${pango-docs_files}"

PKG_pango-devel= "pango-devel"
PKG_pango-module-thai-lang= "pango-module-thai-lang"
PKG_libpango= "libpango"
PKG_pango-tools= "pango-tools"
PKG_pango-docs= "pango-docs"

require pango-extraconf.inc
