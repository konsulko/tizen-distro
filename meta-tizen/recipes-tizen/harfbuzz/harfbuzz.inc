DESCRIPTION = "An OpenType text shaping engine"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/HarfBuzz"
SECTION = "Graphics/Font Management"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by harfbuzz-devel 
PROVIDES += "harfbuzz-devel"
RPROVIDES_harfbuzz-devel += "harfbuzz-devel"
RPROVIDES_harfbuzz-devel += "harfbuzz-dev"

#PROVIDES by harfbuzz-tools 
PROVIDES += "harfbuzz-tools"
RPROVIDES_harfbuzz-tools += "harfbuzz-tools"

#PROVIDES by libharfbuzz 
PROVIDES += "libharfbuzz"
RPROVIDES_libharfbuzz += "libharfbuzz"

#PROVIDES by harfbuzz 
PROVIDES += "harfbuzz"
RPROVIDES_harfbuzz += "harfbuzz"

RDEPENDS = ""
#RDEPENDS of harfbuzz-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libharfbuzz"


DEPENDS = ""
#DEPENDS of harfbuzz 
DEPENDS += "gcc-cross"
DEPENDS += "freetype2"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "pkgconfig(cairo-ft)"
DEPENDS += "pkgconfig(gthread-2.0)"
DEPENDS += "pkgconfig(icu-uc)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/harfbuzz.manifest .
 
 
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
         --infodir=/usr/share/info \
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
 
 
}

PACKAGES = ""
PACKAGES += "harfbuzz-devel"
PACKAGES += "harfbuzz-tools"
PACKAGES += "libharfbuzz"

harfbuzz-devel_files = ""
harfbuzz-devel_files += "harfbuzz.manifest"
harfbuzz-devel_files += "/usr/include/harfbuzz/"
harfbuzz-devel_files += "/usr/lib/*.so"
harfbuzz-devel_files += "/usr/lib/pkgconfig/harfbuzz.pc"

harfbuzz-tools_files = ""
harfbuzz-tools_files += "harfbuzz.manifest"
harfbuzz-tools_files += "/usr/bin/hb-ot-shape-closure"
harfbuzz-tools_files += "/usr/bin/hb-shape"
harfbuzz-tools_files += "/usr/bin/hb-view"

libharfbuzz_files = ""
libharfbuzz_files += "harfbuzz.manifest"
libharfbuzz_files += "/usr/lib/libharfbuzz.so.0*"

FILES_${PN}-devel = "${harfbuzz-devel_files}"
FILES_${PN}-tools = "${harfbuzz-tools_files}"
FILES_lib${PN} = "${libharfbuzz_files}"

PKG_harfbuzz-devel= "harfbuzz-devel"
PKG_harfbuzz-tools= "harfbuzz-tools"
PKG_libharfbuzz= "libharfbuzz"

require harfbuzz-extraconf.inc
