DESCRIPTION = "Multimedia Framework Camera Src Jpeg Encoder Library (libjpeg)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "libdevel"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcamsrcjpegenc-sw-libjpeg 
PROVIDES += "libcamsrcjpegenc-sw-libjpeg"
RPROVIDES_libcamsrcjpegenc-sw-libjpeg += "libcamsrcjpegenc-sw-libjpeg"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of libcamsrcjpegenc-sw-libjpeg 
DEPENDS += "libcamsrcjpegenc"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libjpeg-turbo-devel"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(mmutil-imgp)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libcamsrcjpegenc-sw-libjpeg-0.1.6
 cp ${S}/packaging/libcamsrcjpegenc-sw-libjpeg.manifest .
 
 
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
 cp LICENSE.APLv2 ${D}/usr/share/license/libcamsrcjpegenc-sw-libjpeg
 
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
PACKAGES += "libcamsrcjpegenc-sw-libjpeg"

libcamsrcjpegenc-sw-libjpeg_files = ""
libcamsrcjpegenc-sw-libjpeg_files += "libcamsrcjpegenc-sw-libjpeg.manifest"
libcamsrcjpegenc-sw-libjpeg_files += "/usr/lib/libcamsrcjpegenc-sw.so*"
libcamsrcjpegenc-sw-libjpeg_files += "/usr/share/license/libcamsrcjpegenc-sw-libjpeg"

FILES_${PN} = "${libcamsrcjpegenc-sw-libjpeg_files}"

PKG_libcamsrcjpegenc-sw-libjpeg= "libcamsrcjpegenc-sw-libjpeg"

require libcamsrcjpegenc-sw-libjpeg-extraconf.inc
