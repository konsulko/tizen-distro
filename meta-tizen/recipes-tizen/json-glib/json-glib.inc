DESCRIPTION = "Library for JavaScript Object Notation format"
HOMEPAGE = "http://live.gnome.org/JsonGlib"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libjson-glib 
PROVIDES += "libjson-glib"
RPROVIDES_libjson-glib += "libjson-glib"
# the PROVIDES rules is ignore "json-glib = 0.16.0"
PROVIDES += "json-glib"
RPROVIDES_libjson-glib += "json-glib"

#PROVIDES by typelib-Json 
PROVIDES += "typelib-Json"
RPROVIDES_typelib-Json += "typelib-Json"

#PROVIDES by json-glib-devel 
PROVIDES += "json-glib-devel"
RPROVIDES_json-glib-devel += "json-glib-devel"
RPROVIDES_json-glib-devel += "json-glib-dev"

#PROVIDES by json-glib 
PROVIDES += "json-glib"
RPROVIDES_json-glib += "json-glib"

#PROVIDES by json-glib-locale 
PROVIDES += "json-glib-locale"
RPROVIDES_json-glib-locale += "json-glib-locale"
# the PROVIDES rules is ignore "json-glib-lang-all = 0.16.0"
PROVIDES += "json-glib-lang-all"
RPROVIDES_json-glib-locale += "json-glib-lang-all"

RDEPENDS = ""
#RDEPENDS of json-glib-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libjson-glib"

#RDEPENDS of json-glib-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "json-glib"


DEPENDS = ""
#DEPENDS of json-glib 
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/json-glib.manifest .
 
 
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
         --infodir=/usr/share/info
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} json-glib-1.0
 
 mv json-glib-1.0.lang json-glib.lang
 
 
}

PACKAGES = ""
PACKAGES += "libjson-glib"
PACKAGES += "json-glib-devel"
PACKAGES += "json-glib-locale"

libjson-glib_files = ""
libjson-glib_files += "json-glib.manifest"
libjson-glib_files += "/usr/lib/*.so.*"

json-glib-devel_files = ""
json-glib-devel_files += "json-glib.manifest"
json-glib-devel_files += "/usr/include/json-glib-1.0"
json-glib-devel_files += "/usr/lib/*.so"
json-glib-devel_files += "/usr/lib/pkgconfig/*.pc"
json-glib-devel_files += "/usr/share/gtk-doc"
json-glib-devel_files += "/usr/share/gtk-doc/html"
json-glib-devel_files += "/usr/share/gtk-doc/html/json-glib"

json-glib-locale_files = ""

FILES_lib${PN} = "${libjson-glib_files}"
FILES_${PN}-devel = "${json-glib-devel_files}"
FILES_${PN}-locale = "${json-glib-locale_files}"

PKG_libjson-glib= "libjson-glib"
PKG_json-glib-devel= "json-glib-devel"
PKG_json-glib-locale= "json-glib-locale"

require json-glib-extraconf.inc
