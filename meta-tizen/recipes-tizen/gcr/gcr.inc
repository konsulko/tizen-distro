DESCRIPTION = "Library for Crypto UI related task"
HOMEPAGE = "http://www.gnome.org"
SECTION = "Security/Crypto Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by typelib-Gcr 
PROVIDES += "typelib-Gcr"
RPROVIDES_typelib-Gcr += "typelib-Gcr"

#PROVIDES by libgcr 
PROVIDES += "libgcr"
RPROVIDES_libgcr += "libgcr"

#PROVIDES by libgcr-locale 
PROVIDES += "libgcr-locale"
RPROVIDES_libgcr-locale += "libgcr-locale"
# the PROVIDES rules is ignore "libgcr-lang-all = 3.8.2"
PROVIDES += "libgcr-lang-all"
RPROVIDES_libgcr-locale += "libgcr-lang-all"

#PROVIDES by libgcr-devel 
PROVIDES += "libgcr-devel"
RPROVIDES_libgcr-devel += "libgcr-devel"
RPROVIDES_libgcr-devel += "libgcr-dev"

#PROVIDES by gcr 
PROVIDES += "gcr"
RPROVIDES_gcr += "gcr"

#PROVIDES by typelib-Gck 
PROVIDES += "typelib-Gck"
RPROVIDES_typelib-Gck += "typelib-Gck"

#PROVIDES by libgck 
PROVIDES += "libgck"
RPROVIDES_libgck += "libgck"
# the PROVIDES rules is ignore "gck = 3.8.2"
PROVIDES += "gck"
RPROVIDES_libgck += "gck"

#PROVIDES by gcr-data 
PROVIDES += "gcr-data"
RPROVIDES_gcr-data += "gcr-data"

#PROVIDES by libgck-devel 
PROVIDES += "libgck-devel"
RPROVIDES_libgck-devel += "libgck-devel"
RPROVIDES_libgck-devel += "libgck-dev"

RDEPENDS = ""
#RDEPENDS of libgcr (lib${PN})
RDEPENDS_lib${PN} += "gcr-data"

#RDEPENDS of libgcr-locale (lib${PN}-locale)
RDEPENDS_lib${PN}-locale += "libgcr"

#RDEPENDS of libgcr-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "typelib-Gcr"
RDEPENDS_lib${PN}-devel += "libgcr"

#RDEPENDS of gcr-data (${PN}-data)
RDEPENDS_${PN}-data += "glib2-tools"

#RDEPENDS of libgck-devel (libgck-devel)
RDEPENDS_libgck-devel += "typelib-Gck"
RDEPENDS_libgck-devel += "libgck"


DEPENDS = ""
#DEPENDS of gcr 
DEPENDS += "pkgconfig(p11-kit-1)"
DEPENDS += "shared-mime-info"
DEPENDS += "intltool-native"
DEPENDS += "gnome-common"
DEPENDS += "libtasn1-devel"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(gobject-introspection-1.0)"
DEPENDS += "gpg2"
DEPENDS += "pkgconfig(gthread-2.0)"
DEPENDS += "pkgconfig(gmodule-no-export-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "update-desktop-files"
DEPENDS += "libgcrypt-devel"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(libtasn1)"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "pkgconfig(gio-unix-2.0)"
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
  --with-gtk=no \
  --disable-gtk-doc-html
 
 make
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gcr
 
 
 
}

PACKAGES = ""
PACKAGES += "typelib-Gcr"
PACKAGES += "libgcr"
PACKAGES += "libgcr-locale"
PACKAGES += "libgcr-devel"
PACKAGES += "typelib-Gck"
PACKAGES += "libgck"
PACKAGES += "gcr-data"
PACKAGES += "libgck-devel"

typelib-Gcr_files = ""
typelib-Gcr_files += "/usr/lib/girepository-1.0/Gcr-3.typelib"

libgcr_files = ""
libgcr_files += "/usr/lib/libgcr-base-3.so.*"

libgcr-locale_files = ""

libgcr-devel_files = ""
libgcr-devel_files += "/usr/lib/libgcr-base-3.so"
libgcr-devel_files += "/usr/lib/pkgconfig/gcr-base-3.pc"
libgcr-devel_files += "/usr/include/gcr-3/"

typelib-Gck_files = ""
typelib-Gck_files += "/usr/lib/girepository-1.0/Gck-1.typelib"

libgck_files = ""
libgck_files += "/usr/lib/libgck-1.so.*"

gcr-data_files = ""
gcr-data_files += "/usr/share/GConf"
gcr-data_files += "/usr/share/GConf/gsettings"
gcr-data_files += "/usr/share/GConf/gsettings/org.gnome.crypto.pgp.convert"
gcr-data_files += "/usr/share/GConf/gsettings/org.gnome.crypto.pgp_keyservers.convert"
gcr-data_files += "/usr/share/glib-2.0/schemas/org.gnome.crypto.pgp.gschema.xml"

libgck-devel_files = ""
libgck-devel_files += "/usr/lib/libgck-1.so"
libgck-devel_files += "/usr/lib/pkgconfig/gck-1.pc"
libgck-devel_files += "/usr/include/gck-1/"
libgck-devel_files += "/usr/share/gir-1.0/Gck-1.gir"
libgck-devel_files += "/usr/share/gir-1.0/Gcr-3.gir"

FILES_typelib-Gcr = "${typelib-Gcr_files}"
FILES_lib${PN} = "${libgcr_files}"
FILES_lib${PN}-locale = "${libgcr-locale_files}"
FILES_lib${PN}-devel = "${libgcr-devel_files}"
FILES_typelib-Gck = "${typelib-Gck_files}"
FILES_libgck = "${libgck_files}"
FILES_${PN}-data = "${gcr-data_files}"
FILES_libgck-devel = "${libgck-devel_files}"

PKG_typelib-Gcr= "typelib-Gcr"
PKG_libgcr= "libgcr"
PKG_libgcr-locale= "libgcr-locale"
PKG_libgcr-devel= "libgcr-devel"
PKG_typelib-Gck= "typelib-Gck"
PKG_libgck= "libgck"
PKG_gcr-data= "gcr-data"
PKG_libgck-devel= "libgck-devel"

require gcr-extraconf.inc
