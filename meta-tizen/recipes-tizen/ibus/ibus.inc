DESCRIPTION = "Intelligent Input Bus for Linux OS"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ibus-devel 
PROVIDES += "ibus-devel"
RPROVIDES_ibus-devel += "ibus-devel"
RPROVIDES_ibus-devel += "ibus-dev"

#PROVIDES by ibus-libs 
PROVIDES += "ibus-libs"
RPROVIDES_ibus-libs += "ibus-libs"

#PROVIDES by ibus 
PROVIDES += "ibus"
RPROVIDES_ibus += "ibus"

#PROVIDES by ibus-devel-docs 
PROVIDES += "ibus-devel-docs"
RPROVIDES_ibus-devel-docs += "ibus-devel-docs"
RPROVIDES_ibus-devel-docs += "ibus-dev"

RDEPENDS = ""
#RDEPENDS of ibus-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ibus-libs"
RDEPENDS_${PN}-devel += "glib2-dev"
RDEPENDS_${PN}-devel += "ibus"
RDEPENDS_${PN}-devel += "dbus-dev"

#RDEPENDS of ibus-libs (${PN}-libs)
RDEPENDS_${PN}-libs += "dbus"

#RDEPENDS of ibus (${PN})
RDEPENDS_${PN} += "pygobject"
RDEPENDS_${PN} += "ibus-libs"
RDEPENDS_${PN} += "dbus-python"
RDEPENDS_${PN} += "iso-codes"

#RDEPENDS of ibus-devel-docs (${PN}-devel-docs)
RDEPENDS_${PN}-devel-docs += "ibus"
RDEPENDS_${PN}-devel-docs += "gtk-doc"


DEPENDS = ""
#DEPENDS of ibus 
DEPENDS += "gobject-introspection"
DEPENDS += "intltool-native"
DEPENDS += "iso-codes-devel"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "python-devel"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pygobject-devel"
DEPENDS += "libtool-cross"
DEPENDS += "dbus-python"
DEPENDS += "pkgconfig(xkbcommon)"
DEPENDS += "vala"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ibus.manifest .
 
 
 
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
 
 
 OPTIONS="--disable-static \
          --disable-tests \
          --disable-gtk2 \
          --disable-gtk3 \
          --disable-xim \
          --enable-wayland \
          --disable-vala \
          --disable-gtk-doc \
          --disable-gconf \
          --disable-setup \
          --disable-dconf \
          --enable-python-library \
          --disable-ui \
          --disable-libnotify \
          --enable-introspection"
 
 
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
         --infodir=/usr/share/info $OPTIONS
 
 # make -C po update-gmo
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 make DESTDIR=$RPM_BUILD_ROOT install
 rm -f $RPM_BUILD_ROOT/usr/lib/libibus-1.0.la
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} ibus10
 
 
}

PACKAGES = ""
PACKAGES += "ibus-devel"
PACKAGES += "ibus-libs"
PACKAGES += "ibus"
PACKAGES += "ibus-devel-docs"

ibus-devel_files = ""
ibus-devel_files += "ibus.manifest"
ibus-devel_files += "/usr/lib/lib*.so"
ibus-devel_files += "/usr/lib/pkgconfig/*"
ibus-devel_files += "/usr/include/*"
ibus-devel_files += "/usr/share/gir-1.0/IBus-1.0.gir"

ibus-libs_files = ""
ibus-libs_files += "ibus.manifest"
ibus-libs_files += "/usr/lib/libibus-1.0.so.*"
ibus-libs_files += "/usr/lib/girepository-1.0/IBus-1.0.typelib"

ibus_files = ""
ibus_files += "ibus.manifest"
ibus_files += "AUTHORS COPYING README"
ibus_files += "/usr/lib/python2.7/site-packages/ibus"
ibus_files += "/usr/lib/python2.7/site-packages/ibus/*"
ibus_files += "/usr/share/ibus/"
ibus_files += "/usr/bin/ibus"
ibus_files += "/usr/bin/ibus-daemon"
ibus_files += "/usr/share/ibus/keymaps/*"
ibus_files += "/usr/share/icons/hicolor/*/apps/*"
ibus_files += "/usr/libexec/*"
ibus_files += "/usr/share/ibus/component/simple.xml"
ibus_files += "/usr/share/bash-completion/completions/ibus.bash"
ibus_files += "/usr/share/man/man1/*"

ibus-devel-docs_files = ""
ibus-devel-docs_files += "/usr/share/info"
ibus-devel-docs_files += "/usr/share/man"
ibus-devel-docs_files += "/usr/share/gtk-doc/html/*"

FILES_${PN}-devel = "${ibus-devel_files}"
FILES_${PN}-libs = "${ibus-libs_files}"
FILES_${PN} = "${ibus_files}"
FILES_${PN}-devel-docs = "${ibus-devel-docs_files}"

PKG_ibus-devel= "ibus-devel"
PKG_ibus-libs= "ibus-libs"
PKG_ibus= "ibus"
PKG_ibus-devel-docs= "ibus-devel-docs"

require ibus-extraconf.inc
