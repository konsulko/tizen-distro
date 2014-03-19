DESCRIPTION = "Text To Speech client library and daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "libs"
LICENSE = "Samsung"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tts 
PROVIDES += "tts"
RPROVIDES_tts += "tts"

#PROVIDES by tts-devel 
PROVIDES += "tts-devel"
RPROVIDES_tts-devel += "tts-devel"
RPROVIDES_tts-devel += "tts-dev"

RDEPENDS = ""
#RDEPENDS of tts (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of tts-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "tts"


DEPENDS = ""
#DEPENDS of tts 
DEPENDS += "pkgconfig(vconf-internal-keys)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "libmm-common"
DEPENDS += "dlog"
DEPENDS += "libmm-session"
DEPENDS += "pkgconfig(capi-system-runtime-info)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(mm-player)"
DEPENDS += "pkgconfig(ecore-file)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n tts-0.1.60
 cp ${S}/packaging/tts.manifest ${S}/packaging/tts-devel.manifest .
 
 
 
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
 mkdir -p ${D}/usr/share/license
 
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
PACKAGES += "tts"
PACKAGES += "tts-devel"

tts_files = ""
tts_files += "tts.manifest"
tts_files += "/etc/config/sysinfo-tts.xml"
tts_files += "/usr/lib/lib*.so"
tts_files += "/usr/lib/voice/tts/1.0/ttsd.conf"
tts_files += "/usr/bin/tts-daemon*"
tts_files += "/usr/share/license/*"

tts-devel_files = ""
tts-devel_files += "tts-devel.manifest"
tts-devel_files += "/usr/lib/pkgconfig/tts.pc"
tts-devel_files += "/usr/lib/pkgconfig/tts-setting.pc"
tts-devel_files += "/usr/include/tts.h"
tts-devel_files += "/usr/include/tts_setting.h"
tts-devel_files += "/usr/include/ttsp.h"

FILES_${PN} = "${tts_files}"
FILES_${PN}-devel = "${tts-devel_files}"

PKG_tts= "tts"
PKG_tts-devel= "tts-devel"

require tts-extraconf.inc
