DESCRIPTION = "Python bindings for GObject"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Languages"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pygobject 
PROVIDES += "pygobject"
RPROVIDES_pygobject += "pygobject"

#PROVIDES by pygobject-doc 
PROVIDES += "pygobject-doc"
RPROVIDES_pygobject-doc += "pygobject-doc"

#PROVIDES by pygobject-codegen 
PROVIDES += "pygobject-codegen"
RPROVIDES_pygobject-codegen += "pygobject-codegen"

#PROVIDES by pygobject-devel 
PROVIDES += "pygobject-devel"
RPROVIDES_pygobject-devel += "pygobject-devel"
RPROVIDES_pygobject-devel += "pygobject-dev"

RDEPENDS = ""
#RDEPENDS of pygobject-devel (pygobject-devel)
RDEPENDS_pygobject-devel += "pygobject"
RDEPENDS_pygobject-devel += "pygobject-codegen"
RDEPENDS_pygobject-devel += "glib2-dev"
RDEPENDS_pygobject-devel += "pkgconfig"
RDEPENDS_pygobject-devel += "pygobject-doc"


DEPENDS = ""
#DEPENDS of pygobject 
DEPENDS += "glib"
DEPENDS += "python-devel"
DEPENDS += "libtool-cross"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pygobject.manifest .
 
 
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
         --infodir=/usr/share/info --enable-thread
 export tagname=CC
 make LIBTOOL=/usr/bin/libtool
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 export tagname=CC
 make LIBTOOL=/usr/bin/libtool DESTDIR=$RPM_BUILD_ROOT install
 find $RPM_BUILD_ROOT -name '*.la' -or -name '*.a' | xargs rm -f
 
 rm examples/Makefile*
 
 
}

PACKAGES = ""
PACKAGES += "pygobject-codegen"
PACKAGES += "pygobject"
PACKAGES += "pygobject-doc"
PACKAGES += "pygobject-devel"

pygobject-codegen_files = ""
pygobject-codegen_files += "pygobject.manifest"
pygobject-codegen_files += "/usr/bin/pygobject-codegen-2.0"
pygobject-codegen_files += "/usr/share/pygobject/2.0"
pygobject-codegen_files += "/usr/share/pygobject/2.0/codegen"

pygobject_files = ""
pygobject_files += "pygobject.manifest"
pygobject_files += "AUTHORS NEWS README"
pygobject_files += "/usr/lib/libpyglib-2.0-python.so*"
pygobject_files += "/usr/lib/python2.7/site-packages/gtk-2.0"
pygobject_files += "/usr/lib/python2.7/site-packages/gtk-2.0/dsextras.*"
pygobject_files += "/usr/lib/python2.7/site-packages/pygtk.*"
pygobject_files += "/usr/lib/python2.7/site-packages/gtk-2.0/gio"
pygobject_files += "/usr/lib/python2.7/site-packages/gtk-2.0/glib"
pygobject_files += "/usr/lib/python2.7/site-packages/gtk-2.0/gobject"

pygobject-doc_files = ""
pygobject-doc_files += "pygobject.manifest"
pygobject-doc_files += "examples"
pygobject-doc_files += "/usr/share/gtk-doc/html/pygobject"
pygobject-doc_files += "/usr/share/pygobject/xsl"

pygobject-devel_files = ""
pygobject-devel_files += "pygobject.manifest"
pygobject-devel_files += "/usr/share/pygobject"
pygobject-devel_files += "/usr/include/pygtk-2.0"
pygobject-devel_files += "/usr/share/pygobject/2.0/defs"
pygobject-devel_files += "/usr/include/pygtk-2.0/pyglib.h"
pygobject-devel_files += "/usr/include/pygtk-2.0/pygobject.h"
pygobject-devel_files += "/usr/lib/pkgconfig/pygobject-2.0.pc"

FILES_${PN}-codegen = "${pygobject-codegen_files}"
FILES_${PN} = "${pygobject_files}"
FILES_${PN}-doc = "${pygobject-doc_files}"
FILES_${PN}-devel = "${pygobject-devel_files}"

PKG_pygobject-codegen= "pygobject-codegen"
PKG_pygobject= "pygobject"
PKG_pygobject-doc= "pygobject-doc"
PKG_pygobject-devel= "pygobject-devel"

require pygobject2-extraconf.inc
