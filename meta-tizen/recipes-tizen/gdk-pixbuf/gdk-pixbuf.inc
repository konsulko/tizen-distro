DESCRIPTION = "An image loading library"
HOMEPAGE = "http://developer.gnome.org/"
SECTION = "Multimedia/Image Library"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gdk-pixbuf 
PROVIDES += "gdk-pixbuf"
RPROVIDES_gdk-pixbuf += "gdk-pixbuf"

#PROVIDES by gdk-pixbuf-query-loaders 
PROVIDES += "gdk-pixbuf-query-loaders"
RPROVIDES_gdk-pixbuf-query-loaders += "gdk-pixbuf-query-loaders"

#PROVIDES by gdk-pixbuf-locale  
PROVIDES += "gdk-pixbuf-locale "
RPROVIDES_gdk-pixbuf-locale  += "gdk-pixbuf-locale "
# the PROVIDES rules is ignore "gdk-pixbuf-lang-all = 2.28.1"
PROVIDES += "gdk-pixbuf-lang-all"
RPROVIDES_gdk-pixbuf-locale  += "gdk-pixbuf-lang-all"

#PROVIDES by gdk-pixbuf-devel 
PROVIDES += "gdk-pixbuf-devel"
RPROVIDES_gdk-pixbuf-devel += "gdk-pixbuf-devel"
RPROVIDES_gdk-pixbuf-devel += "gdk-pixbuf-dev"

#PROVIDES by typelib-GdkPixbuf 
PROVIDES += "typelib-GdkPixbuf"
RPROVIDES_typelib-GdkPixbuf += "typelib-GdkPixbuf"

RDEPENDS = ""
#RDEPENDS of gdk-pixbuf-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "gdk-pixbuf"

#RDEPENDS of gdk-pixbuf (${PN})
RDEPENDS_${PN} += "gdk-pixbuf-query-loaders"

#RDEPENDS of gdk-pixbuf-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gdk-pixbuf"


DEPENDS = ""
#DEPENDS of gdk-pixbuf 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libjpeg-devel"
DEPENDS += "libjasper-devel"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libtiff-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gdk-pixbuf.manifest .
 
 
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
 
 export CFLAGS=`echo $RPM_OPT_FLAGS |sed -e 's/atom/i686/g'`
 
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
         --disable-static \
         --with-libjasper \
 
 oe_runmake -j16
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gdk-pixbuf
 touch ${D}/usr/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache
 # Install rpm macros
 mkdir -p ${D}/etc/rpm
 cp ${S}/packaging/macros.gdk-pixbuf ${D}/etc/rpm
 
 ###########################################################################
 # Note: when updating scriptlets, don't forget to also update baselibs.conf
 ###########################################################################
 
 # Convenient define for the scriplets
 
 
 
}

PACKAGES = ""
PACKAGES += "gdk-pixbuf"
PACKAGES += "gdk-pixbuf-locale"
PACKAGES += "gdk-pixbuf-devel"
PACKAGES += "gdk-pixbuf-query-loaders"

gdk-pixbuf_files = ""
gdk-pixbuf_files += "gdk-pixbuf.manifest"
gdk-pixbuf_files += "/usr/lib/libgdk_pixbuf-2.0.so.0*"
gdk-pixbuf_files += "/usr/lib/gdk-pixbuf-2.0"
gdk-pixbuf_files += "/usr/lib/gdk-pixbuf-2.0/2.10.0"
gdk-pixbuf_files += "/usr/lib/gdk-pixbuf-2.0/2.10.0/loaders"
gdk-pixbuf_files += "/usr/lib/gdk-pixbuf-2.0/2.10.0/loaders/*.so"

gdk-pixbuf-locale_files = ""

gdk-pixbuf-devel_files = ""
gdk-pixbuf-devel_files += "gdk-pixbuf.manifest"
gdk-pixbuf-devel_files += "/usr/bin/gdk-pixbuf-csource"
gdk-pixbuf-devel_files += "/usr/bin/gdk-pixbuf-pixdata"
gdk-pixbuf-devel_files += "/usr/share/man/man1/gdk-pixbuf-csource.1*"
gdk-pixbuf-devel_files += "/usr/include/gdk-pixbuf-2.0"
gdk-pixbuf-devel_files += "/usr/lib/pkgconfig/*.pc"
gdk-pixbuf-devel_files += "/usr/lib/*.so"
gdk-pixbuf-devel_files += "/usr/share/gtk-doc/html/gdk-pixbuf"
gdk-pixbuf-devel_files += "/etc/rpm/macros.gdk-pixbuf"

gdk-pixbuf-query-loaders_files = ""
gdk-pixbuf-query-loaders_files += "gdk-pixbuf.manifest"
gdk-pixbuf-query-loaders_files += "/usr/bin/gdk-pixbuf-query-loaders*"
gdk-pixbuf-query-loaders_files += "/usr/share/man/man1/gdk-pixbuf-query-loaders*.1*"

FILES_${PN} = "${gdk-pixbuf_files}"
FILES_${PN}-locale = "${gdk-pixbuf-locale_files}"
FILES_${PN}-devel = "${gdk-pixbuf-devel_files}"
FILES_${PN}-query-loaders = "${gdk-pixbuf-query-loaders_files}"

PKG_gdk-pixbuf= "gdk-pixbuf"
PKG_gdk-pixbuf-locale= "gdk-pixbuf-locale"
PKG_gdk-pixbuf-devel= "gdk-pixbuf-devel"
PKG_gdk-pixbuf-query-loaders= "gdk-pixbuf-query-loaders"

require gdk-pixbuf-extraconf.inc
