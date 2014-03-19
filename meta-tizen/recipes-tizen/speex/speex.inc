DESCRIPTION = "An Open Source, Patent Free Speech Codec"
HOMEPAGE = "http://www.speex.org/"
SECTION = "Multimedia/Audio"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by speex 
PROVIDES += "speex"
RPROVIDES_speex += "speex"

#PROVIDES by libspeex 
PROVIDES += "libspeex"
RPROVIDES_libspeex += "libspeex"

#PROVIDES by libspeexdsp 
PROVIDES += "libspeexdsp"
RPROVIDES_libspeexdsp += "libspeexdsp"

#PROVIDES by speex-devel 
PROVIDES += "speex-devel"
RPROVIDES_speex-devel += "speex-devel"
RPROVIDES_speex-devel += "speex-dev"

RDEPENDS = ""
#RDEPENDS of speex-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libspeex"
RDEPENDS_${PN}-devel += "libspeexdsp"
RDEPENDS_${PN}-devel += "libogg-dev"


DEPENDS = ""
#DEPENDS of speex 
DEPENDS += "libtool-cross"
DEPENDS += "libogg"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n speex-1.2rc1
 cp ${S}/packaging/speex.manifest .
 
 
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
 
 autoreconf -fi
 
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
     --with-ogg-libraries=/usr/lib
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
 # remove duped documents
 rm -rf ${D}/usr/share/doc/speex*
 
 
}

PACKAGES = ""
PACKAGES += "speex"
PACKAGES += "libspeex"
PACKAGES += "libspeexdsp"
PACKAGES += "speex-devel"

speex_files = ""
speex_files += "speex.manifest"
speex_files += "/usr/bin/speex*"
speex_files += "/usr/share/man/man?/*"

libspeex_files = ""
libspeex_files += "speex.manifest"
libspeex_files += "/usr/lib/libspeex.so.*"

libspeexdsp_files = ""
libspeexdsp_files += "speex.manifest"
libspeexdsp_files += "/usr/lib/libspeexdsp.so.*"

speex-devel_files = ""
speex-devel_files += "speex.manifest"
speex-devel_files += "/usr/include/*"
speex-devel_files += "/usr/lib/lib*.so"
speex-devel_files += "/usr/lib/pkgconfig/*.pc"
speex-devel_files += "/usr/share/aclocal/*.m4"

FILES_${PN} = "${speex_files}"
FILES_lib${PN} = "${libspeex_files}"
FILES_lib${PN}dsp = "${libspeexdsp_files}"
FILES_${PN}-devel = "${speex-devel_files}"

PKG_speex= "speex"
PKG_libspeex= "libspeex"
PKG_libspeexdsp= "libspeexdsp"
PKG_speex-devel= "speex-devel"

require speex-extraconf.inc
