DESCRIPTION = "General-Purpose Utility Library"
HOMEPAGE = "http://www.gtk.org/"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgmodule 
PROVIDES += "libgmodule"
RPROVIDES_libgmodule += "libgmodule"

#PROVIDES by glib2-locale  
PROVIDES += "glib2-locale "
RPROVIDES_glib2-locale  += "glib2-locale "
# the PROVIDES rules is ignore "glib2-lang-all = 2.36.4"
PROVIDES += "glib2-lang-all"
RPROVIDES_glib2-locale  += "glib2-lang-all"

#PROVIDES by gio-branding-upstream 
PROVIDES += "gio-branding-upstream"
RPROVIDES_gio-branding-upstream += "gio-branding-upstream"
# the PROVIDES rules is ignore "glib2-branding-upstream = 2.36.4"
PROVIDES += "glib2-branding-upstream"
RPROVIDES_gio-branding-upstream += "glib2-branding-upstream"
# the PROVIDES rules is ignore "gio-branding = 2.36.4"
PROVIDES += "gio-branding"
RPROVIDES_gio-branding-upstream += "gio-branding"

#PROVIDES by glib2-tools 
PROVIDES += "glib2-tools"
RPROVIDES_glib2-tools += "glib2-tools"

#PROVIDES by libgthread 
PROVIDES += "libgthread"
RPROVIDES_libgthread += "libgthread"

#PROVIDES by glib2-devel-static 
PROVIDES += "glib2-devel-static"
RPROVIDES_glib2-devel-static += "glib2-devel-static"
RPROVIDES_glib2-devel-static += "glib2-dev"

#PROVIDES by libglib 
PROVIDES += "libglib"
RPROVIDES_libglib += "libglib"
# the PROVIDES rules is ignore "glib2 = 2.36.4"
PROVIDES += "glib2"
RPROVIDES_libglib += "glib2"

#PROVIDES by glib2 
PROVIDES += "glib2"
RPROVIDES_glib2 += "glib2"

#PROVIDES by glib2-devel 
PROVIDES += "glib2-devel"
RPROVIDES_glib2-devel += "glib2-devel"
RPROVIDES_glib2-devel += "glib2-dev"
# the PROVIDES rules is ignore "glib2-doc = 2.19.6"
PROVIDES += "glib2-doc"
RPROVIDES_glib2-devel += "glib2-doc"

#PROVIDES by libgio 
PROVIDES += "libgio"
RPROVIDES_libgio += "libgio"
# the PROVIDES rules is ignore "gio = 2.36.4"
PROVIDES += "gio"
RPROVIDES_libgio += "gio"

#PROVIDES by libgobject 
PROVIDES += "libgobject"
RPROVIDES_libgobject += "libgobject"

RDEPENDS = ""
#RDEPENDS of glib2-locale  (${PN}2-locale )
RDEPENDS_${PN}2-locale  += "glib2"

#RDEPENDS of gio-branding-upstream (gio-branding-upstream)
RDEPENDS_gio-branding-upstream += "libgio"

#RDEPENDS of glib2-devel-static (${PN}2-devel-static)
RDEPENDS_${PN}2-devel-static += "glib2-dev"

#RDEPENDS of glib2-devel (${PN}2-devel)
RDEPENDS_${PN}2-devel += "glibc-dev"
RDEPENDS_${PN}2-devel += "libgmodule"
RDEPENDS_${PN}2-devel += "pkgconfig"
RDEPENDS_${PN}2-devel += "glib2-tools"
RDEPENDS_${PN}2-devel += "libgthread"
RDEPENDS_${PN}2-devel += "python-xml"
RDEPENDS_${PN}2-devel += "libgio"
RDEPENDS_${PN}2-devel += "glib2"
RDEPENDS_${PN}2-devel += "libglib"
RDEPENDS_${PN}2-devel += "libgobject"

#RDEPENDS of libgio (libgio)
RDEPENDS_libgio += "gio-branding"
RDEPENDS_libgio += "shared-mime-info"


