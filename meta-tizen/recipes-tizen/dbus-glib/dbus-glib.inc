DESCRIPTION = "GLib bindings for D-Bus"
HOMEPAGE = "http://www.freedesktop.org/software/dbus/"
SECTION = "System/Libraries"
LICENSE = "AFL-2.1 or GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dbus-glib-docs  
PROVIDES += "dbus-glib-docs "
RPROVIDES_dbus-glib-docs  += "dbus-glib-docs "

#PROVIDES by dbus-glib-devel 
PROVIDES += "dbus-glib-devel"
RPROVIDES_dbus-glib-devel += "dbus-glib-devel"
RPROVIDES_dbus-glib-devel += "dbus-glib-dev"

#PROVIDES by dbus-glib 
PROVIDES += "dbus-glib"
RPROVIDES_dbus-glib += "dbus-glib"

RDEPENDS = ""
#RDEPENDS of dbus-glib-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "dbus-glib"


DEPENDS = ""
#DEPENDS of dbus-glib 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "expat-devel"
DEPENDS += "libtool-cross"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dbus-glib.manifest .
 
 
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
         --infodir=/usr/share/info --disable-tests \
     --enable-verbose-mode=yes \
     --enable-asserts=yes \
     --disable-gtk-doc
 
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
 
 # don't care about bash completion in a consumer device
 rm -rf ${D}/etc/bash_completion.d/dbus-bash-completion.sh
 rm -rf ${D}/usr/libexec/dbus-bash-completion-helper
 
 
 
}

PACKAGES = ""
PACKAGES += "dbus-glib-docs"
PACKAGES += "dbus-glib-devel"
PACKAGES += "dbus-glib"

dbus-glib-docs_files = ""
dbus-glib-docs_files += "/usr/share/info"
dbus-glib-docs_files += "/usr/share/man"

dbus-glib-devel_files = ""
dbus-glib-devel_files += "dbus-glib.manifest"
dbus-glib-devel_files += "/usr/lib/lib*.so"
dbus-glib-devel_files += "/usr/lib/pkgconfig/dbus-glib-1.pc"
dbus-glib-devel_files += "/usr/include/dbus-1.0/dbus/*"
dbus-glib-devel_files += "/usr/bin/dbus-binding-tool"

dbus-glib_files = ""
dbus-glib_files += "dbus-glib.manifest"
dbus-glib_files += "/usr/lib/*glib*.so.*"

FILES_${PN}-docs = "${dbus-glib-docs_files}"
FILES_${PN}-devel = "${dbus-glib-devel_files}"
FILES_${PN} = "${dbus-glib_files}"

PKG_dbus-glib-docs= "dbus-glib-docs"
PKG_dbus-glib-devel= "dbus-glib-devel"
PKG_dbus-glib= "dbus-glib"

require dbus-glib-extraconf.inc
