DESCRIPTION = "Simple DirectMedia Layer Library"
HOMEPAGE = "http://www.libsdl.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by SDL 
PROVIDES += "SDL"
RPROVIDES_SDL += "SDL"

#PROVIDES by libSDL 
PROVIDES += "libSDL"
RPROVIDES_libSDL += "libSDL"
# the PROVIDES rules is ignore "SDL = 1.2.15"
PROVIDES += "SDL"
RPROVIDES_libSDL += "SDL"

#PROVIDES by libSDL-devel 
PROVIDES += "libSDL-devel"
RPROVIDES_libSDL-devel += "libSDL-devel"
RPROVIDES_libSDL-devel += "libSDL-dev"
# the PROVIDES rules is ignore "SDL-devel = 1.2.15"
PROVIDES += "SDL-devel"
RPROVIDES_libSDL-devel += "SDL-devel"
RPROVIDES_libSDL-devel += "SDL-dev"

RDEPENDS = ""
#RDEPENDS of libSDL-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "gcc"
RDEPENDS_lib${PN}-devel += "pkgconfig(alsa)"
RDEPENDS_lib${PN}-devel += "libstdc++-dev"
RDEPENDS_lib${PN}-devel += "pkgconfig"
RDEPENDS_lib${PN}-devel += "libSDL"
RDEPENDS_lib${PN}-devel += "mesa-dev"


DEPENDS = ""
#DEPENDS of SDL 
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "libstdc++-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libpulse-devel"
DEPENDS += "autoconf-native"
DEPENDS += "gcc-c++"
DEPENDS += "mesa-devel"
DEPENDS += "nasm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/SDL.manifest .
 
 # remove the file to provide sufficient evidence that we are
 # not using this file during the build [bnc#508111]
 rm -f src/joystick/darwin/10.3.9-FIX/IOHIDLib.h
 
 
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
 
 ./autogen.sh
 
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
     --with-pic \
     --disable-rpath \
     --disable-alsa-shared \
     --disable-video-svga \
     --disable-video-ps3
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
PACKAGES += "libSDL"
PACKAGES += "libSDL-devel"

libSDL_files = ""
libSDL_files += "SDL.manifest"
libSDL_files += "COPYING"
libSDL_files += "/usr/lib/*.so.*"

libSDL-devel_files = ""
libSDL-devel_files += "SDL.manifest"
libSDL-devel_files += "/usr/bin/*"
libSDL-devel_files += "/usr/lib/*.so"
libSDL-devel_files += "/usr/include/SDL"
libSDL-devel_files += "/usr/share/aclocal"
libSDL-devel_files += "/usr/share/man/*/*"
libSDL-devel_files += "/usr/lib/pkgconfig/sdl.pc"

FILES_lib${PN} = "${libSDL_files}"
FILES_lib${PN}-devel = "${libSDL-devel_files}"

PKG_libSDL= "libSDL"
PKG_libSDL-devel= "libSDL-devel"

require SDL-extraconf.inc
