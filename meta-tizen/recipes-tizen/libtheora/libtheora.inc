DESCRIPTION = "Free Video Codec"
HOMEPAGE = "http://www.theora.org/"
SECTION = "Multimedia/Video"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtheora-devel 
PROVIDES += "libtheora-devel"
RPROVIDES_libtheora-devel += "libtheora-devel"
RPROVIDES_libtheora-devel += "libtheora-dev"

#PROVIDES by libtheora 
PROVIDES += "libtheora"
RPROVIDES_libtheora += "libtheora"

RDEPENDS = ""
#RDEPENDS of libtheora-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libtheora"
RDEPENDS_${PN}-devel += "libogg-dev"


DEPENDS = ""
#DEPENDS of libtheora 
DEPENDS += "gcc-cross"
inherit pythonnative
DEPENDS += "libvorbis-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "libtool-cross"
DEPENDS += "libogg"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libtheora-1.1.1
 cp ${S}/packaging/libtheora.manifest .
 
 
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
 
 ACLOCAL="aclocal -I m4" autoreconf -f -i
 
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
         --infodir=/usr/share/info --disable-examples \
     --disable-static \
     --with-pic
 make -j16 docdir=/usr/share/doc/packages/libtheora
 
 exit 0
 make check
 
 
 
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
 install -d ${D}/usr/bin
 
 rm -rf ${D}//usr/share/doc/libtheora-1.1.1/*
 
 
}

PACKAGES = ""
PACKAGES += "libtheora-devel"
PACKAGES += "libtheora"

libtheora-devel_files = ""
libtheora-devel_files += "libtheora.manifest"
libtheora-devel_files += "/usr/include/theora"
libtheora-devel_files += "/usr/lib/*.so"
libtheora-devel_files += "/usr/lib/pkgconfig/theoradec.pc"
libtheora-devel_files += "/usr/lib/pkgconfig/theoraenc.pc"
libtheora-devel_files += "/usr/lib/pkgconfig/theora.pc"

libtheora_files = ""
libtheora_files += "libtheora.manifest"
libtheora_files += "COPYING LICENSE"
libtheora_files += "/usr/lib/libtheora.so.0*"
libtheora_files += "/usr/lib/libtheoradec.so.1*"
libtheora_files += "/usr/lib/libtheoraenc.so.1*"

FILES_${PN}-devel = "${libtheora-devel_files}"
FILES_${PN} = "${libtheora_files}"

PKG_libtheora-devel= "libtheora-devel"
PKG_libtheora= "libtheora"

require libtheora-extraconf.inc
