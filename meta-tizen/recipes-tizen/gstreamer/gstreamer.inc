DESCRIPTION = "Streaming-Media Framework Runtime"
HOMEPAGE = "http://gstreamer.freedesktop.org/"
SECTION = "Multimedia/Framework"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gstreamer-utils 
PROVIDES += "gstreamer-utils"
RPROVIDES_gstreamer-utils += "gstreamer-utils"
# the PROVIDES rules is ignore "gstreamer:/usr/bin/gst-launch-1.0 = 1.2.0"
PROVIDES += "gstreamer:/usr/bin/gst-launch-1.0"
RPROVIDES_gstreamer-utils += "gstreamer:/usr/bin/gst-launch-1.0"
# the PROVIDES rules is ignore "gstreamer-utils_versioned = 1.2.0"
PROVIDES += "gstreamer-utils_versioned"
RPROVIDES_gstreamer-utils += "gstreamer-utils_versioned"

#PROVIDES by gstreamer-locale 
PROVIDES += "gstreamer-locale"
RPROVIDES_gstreamer-locale += "gstreamer-locale"
# the PROVIDES rules is ignore "gstreamer-lang-all = 1.2.0"
PROVIDES += "gstreamer-lang-all"
RPROVIDES_gstreamer-locale += "gstreamer-lang-all"

#PROVIDES by gstreamer 
PROVIDES += "gstreamer"
RPROVIDES_gstreamer += "gstreamer"

#PROVIDES by gstreamer-devel 
PROVIDES += "gstreamer-devel"
RPROVIDES_gstreamer-devel += "gstreamer-devel"
RPROVIDES_gstreamer-devel += "gstreamer-dev"

#PROVIDES by typelib-Gst 
PROVIDES += "typelib-Gst"
RPROVIDES_typelib-Gst += "typelib-Gst"

#PROVIDES by libgstreamer 
PROVIDES += "libgstreamer"
RPROVIDES_libgstreamer += "libgstreamer"

RDEPENDS = ""
#RDEPENDS of gstreamer-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "gstreamer"

#RDEPENDS of gstreamer (${PN})
RDEPENDS_${PN} += "libgstreamer"

#RDEPENDS of gstreamer-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gstreamer-utils"
RDEPENDS_${PN}-devel += "gstreamer"
RDEPENDS_${PN}-devel += "libgstreamer"

#RDEPENDS of libgstreamer (lib${PN})
RDEPENDS_lib${PN} += "gstreamer"


DEPENDS = ""
#DEPENDS of gstreamer 
DEPENDS += "glib"
DEPENDS += "flex"
DEPENDS += "libxml2-devel"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "bison-native"
DEPENDS += "libtool-cross"
DEPENDS += "fdupes-native"
DEPENDS += "check"
DEPENDS += "gst-common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gstreamer-1.2.0
 #extracte source 100 
 pushd ${S}
 unp ${S}/packaging/common.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -T -D -a 100
 cp ${S}/packaging/gstreamer.manifest .
 
 
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
 
 # FIXME: GTKDOC_CFLAGS, GST_OBJ_CFLAGS:
 # Silently ignored compilation of uninstalled gtk-doc scanners without RPM_OPT_FLAGS.
 export V=1
 NOCONFIGURE=1 ./autogen.sh
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing"
 
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
         --infodir=/usr/share/info\
 	--disable-static
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
 mkdir -p ${D}/usr/share/gstreamer-1.0/presets
 mkdir -p ${D}/usr/share/doc/packages/gstreamer
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gstreamer-1.0
 mv gstreamer-1.0.lang gstreamer.lang 
 rm -rf ${D}/usr/share/gtk-doc
 rm -rf ${D}/usr/share/doc/packages/gstreamer/manual
 rm -rf ${D}/usr/share/doc/packages/gstreamer/pwg
 mkdir -p ${D}/usr/share/gstreamer-1.0/presets
 /bin/install -m644 -D ${S}/packaging/gstreamer.macros ${D}/usr/libexec/rpm/fileattrs/gstreamer.attr
 /bin/install -m755 -D ${S}/packaging/gstreamer.prov ${D}/usr/libexec/rpm/gstreamer-provides
 
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
PACKAGES += "libgstreamer"
PACKAGES += "gstreamer-locale"
PACKAGES += "gstreamer-devel"
PACKAGES += "gstreamer"
PACKAGES += "gstreamer-utils"

libgstreamer_files = ""
libgstreamer_files += "gstreamer.manifest"
libgstreamer_files += "/usr/lib/*.so.*"

gstreamer-locale_files = ""

gstreamer-devel_files = ""
gstreamer-devel_files += "gstreamer.manifest"
gstreamer-devel_files += "/usr/share/aclocal/*.m4"
gstreamer-devel_files += "/usr/include/*"
gstreamer-devel_files += "/usr/lib/*.so"
gstreamer-devel_files += "/usr/lib/pkgconfig/*.pc"
gstreamer-devel_files += "/usr/libexec/rpm/gstreamer-provides"
gstreamer-devel_files += "/usr/libexec/rpm/fileattrs/gstreamer.attr"

gstreamer_files = ""
gstreamer_files += "gstreamer.manifest"
gstreamer_files += "/usr/share/gstreamer-1.0"
gstreamer_files += "/usr/share/gstreamer-1.0/presets"
gstreamer_files += "/usr/lib/gstreamer-1.0"
gstreamer_files += "/usr/lib/gstreamer-1.0/*.so"
gstreamer_files += "/usr/libexec/gstreamer-1.0"
gstreamer_files += "/usr/libexec/gstreamer-1.0/gst-plugin-scanner"

gstreamer-utils_files = ""
gstreamer-utils_files += "gstreamer.manifest"
gstreamer-utils_files += "/usr/bin/*-1.0"
gstreamer-utils_files += "/usr/share/man/man?/*-1.0.*"

FILES_lib${PN} = "${libgstreamer_files}"
FILES_${PN}-locale = "${gstreamer-locale_files}"
FILES_${PN}-devel = "${gstreamer-devel_files}"
FILES_${PN} = "${gstreamer_files}"
FILES_${PN}-utils = "${gstreamer-utils_files}"

PKG_libgstreamer= "libgstreamer"
PKG_gstreamer-locale= "gstreamer-locale"
PKG_gstreamer-devel= "gstreamer-devel"
PKG_gstreamer= "gstreamer"
PKG_gstreamer-utils= "gstreamer-utils"

require gstreamer-extraconf.inc
