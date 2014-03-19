DESCRIPTION = "X font handling library for server and utilities"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libXfont 
PROVIDES += "libXfont"
RPROVIDES_libXfont += "libXfont"

#PROVIDES by libXfont-devel 
PROVIDES += "libXfont-devel"
RPROVIDES_libXfont-devel += "libXfont-devel"
RPROVIDES_libXfont-devel += "libXfont-dev"

RDEPENDS = ""
#RDEPENDS of libXfont-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libXfont"


DEPENDS = ""
#DEPENDS of libXfont 
DEPENDS += "zlib-devel"
DEPENDS += "freetype2"
DEPENDS += "pkgconfig(xtrans)"
DEPENDS += "pkgconfig(xorg-macros)"
DEPENDS += "pkgconfig(fontsproto)"
DEPENDS += "pkgconfig(fontenc)"
DEPENDS += "pkgconfig-native"
DEPENDS += "pkgconfig(xproto)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libXfont.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static \
            --enable-fc --enable-builtins --enable-pcfformat --enable-bdfformat --without-bzip2
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
PACKAGES += "libXfont"
PACKAGES += "libXfont-devel"

libXfont_files = ""
libXfont_files += "libXfont.manifest"
libXfont_files += "/usr/lib/libXfont.so.1*"

libXfont-devel_files = ""
libXfont-devel_files += "libXfont.manifest"
libXfont-devel_files += "/usr/include/X11/*"
libXfont-devel_files += "/usr/lib/libXfont.so"
libXfont-devel_files += "/usr/lib/pkgconfig/xfont.pc"

FILES_${PN} = "${libXfont_files}"
FILES_${PN}-devel = "${libXfont-devel_files}"

PKG_libXfont= "libXfont"
PKG_libXfont-devel= "libXfont-devel"

require libXfont-extraconf.inc
