DESCRIPTION = "GObject Introspection Tools"
HOMEPAGE = "http://live.gnome.org/GObjectIntrospection"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.1+ and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gobject-introspection 
PROVIDES += "gobject-introspection"
RPROVIDES_gobject-introspection += "gobject-introspection"

#PROVIDES by gobject-introspection-devel 
PROVIDES += "gobject-introspection-devel"
RPROVIDES_gobject-introspection-devel += "gobject-introspection-devel"
RPROVIDES_gobject-introspection-devel += "gobject-introspection-dev"

#PROVIDES by girepository 
PROVIDES += "girepository"
RPROVIDES_girepository += "girepository"

#PROVIDES by libgirepository 
PROVIDES += "libgirepository"
RPROVIDES_libgirepository += "libgirepository"

#PROVIDES by gobject-introspection-docs  
PROVIDES += "gobject-introspection-docs "
RPROVIDES_gobject-introspection-docs  += "gobject-introspection-docs "

RDEPENDS = ""
#RDEPENDS of gobject-introspection (${PN})
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "libgirepository"

#RDEPENDS of gobject-introspection-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gobject-introspection"
RDEPENDS_${PN}-devel += "libffi-dev"

#RDEPENDS of girepository (girepository)
RDEPENDS_girepository += "libgirepository"

#RDEPENDS of libgirepository (libgirepository)
RDEPENDS_libgirepository += "girepository"


DEPENDS = ""
#DEPENDS of gobject-introspection 
DEPENDS += "flex"
DEPENDS += "fdupes-native"
DEPENDS += "pkgconfig(cairo-gobject)"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "python-devel"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "libtool-cross"
DEPENDS += "python-xml"
DEPENDS += "bison-native"
DEPENDS += "libffi-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gobject-introspection.manifest .
 
 
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
 
 [ -x ./autogen.sh ] && NOCONFIGURE=1 ./autogen.sh
 #autoreconf -fi
 
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
         --disable-gtk-doc 
 oe_runmake -j16 V=1
 
 
 
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
 install -D ${S}/packaging/gi-find-deps.sh ${D}/usr/share/spec2yocto/macro/gi-find-deps.sh
 install -D ${S}/packaging/gobjectintrospection.attr -m 0644 ${D}/usr/share/spec2yocto/macro/fileattrs/gobjectintrospection.attr
 # comparing, if we provide all the symbols expected.
 ls ${D}/usr/lib/girepository-1.0/*.typelib | sh ${S}/packaging/gi-find-deps.sh -P > gobject-introspection-typelib.installed
 diff -s ${S}/packaging/gobject-introspection-typelib.template gobject-introspection-typelib.installed
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D} | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
 
}

PACKAGES = ""
PACKAGES += "gobject-introspection"
PACKAGES += "gobject-introspection-devel"
PACKAGES += "girepository"
PACKAGES += "libgirepository"
PACKAGES += "gobject-introspection-docs"

gobject-introspection_files = ""
gobject-introspection_files += "gobject-introspection.manifest"
gobject-introspection_files += "LGPL-2.1+ COPYING COPYING.GPL"
gobject-introspection_files += "/usr/bin/g-ir-annotation-tool"
gobject-introspection_files += "/usr/bin/g-ir-compiler"
gobject-introspection_files += "/usr/bin/g-ir-dep-tool"
gobject-introspection_files += "/usr/bin/g-ir-generate"
gobject-introspection_files += "/usr/bin/g-ir-scanner"
gobject-introspection_files += "/usr/share/aclocal/introspection.m4"
gobject-introspection_files += "/usr/share/gir-1.0/*.gir"
gobject-introspection_files += "/usr/lib/gobject-introspection"
gobject-introspection_files += "/usr/lib/gobject-introspection/giscanner/"
gobject-introspection_files += "/usr/share/gobject-introspection-1.0"
gobject-introspection_files += "/usr/share/gobject-introspection-1.0/Makefile.introspection"
gobject-introspection_files += "/usr/share/gobject-introspection-1.0/tests/"
gobject-introspection_files += "/usr/share/gobject-introspection-1.0/gdump.c"
gobject-introspection_files += "/usr/share/spec2yocto/macro/gi-find-deps.sh"
gobject-introspection_files += "/usr/share/spec2yocto/macro/fileattrs/gobjectintrospection.attr"

gobject-introspection-devel_files = ""
gobject-introspection-devel_files += "gobject-introspection.manifest"
gobject-introspection-devel_files += "/usr/include/gobject-introspection-1.0/"
gobject-introspection-devel_files += "/usr/lib/libgirepository-1.0.so"
gobject-introspection-devel_files += "/usr/lib/pkgconfig/gobject-introspection-1.0.pc"
gobject-introspection-devel_files += "/usr/lib/pkgconfig/gobject-introspection-no-export-1.0.pc"

girepository_files = ""
girepository_files += "gobject-introspection.manifest"
girepository_files += "/usr/lib/girepository-1.0/*.typelib"

libgirepository_files = ""
libgirepository_files += "gobject-introspection.manifest"
libgirepository_files += "COPYING.LGPL"
libgirepository_files += "/usr/share/gir-1.0"
libgirepository_files += "/usr/lib/libgirepository-1.0.so.*"
libgirepository_files += "/usr/lib/girepository-1.0"

gobject-introspection-docs_files = ""
gobject-introspection-docs_files += "/usr/share/info"
gobject-introspection-docs_files += "/usr/share/man"

FILES_${PN} = "${gobject-introspection_files}"
FILES_${PN}-devel = "${gobject-introspection-devel_files}"
FILES_girepository = "${girepository_files}"
FILES_libgirepository = "${libgirepository_files}"
FILES_${PN}-docs = "${gobject-introspection-docs_files}"

PKG_gobject-introspection= "gobject-introspection"
PKG_gobject-introspection-devel= "gobject-introspection-devel"
PKG_girepository= "girepository"
PKG_libgirepository= "libgirepository"
PKG_gobject-introspection-docs= "gobject-introspection-docs"

require gobject-introspection-extraconf.inc
