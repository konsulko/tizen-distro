DESCRIPTION = "HTTP client/server library for GNOME"
HOMEPAGE = "http://www.gnome.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by typelib-Soup 
PROVIDES += "typelib-Soup"
RPROVIDES_typelib-Soup += "typelib-Soup"

#PROVIDES by libsoup-locale  
PROVIDES += "libsoup-locale "
RPROVIDES_libsoup-locale  += "libsoup-locale "
# the PROVIDES rules is ignore "libsoup-lang-all = 2.42.2"
PROVIDES += "libsoup-lang-all"
RPROVIDES_libsoup-locale  += "libsoup-lang-all"

#PROVIDES by libsoup 
PROVIDES += "libsoup"
RPROVIDES_libsoup += "libsoup"

#PROVIDES by libsoup-devel 
PROVIDES += "libsoup-devel"
RPROVIDES_libsoup-devel += "libsoup-devel"
RPROVIDES_libsoup-devel += "libsoup-dev"

RDEPENDS = ""
#RDEPENDS of libsoup-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "libsoup"

#RDEPENDS of libsoup-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsoup"

#RDEPENDS of libsoup (${PN})
RDEPENDS_${PN} += "glib-networking"


DEPENDS = ""
#DEPENDS of libsoup 
DEPENDS += "glib-networking"
DEPENDS += "intltool-native"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "gnome-common"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "sqlite3-devel"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libsoup.manifest .
 
 
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
         --infodir=/usr/share/info\
     --without-gnome \
     --enable-sqlite=yes \
     --disable-tls-check \
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libsoup
 
 
}

PACKAGES = ""
PACKAGES += "libsoup-locale"
PACKAGES += "libsoup"
PACKAGES += "libsoup-devel"

libsoup-locale_files = ""

libsoup_files = ""
libsoup_files += "libsoup.manifest"
libsoup_files += "/usr/lib/*.so.*"

libsoup-devel_files = ""
libsoup-devel_files += "libsoup.manifest"
libsoup-devel_files += "/usr/include/libsoup-2.4"
libsoup-devel_files += "/usr/lib/*.so"
libsoup-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN}-locale = "${libsoup-locale_files}"
FILES_${PN} = "${libsoup_files}"
FILES_${PN}-devel = "${libsoup-devel_files}"

PKG_libsoup-locale= "libsoup-locale"
PKG_libsoup= "libsoup"
PKG_libsoup-devel= "libsoup-devel"

require libsoup-extraconf.inc