DEPENDS = ""
#DEPENDS of glib2 
DEPENDS += "pkgconfig(libpcre)"
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(libelf)"
DEPENDS += "pkgconfig(libffi)"
inherit pythonnative
DEPENDS += "pkgconfig-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"
DEPENDS += "python-xml"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n glib2-2.36.4
 cp ${S}/packaging/glib2.manifest .
 cp -a ${S}/packaging/glib2.sh ${S}/packaging/glib2.csh .
 cp -a ${S}/packaging/glib2-upstream-gnome_defaults.conf gnome_defaults.conf
 if ! test -f /usr/share/aclocal/gtk-doc.m4 ; then
     cp -a ${S}/packaging/gtk-doc.m4 m4macros/
 fi
 
 
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
         --infodir=/usr/share/info \
     --enable-static \
     --with-pcre=system
 
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
   
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} glib20 --without-C
 
 mkdir -p ${D}/etc/profile.d
 install -D -m0644 glib2.sh ${D}/etc/profile.d/zzz-glib2.sh
 install -D -m0644 glib2.csh ${D}/etc/profile.d/zzz-glib2.csh
 install -D -m0644 gnome_defaults.conf ${D}/etc/gnome_defaults.conf
 # default apps magic
 mkdir -p ${D}/var/cache/gio-2.0 ${D}/usr/share/applications
 touch ${D}/var/cache/gio-2.0/gnome-defaults.list
 touch ${D}/var/cache/gio-2.0/xfce-defaults.list
 touch ${D}/var/cache/gio-2.0/lxde-defaults.list
 ln -s /var/cache/gio-2.0/gnome-defaults.list ${D}/usr/share/applications/defaults.list
 # gio-querymodules magic
 touch ${D}/usr/lib/gio/modules/giomodule.cache
 # gsettings magic
 touch ${D}/usr/share/glib-2.0/schemas/gschemas.compiled
 # remove files we don't care about
 find ${D}/usr/lib -name '*.la' -type f -delete -print
 # Install rpm macros
 mkdir -p ${D}/etc/rpm
 cp ${S}/packaging/macros.glib2 ${D}/etc/rpm
 
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
PACKAGES += "glib2-locale"
PACKAGES += "libgmodule"
PACKAGES += "gio-branding-upstream"
PACKAGES += "glib2-tools"
PACKAGES += "libgthread"
PACKAGES += "glib2-devel-static"
PACKAGES += "libgio"
PACKAGES += "glib2-devel"
PACKAGES += "libglib"
PACKAGES += "libgobject"

glib2-locale_files = ""

libgmodule_files = ""
libgmodule_files += "glib2.manifest"
libgmodule_files += "/usr/lib/libgmodule*.so.*"

gio-branding-upstream_files = ""
gio-branding-upstream_files += "glib2.manifest"
gio-branding-upstream_files += "(noreplace) /etc/gnome_defaults.conf"

glib2-tools_files = ""
glib2-tools_files += "glib2.manifest"
glib2-tools_files += "/usr/share/bash-completion"
glib2-tools_files += "/usr/share/bash-completion/completions"
glib2-tools_files += "/usr/share/bash-completion/completions/gresource"
glib2-tools_files += "/usr/share/bash-completion/completions/gsettings"
glib2-tools_files += "/usr/bin/gdbus"
glib2-tools_files += "/usr/bin/gio-querymodules*"
glib2-tools_files += "/usr/bin/glib-compile-schemas"
glib2-tools_files += "/usr/bin/gresource"
glib2-tools_files += "/usr/bin/gsettings"
glib2-tools_files += "/etc/profile.d/zzz-glib2.*"

libgthread_files = ""
libgthread_files += "glib2.manifest"
libgthread_files += "/usr/lib/libgthread*.so.*"

glib2-devel-static_files = ""
glib2-devel-static_files += "glib2.manifest"
glib2-devel-static_files += "/usr/lib/lib*.a"

