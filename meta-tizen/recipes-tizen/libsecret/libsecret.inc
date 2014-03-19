DESCRIPTION = "Library for accessing the Secret Service API"
HOMEPAGE = "http://www.gnome.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsecret-tools 
PROVIDES += "libsecret-tools"
RPROVIDES_libsecret-tools += "libsecret-tools"

#PROVIDES by typelib-Secret 
PROVIDES += "typelib-Secret"
RPROVIDES_typelib-Secret += "typelib-Secret"

#PROVIDES by libsecret-locale 
PROVIDES += "libsecret-locale"
RPROVIDES_libsecret-locale += "libsecret-locale"
# the PROVIDES rules is ignore "libsecret-lang-all = 0.15"
PROVIDES += "libsecret-lang-all"
RPROVIDES_libsecret-locale += "libsecret-lang-all"

#PROVIDES by libsecret-devel 
PROVIDES += "libsecret-devel"
RPROVIDES_libsecret-devel += "libsecret-devel"
RPROVIDES_libsecret-devel += "libsecret-dev"

#PROVIDES by libsecret 
PROVIDES += "libsecret"
RPROVIDES_libsecret += "libsecret"

#PROVIDES by typelib-SecretUnstable 
PROVIDES += "typelib-SecretUnstable"
RPROVIDES_typelib-SecretUnstable += "typelib-SecretUnstable"

RDEPENDS = ""
#RDEPENDS of libsecret-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "libsecret"

#RDEPENDS of libsecret-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "typelib-Secret"
RDEPENDS_${PN}-devel += "libsecret"
RDEPENDS_${PN}-devel += "typelib-SecretUnstable"


DEPENDS = ""
#DEPENDS of libsecret 
DEPENDS += "gobject-introspection"
DEPENDS += "intltool-native"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "xsltproc"
DEPENDS += "vala"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(gio-unix-2.0)"
DEPENDS += "docbook-xsl-stylesheets"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "fdupes-native"
DEPENDS += "libgcrypt"
DEPENDS += "gtk-doc"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --disable-static
 make V=1
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libsecret
 rm -rf ${D}/usr/share/locales/*
 
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
PACKAGES += "libsecret-tools"
PACKAGES += "typelib-Secret"
PACKAGES += "libsecret-locale"
PACKAGES += "libsecret-devel"
PACKAGES += "typelib-SecretUnstable"
PACKAGES += "libsecret"

libsecret-tools_files = ""
libsecret-tools_files += "/usr/bin/secret-tool"

typelib-Secret_files = ""
typelib-Secret_files += "/usr/lib/girepository-1.0/Secret-1.typelib"

libsecret-locale_files = ""

libsecret-devel_files = ""
libsecret-devel_files += "AUTHORS ChangeLog NEWS README"
libsecret-devel_files += "/usr/lib/libsecret-1.so"
libsecret-devel_files += "/usr/lib/pkgconfig/libsecret-1.pc"
libsecret-devel_files += "/usr/lib/pkgconfig/libsecret-unstable.pc"
libsecret-devel_files += "/usr/include/libsecret-1/"
libsecret-devel_files += "/usr/share/gir-1.0/Secret-1.gir"
libsecret-devel_files += "/usr/share/gir-1.0/SecretUnstable-0.gir"
libsecret-devel_files += "/usr/share/vala/vapi"
libsecret-devel_files += "/usr/share/vala/vapi/libsecret-1.deps"
libsecret-devel_files += "/usr/share/vala/vapi/libsecret-1.vapi"
libsecret-devel_files += "/usr/share/vala/vapi/libsecret-unstable.deps"
libsecret-devel_files += "/usr/share/vala/vapi/libsecret-unstable.vapi"
libsecret-devel_files += "/usr/share/vala/vapi/mock-service-0.vapi"

typelib-SecretUnstable_files = ""
typelib-SecretUnstable_files += "/usr/lib/girepository-1.0/SecretUnstable-0.typelib"

libsecret_files = ""
libsecret_files += "/usr/lib/libsecret-1.so.*"

FILES_${PN}-tools = "${libsecret-tools_files}"
FILES_typelib-Secret = "${typelib-Secret_files}"
FILES_${PN}-locale = "${libsecret-locale_files}"
FILES_${PN}-devel = "${libsecret-devel_files}"
FILES_typelib-SecretUnstable = "${typelib-SecretUnstable_files}"
FILES_${PN} = "${libsecret_files}"

PKG_libsecret-tools= "libsecret-tools"
PKG_typelib-Secret= "typelib-Secret"
PKG_libsecret-locale= "libsecret-locale"
PKG_libsecret-devel= "libsecret-devel"
PKG_typelib-SecretUnstable= "typelib-SecretUnstable"
PKG_libsecret= "libsecret"

require libsecret-extraconf.inc
