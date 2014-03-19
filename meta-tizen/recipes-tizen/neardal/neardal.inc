DESCRIPTION = "Neard Abstraction Library (for Neard v0.7)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Connectivity/NFC"
LICENSE = "LGPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by neardal-devel 
PROVIDES += "neardal-devel"
RPROVIDES_neardal-devel += "neardal-devel"
RPROVIDES_neardal-devel += "neardal-dev"

#PROVIDES by neardal 
PROVIDES += "neardal"
RPROVIDES_neardal += "neardal"

RDEPENDS = ""
#RDEPENDS of neardal-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "neardal"

#RDEPENDS of neardal (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of neardal 
DEPENDS += "intltool-native"
inherit pythonnative
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libtool-cross"
DEPENDS += "dlog"
DEPENDS += "python-xml"
DEPENDS += "autoconf-native"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n neardal-0.7.0
 
 
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
 
 autoreconf --force --install
 
 
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
         --infodir=/usr/share/info --disable-traces --prefix=/usr
 make
 
 
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
 
 # executed after install
 
}

PACKAGES = ""
PACKAGES += "neardal-devel"
PACKAGES += "neardal"

neardal-devel_files = ""
neardal-devel_files += "/usr/include/neardal/*.h"
neardal-devel_files += "/usr/lib/pkgconfig/neardal.pc"
neardal-devel_files += "/usr/lib/libneardal.so"

neardal_files = ""
neardal_files += "README AUTHORS NEWS"
neardal_files += "/usr/lib/libneardal.so.0"
neardal_files += "/usr/lib/libneardal.so.0.0.1"

FILES_${PN}-devel = "${neardal-devel_files}"
FILES_${PN} = "${neardal_files}"

PKG_neardal-devel= "neardal-devel"
PKG_neardal= "neardal"

require neardal-extraconf.inc
