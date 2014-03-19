DESCRIPTION = "Device management service, ver 2"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by udisks-devel 
PROVIDES += "udisks-devel"
RPROVIDES_udisks-devel += "udisks-devel"
RPROVIDES_udisks-devel += "udisks-dev"

#PROVIDES by libudisks2-0 
PROVIDES += "libudisks2-0"
RPROVIDES_libudisks2-0 += "libudisks2-0"

#PROVIDES by udisks 
PROVIDES += "udisks"
RPROVIDES_udisks += "udisks"

#PROVIDES by typelib-UDisks-2_0 
PROVIDES += "typelib-UDisks-2_0"
RPROVIDES_typelib-UDisks-2_0 += "typelib-UDisks-2_0"

#PROVIDES by udisks-locale 
PROVIDES += "udisks-locale"
RPROVIDES_udisks-locale += "udisks-locale"

RDEPENDS = ""
#RDEPENDS of udisks-devel (udisks-devel)
RDEPENDS_udisks-devel += "libudisks2-0"

#RDEPENDS of udisks (udisks)
RDEPENDS_udisks += "libxslt"
RDEPENDS_udisks += "glib2"
RDEPENDS_udisks += "expat"
RDEPENDS_udisks += "polkit"

#RDEPENDS of typelib-UDisks-2_0 (typelib-UDisks-2_0)
RDEPENDS_typelib-UDisks-2_0 += "udisks"

#RDEPENDS of udisks-locale (udisks-locale)
RDEPENDS_udisks-locale += "udisks"


DEPENDS = ""
#DEPENDS of udisks 
DEPENDS += "gobject-introspection"
DEPENDS += "systemd"
DEPENDS += "expat"
DEPENDS += "gnome-common"
inherit pythonnative
DEPENDS += "libatasmart"
DEPENDS += "pkgconfig(polkit-agent-1)"
DEPENDS += "device-mapper"
DEPENDS += "acl"
DEPENDS += "intltool-native"
DEPENDS += "pkgconfig(polkit-gobject-1)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libxml-parser-perl"
DEPENDS += "pkgconfig(libxslt)"
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
   --disable-gtk-doc \
   --disable-gtk-doc-html \
   --disable-gtk-doc-pdf \
   --disable-man \
   --disable-nls
 
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../udisks2.service  ${D}//lib/systemd/system/multi-user.target.wants/udisks2.service  
 cp -a ${S}/packaging/udisks.manifest ${D}/usr/share/udisks.manifest
 
 
 
}

PACKAGES = ""
PACKAGES += "udisks-devel"
PACKAGES += "udisks-locale"
PACKAGES += "udisks"
PACKAGES += "libudisks2-0"
PACKAGES += "typelib-UDisks-2_0"

udisks-devel_files = ""
udisks-devel_files += "/usr/include/udisks2/"
udisks-devel_files += "/usr/lib/libudisks2.so"
udisks-devel_files += "/usr/lib/pkgconfig/udisks2.pc"
udisks-devel_files += "/usr/share/gir-1.0/UDisks-2.0.gir"

udisks-locale_files = ""

udisks_files = ""
udisks_files += "/usr/share/udisks.manifest"
udisks_files += "/lib/systemd/system/udisks2.service"
udisks_files += "/lib/systemd/system/multi-user.target.wants/udisks2.service"
udisks_files += "/usr/lib/udev/rules.d/80-udisks2.rules"
udisks_files += "/usr/bin/udisksctl"
udisks_files += "/etc/dbus-1/system.d/org.freedesktop.UDisks2.conf"
udisks_files += "/usr/lib/udisks2"
udisks_files += "/usr/lib/udisks2/udisksd"
udisks_files += "/usr/sbin/umount.udisks2"
udisks_files += "/usr/share/bash-completion/completions/udisksctl"
udisks_files += "/usr/share/dbus-1/system-services/org.freedesktop.UDisks2.service"
udisks_files += "/usr/share/polkit-1/actions/org.freedesktop.udisks2.policy"

libudisks2-0_files = ""
libudisks2-0_files += "/usr/lib/libudisks2.so.*"

typelib-UDisks-2_0_files = ""
typelib-UDisks-2_0_files += "/usr/lib/girepository-1.0/UDisks-2.0.typelib"

FILES_${PN}-devel = "${udisks-devel_files}"
FILES_${PN}-locale = "${udisks-locale_files}"
FILES_${PN} = "${udisks_files}"
FILES_lib${PN}2-0 = "${libudisks2-0_files}"
FILES_typelib-UDisks-2_0 = "${typelib-UDisks-2_0_files}"

PKG_udisks-devel= "udisks-devel"
PKG_udisks-locale= "udisks-locale"
PKG_udisks= "udisks"
PKG_libudisks2-0= "libudisks2-0"
PKG_typelib-UDisks-2_0= "typelib-UDisks-2_0"

require udisks2-extraconf.inc
