DESCRIPTION = "C library for reading and writing sound files"
HOMEPAGE = "http://www.mega-nerd.com/libsndfile/"
SECTION = "Multimedia/Audio"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsndfile 
PROVIDES += "libsndfile"
RPROVIDES_libsndfile += "libsndfile"

#PROVIDES by libsndfile-devel 
PROVIDES += "libsndfile-devel"
RPROVIDES_libsndfile-devel += "libsndfile-devel"
RPROVIDES_libsndfile-devel += "libsndfile-dev"

RDEPENDS = ""
#RDEPENDS of libsndfile-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libsndfile"
RDEPENDS_${PN}-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of libsndfile 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "sqlite-devel"
DEPENDS += "libvorbis-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "speex-devel"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libsndfile.manifest .
 
 
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -W -Wall -Wstrict-prototypes -Wpointer-arith -Wno-unused-parameter"
 export CFLAGS
 
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
         --infodir=/usr/share/info --disable-silent-rules \
 	--disable-static \
     --enable-sqlite \
 	--with-pic \
     --enable-experimental
 make -j16
 
 exit 0
 pushd src
 make check
 popd
 
 
 
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
 # remove programs; built in another spec file
 rm -rf ${D}/usr/bin
 rm -rf ${D}/usr/share/man/man1
 # remove binaries from examples directory
 make -C examples distclean
 rm -rf ${D}/usr/share/doc/libsndfile1-dev
 
 
}

PACKAGES = ""
PACKAGES += "libsndfile"
PACKAGES += "libsndfile-devel"

libsndfile_files = ""
libsndfile_files += "libsndfile.manifest"
libsndfile_files += "/usr/lib/libsndfile.so.1*"

libsndfile-devel_files = ""
libsndfile-devel_files += "libsndfile.manifest"
libsndfile-devel_files += "/usr/lib/libsndfile.so"
libsndfile-devel_files += "/usr/include/sndfile.h"
libsndfile-devel_files += "/usr/include/sndfile.hh"
libsndfile-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libsndfile_files}"
FILES_${PN}-devel = "${libsndfile-devel_files}"

PKG_libsndfile= "libsndfile"
PKG_libsndfile-devel= "libsndfile-devel"

require libsndfile-extraconf.inc
