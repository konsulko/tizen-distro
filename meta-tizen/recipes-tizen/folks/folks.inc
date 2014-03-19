DESCRIPTION = "Library to create metacontacts from multiple sources"
HOMEPAGE = "http://telepathy.freedesktop.org/wiki/Folks"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by folks-tools 
PROVIDES += "folks-tools"
RPROVIDES_folks-tools += "folks-tools"

#PROVIDES by libfolks-eds 
PROVIDES += "libfolks-eds"
RPROVIDES_libfolks-eds += "libfolks-eds"

#PROVIDES by libfolks 
PROVIDES += "libfolks"
RPROVIDES_libfolks += "libfolks"

#PROVIDES by folks-locale 
PROVIDES += "folks-locale"
RPROVIDES_folks-locale += "folks-locale"
# the PROVIDES rules is ignore "libfolks-lang-all = 0.9.3"
PROVIDES += "libfolks-lang-all"
RPROVIDES_folks-locale += "libfolks-lang-all"

#PROVIDES by libfolks-data 
PROVIDES += "libfolks-data"
RPROVIDES_libfolks-data += "libfolks-data"

#PROVIDES by folks-devel 
PROVIDES += "folks-devel"
RPROVIDES_folks-devel += "folks-devel"
RPROVIDES_folks-devel += "folks-dev"

#PROVIDES by folks 
PROVIDES += "folks"
RPROVIDES_folks += "folks"

#PROVIDES by typelib-Folks 
PROVIDES += "typelib-Folks"
RPROVIDES_typelib-Folks += "typelib-Folks"

RDEPENDS = ""
#RDEPENDS of libfolks (lib${PN})
RDEPENDS_lib${PN} += "libfolks-data"

#RDEPENDS of folks-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "libfolks"

#RDEPENDS of libfolks-data (lib${PN}-data)
RDEPENDS_lib${PN}-data += "glib2-tools"

#RDEPENDS of folks-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libfolks"
RDEPENDS_${PN}-devel += "typelib-Folks"
RDEPENDS_${PN}-devel += "libfolks-eds"


DEPENDS = ""
#DEPENDS of folks 
DEPENDS += "pkgconfig(libedataserver-1.2)"
DEPENDS += "intltool-native"
DEPENDS += "readline-devel"
DEPENDS += "vala"
DEPENDS += "pkgconfig(gee-0.8)"
DEPENDS += "pkgconfig(gobject-introspection-1.0)"
DEPENDS += "pkgconfig(libebook-1.2)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(libxml-2.0)"

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
  --enable-vala \
  --disable-static \
  --enable-eds-backend \
  --disable-ofono-backend \
  --disable-telepathy-backend \
  --disable-socialweb-backend \
  --disable-fatal-warnings \
  --disable-tests \
  #eol
 
 PKG_CONFIG_PATH=`pwd`/folks \
 oe_runmake -j16 V=1
 
 
 
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
 find ${D}/usr/lib -name '*.la' -type f -delete -print
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} folks --without-C
 
 
}

PACKAGES = ""
PACKAGES += "folks-tools"
PACKAGES += "libfolks-eds"
PACKAGES += "libfolks"
PACKAGES += "folks-locale"
PACKAGES += "libfolks-data"
PACKAGES += "folks-devel"
PACKAGES += "typelib-Folks"

folks-tools_files = ""
folks-tools_files += "/usr/bin/folks-import"
folks-tools_files += "/usr/bin/folks-inspect"

libfolks-eds_files = ""
libfolks-eds_files += "/usr/lib/libfolks-eds.so.25*"
libfolks-eds_files += "/usr/lib/folks/39/backends/eds"
libfolks-eds_files += "/usr/lib/folks/39/backends/eds/eds.so"

libfolks_files = ""
libfolks_files += "/usr/lib/libfolks.so.25*"
libfolks_files += "/usr/lib/folks"
libfolks_files += "/usr/lib/folks/39"
libfolks_files += "/usr/lib/folks/39/backends"
libfolks_files += "/usr/lib/folks/39/backends/key-file"
libfolks_files += "/usr/lib/folks/39/backends/key-file/key-file.so"

folks-locale_files = ""

libfolks-data_files = ""
libfolks-data_files += "/usr/share/GConf/gsettings/folks.convert"
libfolks-data_files += "/usr/share/glib-2.0/schemas/org.freedesktop.folks.gschema.xml"

folks-devel_files = ""
folks-devel_files += "/usr/include/folks/"
folks-devel_files += "/usr/lib/*.so"
folks-devel_files += "/usr/lib/pkgconfig/*.pc"
folks-devel_files += "/usr/share/gir-1.0/Folks-0.6.gir"
folks-devel_files += "/usr/share/gir-1.0/FolksEds-0.6.gir"
folks-devel_files += "/usr/share/vala/vapi/folks.*"
folks-devel_files += "/usr/share/vala/vapi/folks-eds.*"

typelib-Folks_files = ""
typelib-Folks_files += "/usr/lib/girepository-1.0/FolksEds-0.6.typelib"
typelib-Folks_files += "/usr/lib/girepository-1.0/Folks-0.6.typelib"

FILES_${PN}-tools = "${folks-tools_files}"
FILES_lib${PN}-eds = "${libfolks-eds_files}"
FILES_lib${PN} = "${libfolks_files}"
FILES_${PN}-locale = "${folks-locale_files}"
FILES_lib${PN}-data = "${libfolks-data_files}"
FILES_${PN}-devel = "${folks-devel_files}"
FILES_typelib-Folks = "${typelib-Folks_files}"

PKG_folks-tools= "folks-tools"
PKG_libfolks-eds= "libfolks-eds"
PKG_libfolks= "libfolks"
PKG_folks-locale= "folks-locale"
PKG_libfolks-data= "libfolks-data"
PKG_folks-devel= "folks-devel"
PKG_typelib-Folks= "typelib-Folks"

require folks-extraconf.inc
