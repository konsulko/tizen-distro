DESCRIPTION = "Media thumbnail service Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmedia-thumbnail 
PROVIDES += "libmedia-thumbnail"
RPROVIDES_libmedia-thumbnail += "libmedia-thumbnail"

#PROVIDES by media-thumbnail-server 
PROVIDES += "media-thumbnail-server"
RPROVIDES_media-thumbnail-server += "media-thumbnail-server"

#PROVIDES by libmedia-thumbnail-devel 
PROVIDES += "libmedia-thumbnail-devel"
RPROVIDES_libmedia-thumbnail-devel += "libmedia-thumbnail-devel"
RPROVIDES_libmedia-thumbnail-devel += "libmedia-thumbnail-dev"

#PROVIDES by libmedia-thumbnail-test 
PROVIDES += "libmedia-thumbnail-test"
RPROVIDES_libmedia-thumbnail-test += "libmedia-thumbnail-test"

RDEPENDS = ""
#RDEPENDS of libmedia-thumbnail (${PN})
RDEPENDS_${PN} += "media-server"

#RDEPENDS of media-thumbnail-server (media-thumbnail-server)
RDEPENDS_media-thumbnail-server += "libmedia-thumbnail"

#RDEPENDS of libmedia-thumbnail-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmedia-thumbnail"

#RDEPENDS of libmedia-thumbnail-test (${PN}-test)
RDEPENDS_${PN}-test += "libmedia-thumbnail"


DEPENDS = ""
#DEPENDS of libmedia-thumbnail 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "drm-client"
DEPENDS += "pkgconfig(mm-fileinfo)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(libmedia-utils)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(mmutil-imgp)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "heynoti"
DEPENDS += "pkgconfig(mmutil-jpeg)"
DEPENDS += "ecore"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmedia-thumbnail.manifest ${S}/packaging/libmedia-thumbnail-devel.manifest ${S}/packaging/media-thumbnail-server.manifest .
 
 
 
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
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
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
PACKAGES += "libmedia-thumbnail"
PACKAGES += "media-thumbnail-server"
PACKAGES += "libmedia-thumbnail-devel"
PACKAGES += "libmedia-thumbnail-test"

libmedia-thumbnail_files = ""
libmedia-thumbnail_files += "libmedia-thumbnail.manifest"
libmedia-thumbnail_files += "/usr/lib/libmedia-thumbnail.so"
libmedia-thumbnail_files += "/usr/lib/libmedia-thumbnail.so.*"
libmedia-thumbnail_files += "/usr/lib/libmedia-hash.so"
libmedia-thumbnail_files += "/usr/lib/libmedia-hash.so.1"
libmedia-thumbnail_files += "/usr/lib/libmedia-hash.so.1.0.0"

media-thumbnail-server_files = ""
media-thumbnail-server_files += "media-thumbnail-server.manifest"
media-thumbnail-server_files += "/usr/bin/media-thumbnail-server"

libmedia-thumbnail-devel_files = ""
libmedia-thumbnail-devel_files += "libmedia-thumbnail-devel.manifest"
libmedia-thumbnail-devel_files += "/usr/lib/pkgconfig/media-thumbnail.pc"
libmedia-thumbnail-devel_files += "/usr/include/media-thumbnail/*.h"

libmedia-thumbnail-test_files = ""
libmedia-thumbnail-test_files += "/usr/bin/test-thumb"

FILES_${PN} = "${libmedia-thumbnail_files}"
FILES_media-thumbnail-server = "${media-thumbnail-server_files}"
FILES_${PN}-devel = "${libmedia-thumbnail-devel_files}"
FILES_${PN}-test = "${libmedia-thumbnail-test_files}"

PKG_libmedia-thumbnail= "libmedia-thumbnail"
PKG_media-thumbnail-server= "media-thumbnail-server"
PKG_libmedia-thumbnail-devel= "libmedia-thumbnail-devel"
PKG_libmedia-thumbnail-test= "libmedia-thumbnail-test"

require libmedia-thumbnail-extraconf.inc
