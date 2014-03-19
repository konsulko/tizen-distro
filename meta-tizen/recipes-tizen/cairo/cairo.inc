DESCRIPTION = "Vector Graphics Library with Cross-Device Output Support"
HOMEPAGE = "http://cairographics.org/"
SECTION = "Graphics/Libraries"
LICENSE = "LGPL-2.1+ or MPL-1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcairo 
PROVIDES += "libcairo"
RPROVIDES_libcairo += "libcairo"
# the PROVIDES rules is ignore "cairo = 1.12.16"
PROVIDES += "cairo"
RPROVIDES_libcairo += "cairo"

#PROVIDES by cairo 
PROVIDES += "cairo"
RPROVIDES_cairo += "cairo"

#PROVIDES by libcairo-gobject 
PROVIDES += "libcairo-gobject"
RPROVIDES_libcairo-gobject += "libcairo-gobject"

#PROVIDES by cairo-devel 
PROVIDES += "cairo-devel"
RPROVIDES_cairo-devel += "cairo-devel"
RPROVIDES_cairo-devel += "cairo-dev"

#PROVIDES by cairo-tools 
PROVIDES += "cairo-tools"
RPROVIDES_cairo-tools += "cairo-tools"

#PROVIDES by libcairo-script-interpreter 
PROVIDES += "libcairo-script-interpreter"
RPROVIDES_libcairo-script-interpreter += "libcairo-script-interpreter"

RDEPENDS = ""
#RDEPENDS of cairo-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcairo-script-interpreter"
RDEPENDS_${PN}-devel += "libcairo-gobject"
RDEPENDS_${PN}-devel += "libcairo"

#RDEPENDS of cairo-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libcairo"


DEPENDS = ""
#DEPENDS of cairo 
DEPENDS += "pkgconfig(glesv2)"
DEPENDS += "which"
DEPENDS += "pkgconfig(fontconfig)"
DEPENDS += "pkgconfig(freetype2)"
DEPENDS += "pkgconfig-native"
DEPENDS += "xz"
DEPENDS += "pkgconfig(wayland-egl)"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "pkgconfig(pixman-1)"
DEPENDS += "pkgconfig(gobject-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/cairo.manifest .
 
 
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
 
 # Disable Atom optimizations in order to make binaries executable in buildroot
 export RPM_OPT_FLAGS=`echo $RPM_OPT_FLAGS | sed s'/atom/i686/g'`
 export CFLAGS=`echo $CFLAGS | sed s'/atom/i686/g'`
 export CXXFLAGS=`echo $CXXFLAGS | sed s'/atom/i686/g'`
 
 # Needed by patch0
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
         --infodir=/usr/share/info \
     --with-pic \
     --enable-fc \
     --enable-ft \
     --enable-egl \
     --enable-glesv2=yes \
     --enable-ps \
     --enable-pdf \
     --enable-script \
     --enable-svg \
     --enable-tee \
    --disable-xlib \
    --disable-xcb  \
     --disable-gtk-doc \
     --disable-static
 make -j16 V=1
 
 
 
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
PACKAGES += "cairo-devel"
PACKAGES += "libcairo-script-interpreter"
PACKAGES += "cairo-tools"
PACKAGES += "libcairo-gobject"
PACKAGES += "libcairo"

cairo-devel_files = ""
cairo-devel_files += "cairo.manifest"
cairo-devel_files += "PORTING_GUIDE"
cairo-devel_files += "/usr/include/cairo/"
cairo-devel_files += "/usr/share/gtk-doc/html/cairo"
cairo-devel_files += "/usr/lib/*.so"
cairo-devel_files += "/usr/lib/pkgconfig/*.pc"

libcairo-script-interpreter_files = ""
libcairo-script-interpreter_files += "cairo.manifest"
libcairo-script-interpreter_files += "/usr/lib/libcairo-script-interpreter.so.*"

cairo-tools_files = ""
cairo-tools_files += "cairo.manifest"
cairo-tools_files += "/usr/bin/cairo-sphinx"
cairo-tools_files += "/usr/bin/cairo-trace"
cairo-tools_files += "/usr/lib/cairo"
cairo-tools_files += "/usr/lib/cairo/cairo-fdr.so"
cairo-tools_files += "/usr/lib/cairo/cairo-sphinx.so"
cairo-tools_files += "/usr/lib/cairo/libcairo-trace.so"

libcairo-gobject_files = ""
libcairo-gobject_files += "cairo.manifest"
libcairo-gobject_files += "/usr/lib/libcairo-gobject.so.2*"

libcairo_files = ""
libcairo_files += "cairo.manifest"
libcairo_files += "/usr/lib/libcairo.so.*"

FILES_${PN}-devel = "${cairo-devel_files}"
FILES_lib${PN}-script-interpreter = "${libcairo-script-interpreter_files}"
FILES_${PN}-tools = "${cairo-tools_files}"
FILES_lib${PN}-gobject = "${libcairo-gobject_files}"
FILES_lib${PN} = "${libcairo_files}"

PKG_cairo-devel= "cairo-devel"
PKG_libcairo-script-interpreter= "libcairo-script-interpreter"
PKG_cairo-tools= "cairo-tools"
PKG_libcairo-gobject= "libcairo-gobject"
PKG_libcairo= "libcairo"

require cairo-extraconf.inc
