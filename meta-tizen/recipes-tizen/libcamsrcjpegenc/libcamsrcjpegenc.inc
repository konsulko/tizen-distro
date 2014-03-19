DESCRIPTION = "camerasrc JPEG encoder Development library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "libdevel"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcamsrcjpegenc 
PROVIDES += "libcamsrcjpegenc"
RPROVIDES_libcamsrcjpegenc += "libcamsrcjpegenc"

#PROVIDES by libcamsrcjpegenc-devel 
PROVIDES += "libcamsrcjpegenc-devel"
RPROVIDES_libcamsrcjpegenc-devel += "libcamsrcjpegenc-devel"
RPROVIDES_libcamsrcjpegenc-devel += "libcamsrcjpegenc-dev"

RDEPENDS = ""
#RDEPENDS of libcamsrcjpegenc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcamsrcjpegenc"


DEPENDS = ""
#DEPENDS of libcamsrcjpegenc 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libcamsrcjpegenc-0.1.4
 cp ${S}/packaging/libcamsrcjpegenc.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --enable-dlog
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
 mkdir -p ${D}/usr/share/license
 cp LICENSE.APLv2 ${D}/usr/share/license/libcamsrcjpegenc
 
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
PACKAGES += "libcamsrcjpegenc"
PACKAGES += "libcamsrcjpegenc-devel"

libcamsrcjpegenc_files = ""
libcamsrcjpegenc_files += "libcamsrcjpegenc.manifest"
libcamsrcjpegenc_files += "/usr/lib/libcamsrcjpegenc.so.*"
libcamsrcjpegenc_files += "/usr/share/license/libcamsrcjpegenc"

libcamsrcjpegenc-devel_files = ""
libcamsrcjpegenc-devel_files += "libcamsrcjpegenc.manifest"
libcamsrcjpegenc-devel_files += "/usr/lib/libcamsrcjpegenc.so"
libcamsrcjpegenc-devel_files += "/usr/lib/pkgconfig/camsrcjpegenc.pc"
libcamsrcjpegenc-devel_files += "/usr/include/camsrcjpegenc.h"
libcamsrcjpegenc-devel_files += "/usr/include/camsrcjpegenc_sub.h"
libcamsrcjpegenc-devel_files += "/usr/include/camsrcjpegenc_type.h"

FILES_${PN} = "${libcamsrcjpegenc_files}"
FILES_${PN}-devel = "${libcamsrcjpegenc-devel_files}"

PKG_libcamsrcjpegenc= "libcamsrcjpegenc"
PKG_libcamsrcjpegenc-devel= "libcamsrcjpegenc-devel"

require libcamsrcjpegenc-extraconf.inc
