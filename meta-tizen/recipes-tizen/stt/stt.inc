DESCRIPTION = "Speech To Text client library and daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "UI Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by stt 
PROVIDES += "stt"
RPROVIDES_stt += "stt"

#PROVIDES by stt-devel 
PROVIDES += "stt-devel"
RPROVIDES_stt-devel += "stt-devel"
RPROVIDES_stt-devel += "stt-dev"

RDEPENDS = ""
#RDEPENDS of stt-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "stt"


DEPENDS = ""
#DEPENDS of stt 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(capi-media-audio-io)"
DEPENDS += "pkgconfig(ecore-file)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(capi-media-sound-manager)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/stt.manifest ${S}/packaging/stt-devel.manifest .
 
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "stt"
PACKAGES += "stt-devel"

stt_files = ""
stt_files += "stt.manifest"
stt_files += "/etc/config/sysinfo-stt.xml"
stt_files += "/usr/lib/libstt.so"
stt_files += "/usr/lib/libstt_setting.so"
stt_files += "/usr/lib/voice/stt/1.0/sttd.conf"
stt_files += "/usr/bin/stt-daemon"

stt-devel_files = ""
stt-devel_files += "stt-devel.manifest"
stt-devel_files += "/usr/lib/pkgconfig/stt.pc"
stt-devel_files += "/usr/lib/pkgconfig/stt-setting.pc"
stt-devel_files += "/usr/include/stt.h"
stt-devel_files += "/usr/include/stt_setting.h"
stt-devel_files += "/usr/include/sttp.h"

FILES_${PN} = "${stt_files}"
FILES_${PN}-devel = "${stt-devel_files}"

PKG_stt= "stt"
PKG_stt-devel= "stt-devel"

require stt-extraconf.inc
