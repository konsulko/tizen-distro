DESCRIPTION = "Python bindings for GObject"
HOMEPAGE = "http://ftp.gnome.org/pub/GNOME/sources/pygobject/"
SECTION = "Development/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-gobject-cairo 
PROVIDES += "python-gobject-cairo"
RPROVIDES_python-gobject-cairo += "python-gobject-cairo"

#PROVIDES by python-gobject 
PROVIDES += "python-gobject"
RPROVIDES_python-gobject += "python-gobject"
# the PROVIDES rules is ignore "pygobject3  "
PROVIDES += "pygobject3"
RPROVIDES_python-gobject += "pygobject3"

#PROVIDES by python-gobject-pygtkcompat 
PROVIDES += "python-gobject-pygtkcompat"
RPROVIDES_python-gobject-pygtkcompat += "python-gobject-pygtkcompat"

#PROVIDES by python-gobject-devel 
PROVIDES += "python-gobject-devel"
RPROVIDES_python-gobject-devel += "python-gobject-devel"
RPROVIDES_python-gobject-devel += "python-gobject-dev"

#PROVIDES by libpyglib-gi-python 
PROVIDES += "libpyglib-gi-python"
RPROVIDES_libpyglib-gi-python += "libpyglib-gi-python"

RDEPENDS = ""
#RDEPENDS of python-gobject-cairo (${PN}-cairo)
RDEPENDS_${PN}-cairo += "python-gobject"

#RDEPENDS of python-gobject-pygtkcompat (${PN}-pygtkcompat)
RDEPENDS_${PN}-pygtkcompat += "python-gobject"

#RDEPENDS of python-gobject-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "python-gobject"
RDEPENDS_${PN}-devel += "libpyglib-gi-python"


DEPENDS = ""
#DEPENDS of python-gobject 
DEPENDS += "glib"
DEPENDS += "gobject-introspection"
DEPENDS += "pkgconfig(cairo-gobject)"
inherit pythonnative
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "python-cairo"
DEPENDS += "libffi"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n pygobject-3.8.0
 cp ${S}/packaging/python-gobject.manifest .
 
 
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
 rm examples/Makefile*
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r $RPM_BUILD_ROOT | 
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
PACKAGES += "python-gobject-cairo"
PACKAGES += "python-gobject"
PACKAGES += "python-gobject-pygtkcompat"
PACKAGES += "python-gobject-devel"
PACKAGES += "libpyglib-gi-python"

python-gobject-cairo_files = ""
python-gobject-cairo_files += "python-gobject.manifest"
python-gobject-cairo_files += "/usr/lib/python2.7/site-packages/gi/_gi_cairo.so"

python-gobject_files = ""
python-gobject_files += "python-gobject.manifest"
python-gobject_files += "/usr/lib/python2.7/site-packages/gi/"
python-gobject_files += "/usr/lib/python2.7/site-packages/pygobject-*"

python-gobject-pygtkcompat_files = ""
python-gobject-pygtkcompat_files += "python-gobject.manifest"
python-gobject-pygtkcompat_files += "/usr/lib/python2.7/site-packages/pygtkcompat"

python-gobject-devel_files = ""
python-gobject-devel_files += "python-gobject.manifest"
python-gobject-devel_files += "/usr/include/pygobject-3.0/"
python-gobject-devel_files += "/usr/lib/*.so"
python-gobject-devel_files += "/usr/lib/pkgconfig/pygobject-3.0.pc"

libpyglib-gi-python_files = ""
libpyglib-gi-python_files += "python-gobject.manifest"
libpyglib-gi-python_files += "/usr/lib/libpyglib-gi-2.0-python2.so.0*"

FILES_${PN}-cairo = "${python-gobject-cairo_files}"
FILES_${PN} = "${python-gobject_files}"
FILES_${PN}-pygtkcompat = "${python-gobject-pygtkcompat_files}"
FILES_${PN}-devel = "${python-gobject-devel_files}"
FILES_libpyglib-gi-python = "${libpyglib-gi-python_files}"

PKG_python-gobject-cairo= "python-gobject-cairo"
PKG_python-gobject= "python-gobject"
PKG_python-gobject-pygtkcompat= "python-gobject-pygtkcompat"
PKG_python-gobject-devel= "python-gobject-devel"
PKG_libpyglib-gi-python= "libpyglib-gi-python"

require python-gobject-extraconf.inc
