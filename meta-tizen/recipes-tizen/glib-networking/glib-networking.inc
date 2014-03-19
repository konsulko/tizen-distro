DESCRIPTION = "Network-related GIO modules for glib"
HOMEPAGE = "http://www.gnome.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by glib-networking 
PROVIDES += "glib-networking"
RPROVIDES_glib-networking += "glib-networking"

#PROVIDES by glib-networking-locale 
PROVIDES += "glib-networking-locale"
RPROVIDES_glib-networking-locale += "glib-networking-locale"
# the PROVIDES rules is ignore "glib-networking-lang-all = 2.36.2"
PROVIDES += "glib-networking-lang-all"
RPROVIDES_glib-networking-locale += "glib-networking-lang-all"

RDEPENDS = ""
#RDEPENDS of glib-networking-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "glib-networking"


DEPENDS = ""
#DEPENDS of glib-networking 
DEPENDS += "pkgconfig(p11-kit-1)"
DEPENDS += "intltool-native"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(gnutls)"
DEPENDS += "libgcrypt-devel"
DEPENDS += "pkgconfig(gio-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/glib-networking.manifest .
 
 
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
     --disable-static \
     --with-ca-certificates=/etc/ssl/ca-bundle.pem
 make -j16 V=1
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} glib-networking
 
 
}

PACKAGES = ""
PACKAGES += "glib-networking-locale"
PACKAGES += "glib-networking"

glib-networking-locale_files = ""

glib-networking_files = ""
glib-networking_files += "glib-networking.manifest"
glib-networking_files += "/usr/lib/gio/modules/libgiognutls.so"

FILES_${PN}-locale = "${glib-networking-locale_files}"
FILES_${PN} = "${glib-networking_files}"

PKG_glib-networking-locale= "glib-networking-locale"
PKG_glib-networking= "glib-networking"

require glib-networking-extraconf.inc
