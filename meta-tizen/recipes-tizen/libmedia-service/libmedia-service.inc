DESCRIPTION = "Media information service library for multimedia applications"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmedia-service-devel 
PROVIDES += "libmedia-service-devel"
RPROVIDES_libmedia-service-devel += "libmedia-service-devel"
RPROVIDES_libmedia-service-devel += "libmedia-service-dev"

#PROVIDES by libmedia-service 
PROVIDES += "libmedia-service"
RPROVIDES_libmedia-service += "libmedia-service"

RDEPENDS = ""
#RDEPENDS of libmedia-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmedia-service"

#RDEPENDS of libmedia-service (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of libmedia-service 
DEPENDS += "cmake"
DEPENDS += "drm-client"
DEPENDS += "pkgconfig(mm-fileinfo)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(libmedia-utils)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(media-thumbnail)"
DEPENDS += "pkgconfig(mm-common)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(db-util)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/libmedia-service.manifest .
 
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 #License
 mkdir -p ${D}//usr/share/license
 cp -rf ${WORKDIR}/libmedia-service-0.2.43/LICENSE ${D}//usr/share/license/libmedia-service
 
 
}

PACKAGES = ""
PACKAGES += "libmedia-service-devel"
PACKAGES += "libmedia-service"

libmedia-service-devel_files = ""
libmedia-service-devel_files += "libmedia-service.manifest"
libmedia-service-devel_files += "/usr/lib/pkgconfig/libmedia-service.pc"
libmedia-service-devel_files += "/usr/include/media-service/*.h"

libmedia-service_files = ""
libmedia-service_files += "libmedia-service.manifest"
libmedia-service_files += "/usr/lib/libmedia-service.so"
libmedia-service_files += "/usr/lib/libmedia-service.so.1"
libmedia-service_files += "/usr/lib/libmedia-service.so.1.0.0"
libmedia-service_files += "/usr/lib/libmedia-svc-hash.so"
libmedia-service_files += "/usr/lib/libmedia-svc-hash.so.1"
libmedia-service_files += "/usr/lib/libmedia-svc-hash.so.1.0.0"
libmedia-service_files += "/usr/lib/libmedia-content-plugin.so"
libmedia-service_files += "/usr/lib/libmedia-content-plugin.so.1"
libmedia-service_files += "/usr/lib/libmedia-content-plugin.so.1.0.0"
libmedia-service_files += "/usr/share/license/libmedia-service"

FILES_${PN}-devel = "${libmedia-service-devel_files}"
FILES_${PN} = "${libmedia-service_files}"

PKG_libmedia-service-devel= "libmedia-service-devel"
PKG_libmedia-service= "libmedia-service"

require libmedia-service-extraconf.inc