libgio_files = ""
libgio_files += "glib2.manifest"
libgio_files += "/usr/lib/libgio*.so.*"
libgio_files += "/usr/lib/gio"
libgio_files += "/usr/lib/gio/modules"
libgio_files += "/usr/share/glib-2.0/"
libgio_files += "/usr/share/glib-2.0/schemas/"
libgio_files += "/usr/share/applications/defaults.list"
libgio_files += "/var/cache/gio-2.0"

glib2-devel_files = ""
glib2-devel_files += "glib2.manifest"
glib2-devel_files += "/usr/bin/gdbus-codegen"
glib2-devel_files += "/usr/share/bash-completion/completions/*"
glib2-devel_files += "/usr/share/glib-2.0/codegen"
glib2-devel_files += "/usr/bin/glib-compile-resources"
glib2-devel_files += "/usr/bin/glib-genmarshal"
glib2-devel_files += "/usr/bin/glib-gettextize"
glib2-devel_files += "/usr/bin/glib-mkenums"
glib2-devel_files += "/usr/bin/gobject-query"
glib2-devel_files += "/usr/bin/gtester"
glib2-devel_files += "/usr/bin/gtester-report"
glib2-devel_files += "/usr/share/aclocal"
glib2-devel_files += "/usr/share/aclocal/glib-2.0.m4"
glib2-devel_files += "/usr/share/aclocal/glib-gettext.m4"
glib2-devel_files += "/usr/share/aclocal/gsettings.m4"
glib2-devel_files += "/usr/share/glib-2.0/"
glib2-devel_files += "/usr/share/glib-2.0/gdb/"
glib2-devel_files += "/usr/share/glib-2.0/gettext/"
glib2-devel_files += "/usr/share/glib-2.0/schemas/gschema.dtd"
glib2-devel_files += "/usr/include/glib-2.0"
glib2-devel_files += "/usr/include/gio-unix-2.0"
glib2-devel_files += "/usr/lib/lib*.so"
glib2-devel_files += "/usr/lib/glib-2.0/"
glib2-devel_files += "/usr/lib/glib-2.0/include/"
glib2-devel_files += "/usr/lib/pkgconfig/*.pc"
glib2-devel_files += "/usr/share/gdb/auto-load/usr/lib/*-gdb.py"
glib2-devel_files += "/etc/rpm/macros.glib2"
glib2-devel_files += "/usr/share/gdb"
glib2-devel_files += "/usr/share/gdb/auto-load"
glib2-devel_files += "/usr/share/gdb/auto-load/usr"
glib2-devel_files += "/usr/share/gdb/auto-load/usr/lib"

libglib_files = ""
libglib_files += "glib2.manifest"
libglib_files += "/usr/lib/libglib*.so.*"

libgobject_files = ""
libgobject_files += "glib2.manifest"
libgobject_files += "/usr/lib/libgobject*.so.*"

FILES_${PN}-locale = "${glib2-locale_files}"
FILES_libgmodule = "${libgmodule_files}"
FILES_gio-branding-upstream = "${gio-branding-upstream_files}"
FILES_${PN}-tools = "${glib2-tools_files}"
FILES_libgthread = "${libgthread_files}"
FILES_${PN}-devel-static = "${glib2-devel-static_files}"
FILES_libgio = "${libgio_files}"
FILES_${PN}-devel = "${glib2-devel_files}"
FILES_libglib = "${libglib_files}"
FILES_libgobject = "${libgobject_files}"

PKG_glib2-locale= "glib2-locale"
PKG_libgmodule= "libgmodule"
PKG_gio-branding-upstream= "gio-branding-upstream"
PKG_glib2-tools= "glib2-tools"
PKG_libgthread= "libgthread"
PKG_glib2-devel-static= "glib2-devel-static"
PKG_libgio= "libgio"
PKG_glib2-devel= "glib2-devel"
PKG_libglib= "libglib"
PKG_libgobject= "libgobject"

require glib-extraconf.inc
