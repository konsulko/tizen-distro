DESCRIPTION = "A process-transparent configuration system"
HOMEPAGE = "http://www.gnome.org"
SECTION = "System/Base"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gconf-dbus-utils 
PROVIDES += "gconf-dbus-utils"
RPROVIDES_gconf-dbus-utils += "gconf-dbus-utils"

#PROVIDES by gconf-dbus 
PROVIDES += "gconf-dbus"
RPROVIDES_gconf-dbus += "gconf-dbus"

#PROVIDES by gconf-dbus-devel 
PROVIDES += "gconf-dbus-devel"
RPROVIDES_gconf-dbus-devel += "gconf-dbus-devel"
RPROVIDES_gconf-dbus-devel += "gconf-dbus-dev"

RDEPENDS = ""
#RDEPENDS of gconf-dbus-utils (${PN}-utils)
RDEPENDS_${PN}-utils += "gconf-dbus"
RDEPENDS_${PN}-utils += "dbus"

#RDEPENDS of gconf-dbus (${PN})
RDEPENDS_${PN} += "gconf-dbus"
RDEPENDS_${PN} += "dbus"

#RDEPENDS of gconf-dbus-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(libxml-2.0)"
RDEPENDS_${PN}-devel += "pkgconfig(dbus-1)"
RDEPENDS_${PN}-devel += "automake"
RDEPENDS_${PN}-devel += "pkgconfig(dbus-glib-1)"
RDEPENDS_${PN}-devel += "gconf-dbus"
RDEPENDS_${PN}-devel += "pkgconfig(glib-2.0)"


DEPENDS = ""
#DEPENDS of gconf-dbus 
DEPENDS += "autoconf-native"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "automake-native"
DEPENDS += "intltool-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gconf-dbus.manifest .
 cat ${S}/packaging/01_removePopt.dpatch | patch -s  -p1 --fuzz=2
 #patch0 -p1
 cat ${S}/packaging/02_poweroff.dpatch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 
 
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
         --infodir=/usr/share/info --disable-static --disable-gtk-doc --disable-defaults-service --disable-gtk --disable-nls --enable-system-bus 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -fr ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 install COPYING ${D}/usr/share/license/gconf-dbus
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} GConf2
 
 
}

PACKAGES = ""
PACKAGES += "gconf-dbus-utils"
PACKAGES += "gconf-dbus"
PACKAGES += "gconf-dbus-devel"

gconf-dbus-utils_files = ""
gconf-dbus-utils_files += "gconf-dbus.manifest"
gconf-dbus-utils_files += "/usr/bin/gconf-merge-tree"
gconf-dbus-utils_files += "/usr/bin/gconftool-2"
gconf-dbus-utils_files += "gconf-dbus.manifest"

gconf-dbus_files = ""
gconf-dbus_files += "gconf-dbus.manifest"
gconf-dbus_files += "COPYING"
gconf-dbus_files += "/usr/share/sgml/gconf/*"
gconf-dbus_files += "/etc/gconf/2/path"
gconf-dbus_files += "/etc/gconf"
gconf-dbus_files += "/etc/gconf/2"
gconf-dbus_files += "/etc/gconf/gconf.xml.defaults"
gconf-dbus_files += "/etc/gconf/gconf.xml.mandatory"
gconf-dbus_files += "/usr/libexec/*"
gconf-dbus_files += "/usr/lib/*.so.*"
gconf-dbus_files += "/usr/lib/GConf-dbus"
gconf-dbus_files += "/usr/lib/GConf-dbus/2"
gconf-dbus_files += "/usr/lib/GConf-dbus/2/*.so"
gconf-dbus_files += "/usr/share/dbus-1/services/gconf.service"
gconf-dbus_files += "/etc/dbus-1/system.d/gconfd.conf"
gconf-dbus_files += "gconf-dbus.manifest"
gconf-dbus_files += "/usr/share/license/gconf-dbus"

gconf-dbus-devel_files = ""
gconf-dbus-devel_files += "gconf-dbus.manifest"
gconf-dbus-devel_files += "/usr/share/gtk-doc/html/gconf/*"
gconf-dbus-devel_files += "/usr/share/man/man1/*"
gconf-dbus-devel_files += "/usr/lib/*.so"
gconf-dbus-devel_files += "/usr/include/gconf"
gconf-dbus-devel_files += "/usr/share/aclocal/*.m4"
gconf-dbus-devel_files += "/usr/lib/pkgconfig/*"

FILES_${PN}-utils = "${gconf-dbus-utils_files}"
FILES_${PN} = "${gconf-dbus_files}"
FILES_${PN}-devel = "${gconf-dbus-devel_files}"

PKG_gconf-dbus-utils= "gconf-dbus-utils"
PKG_gconf-dbus= "gconf-dbus"
PKG_gconf-dbus-devel= "gconf-dbus-devel"

require gconf-dbus-extraconf.inc
