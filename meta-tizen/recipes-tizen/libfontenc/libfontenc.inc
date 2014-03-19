DESCRIPTION = "X"
HOMEPAGE = "http://www.x.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libfontenc 
PROVIDES += "libfontenc"
RPROVIDES_libfontenc += "libfontenc"

#PROVIDES by libfontenc-devel 
PROVIDES += "libfontenc-devel"
RPROVIDES_libfontenc-devel += "libfontenc-devel"
RPROVIDES_libfontenc-devel += "libfontenc-dev"

RDEPENDS = ""
#RDEPENDS of libfontenc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libfontenc"


DEPENDS = ""
#DEPENDS of libfontenc 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(xproto)"
DEPENDS += "autoconf-native"
DEPENDS += "pkgconfig(xorg-macros)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libfontenc.manifest .
 
 
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
     --with-encodingsdir=/usr/share/fonts/X11/encodings
 
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
PACKAGES += "libfontenc"
PACKAGES += "libfontenc-devel"

libfontenc_files = ""
libfontenc_files += "libfontenc.manifest"
libfontenc_files += "COPYING"
libfontenc_files += "/usr/lib/libfontenc.so.1"
libfontenc_files += "/usr/lib/libfontenc.so.1.0.0"

libfontenc-devel_files = ""
libfontenc-devel_files += "libfontenc.manifest"
libfontenc-devel_files += "/usr/include/X11"
libfontenc-devel_files += "/usr/include/X11/fonts"
libfontenc-devel_files += "/usr/include/X11/fonts/fontenc.h"
libfontenc-devel_files += "/usr/lib/libfontenc.so"
libfontenc-devel_files += "/usr/lib/pkgconfig/fontenc.pc"

FILES_${PN} = "${libfontenc_files}"
FILES_${PN}-devel = "${libfontenc-devel_files}"

PKG_libfontenc= "libfontenc"
PKG_libfontenc-devel= "libfontenc-devel"

require libfontenc-extraconf.inc
