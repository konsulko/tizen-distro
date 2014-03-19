DESCRIPTION = "The Vorbis General Audio Compression Codec"
HOMEPAGE = "http://www.vorbis.com/"
SECTION = "Multimedia/Audio"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libvorbis 
PROVIDES += "libvorbis"
RPROVIDES_libvorbis += "libvorbis"

#PROVIDES by libvorbis-devel 
PROVIDES += "libvorbis-devel"
RPROVIDES_libvorbis-devel += "libvorbis-devel"
RPROVIDES_libvorbis-devel += "libvorbis-dev"

#PROVIDES by libvorbisenc 
PROVIDES += "libvorbisenc"
RPROVIDES_libvorbisenc += "libvorbisenc"

#PROVIDES by libvorbisfile 
PROVIDES += "libvorbisfile"
RPROVIDES_libvorbisfile += "libvorbisfile"

RDEPENDS = ""
#RDEPENDS of libvorbis-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libvorbis"
RDEPENDS_${PN}-devel += "libvorbisenc"
RDEPENDS_${PN}-devel += "libvorbisfile"
RDEPENDS_${PN}-devel += "libogg-dev"


DEPENDS = ""
#DEPENDS of libvorbis 
DEPENDS += "libtool-cross"
DEPENDS += "fdupes-native"
DEPENDS += "libogg"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libvorbis.manifest .
 
 
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
 
 # Fix optimization level
 sed -i s,-O20,-O3,g configure.ac
 
 autoreconf -fiv
 
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
         --infodir=/usr/share/info --disable-examples --disable-static
 make -j16
 
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
 mkdir -p ${D}/usr/share/doc/packages/libvorbis
 mv ${D}/usr/share/doc/libvorbis-* ${D}/usr/share/doc/packages/libvorbis
 install -c -m 0644 doc/Vorbis_I_spec.* ${D}/usr/share/doc/packages/libvorbis
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/libvorbis 
   rm -rf ${D}/usr/share/doc/libvorbis-1.3.3 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libvorbis"
PACKAGES += "libvorbis-devel"
PACKAGES += "libvorbisenc"
PACKAGES += "libvorbisfile"

libvorbis_files = ""
libvorbis_files += "libvorbis.manifest"
libvorbis_files += "/usr/lib/libvorbis.so.0*"

libvorbis-devel_files = ""
libvorbis-devel_files += "libvorbis.manifest"
libvorbis-devel_files += "/usr/share/aclocal/*.m4"
libvorbis-devel_files += "/usr/include/vorbis"
libvorbis-devel_files += "/usr/lib/lib*.so"
libvorbis-devel_files += "/usr/lib/pkgconfig/*.pc"

libvorbisenc_files = ""
libvorbisenc_files += "libvorbis.manifest"
libvorbisenc_files += "/usr/lib/libvorbisenc.so.2*"

libvorbisfile_files = ""
libvorbisfile_files += "libvorbis.manifest"
libvorbisfile_files += "/usr/lib/libvorbisfile.so.3*"

FILES_${PN} = "${libvorbis_files}"
FILES_${PN}-devel = "${libvorbis-devel_files}"
FILES_${PN}enc = "${libvorbisenc_files}"
FILES_${PN}file = "${libvorbisfile_files}"

PKG_libvorbis= "libvorbis"
PKG_libvorbis-devel= "libvorbis-devel"
PKG_libvorbisenc= "libvorbisenc"
PKG_libvorbisfile= "libvorbisfile"

require libvorbis-extraconf.inc
