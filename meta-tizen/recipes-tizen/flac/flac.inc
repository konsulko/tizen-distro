DESCRIPTION = "Free Lossless Audio Codec"
HOMEPAGE = "http://flac.sourceforge.net/"
SECTION = "Multimedia/Audio"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libflac++ 
PROVIDES += "libflac++"
RPROVIDES_libflac++ += "libflac++"

#PROVIDES by flac-devel 
PROVIDES += "flac-devel"
RPROVIDES_flac-devel += "flac-devel"
RPROVIDES_flac-devel += "flac-dev"

#PROVIDES by libflac 
PROVIDES += "libflac"
RPROVIDES_libflac += "libflac"

#PROVIDES by flac 
PROVIDES += "flac"
RPROVIDES_flac += "flac"

RDEPENDS = ""
#RDEPENDS of flac-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libflac"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of flac 
DEPENDS += "libtool-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "gcc-c++"
DEPENDS += "pkgconfig-native"
DEPENDS += "libogg-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/flac.manifest .
 
 
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
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -O3 -W -Wall -Wstrict-prototypes -Wformat-security"
 export CXXFLAGS="$CFLAGS"
 
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
         --infodir=/usr/share/info  --disable-thorough-tests --disable-exhaustive-tests\
     --disable-xmms-plugin \
 	--disable-static \
 	--disable-rpath \
 	--with-pic \
     --enable-sse
 
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
 rm -rf ${D}/usr/share/doc/flac-1.2.1
 
 
}

PACKAGES = ""
PACKAGES += "libflac"
PACKAGES += "libflac++"
PACKAGES += "flac"
PACKAGES += "flac-devel"

libflac_files = ""
libflac_files += "flac.manifest"
libflac_files += "/usr/lib/libFLAC.so.8*"

libflac++_files = ""
libflac++_files += "flac.manifest"
libflac++_files += "/usr/lib/libFLAC++.so.6*"

flac_files = ""
flac_files += "flac.manifest"
flac_files += "/usr/bin/*"
flac_files += "/usr/share/man/man*/*"

flac-devel_files = ""
flac-devel_files += "flac.manifest"
flac-devel_files += "/usr/lib/lib*.so"
flac-devel_files += "/usr/include/*"
flac-devel_files += "/usr/lib/pkgconfig/*.pc"
flac-devel_files += "/usr/share/aclocal/*.m4"

FILES_lib${PN} = "${libflac_files}"
FILES_lib${PN}++ = "${libflac++_files}"
FILES_${PN} = "${flac_files}"
FILES_${PN}-devel = "${flac-devel_files}"

PKG_libflac= "libflac"
PKG_libflac++= "libflac++"
PKG_flac= "flac"
PKG_flac-devel= "flac-devel"

require flac-extraconf.inc
