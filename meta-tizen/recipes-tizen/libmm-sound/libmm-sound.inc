DESCRIPTION = "MMSound Package contains client lib and sound_server binary"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmm-sound-devel 
PROVIDES += "libmm-sound-devel"
RPROVIDES_libmm-sound-devel += "libmm-sound-devel"
RPROVIDES_libmm-sound-devel += "libmm-sound-dev"

#PROVIDES by libmm-sound 
PROVIDES += "libmm-sound"
RPROVIDES_libmm-sound += "libmm-sound"

#PROVIDES by libmm-sound-tool 
PROVIDES += "libmm-sound-tool"
RPROVIDES_libmm-sound-tool += "libmm-sound-tool"

#PROVIDES by libmm-sound-sdk-devel 
PROVIDES += "libmm-sound-sdk-devel"
RPROVIDES_libmm-sound-sdk-devel += "libmm-sound-sdk-devel"
RPROVIDES_libmm-sound-sdk-devel += "libmm-sound-sdk-dev"

RDEPENDS = ""
#RDEPENDS of libmm-sound-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmm-sound"

#RDEPENDS of libmm-sound-sdk-devel (${PN}-sdk-devel)
RDEPENDS_${PN}-sdk-devel += "libmm-sound-dev"

#RDEPENDS of libmm-sound-tool (${PN}-tool)
RDEPENDS_${PN}-tool += "libmm-sound"

#RDEPENDS of libmm-sound (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of libmm-sound 
DEPENDS += "pkgconfig(avsystem)"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "libmm-log"
DEPENDS += "audio-session-manager"
DEPENDS += "libmm-common"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "heynoti"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libmm-session"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-sound.manifest .
 
 
 
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fvisibility=hidden -DMM_DEBUG_FLAG -DSEPARATE_SPEAKER_AND_WIRED_ACCESSORY -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\""; export CFLAGS
 
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
         --infodir=/usr/share/info --prefix=/usr --enable-pulse --enable-security
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
 install -d ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m0644 ${S}/packaging/sound-server.service ${D}/usr/lib/systemd/system/
 install -m0644 ${S}/packaging/sound-server.path ${D}/usr/lib/systemd/system/
 ln -sf ../sound-server.path ${D}/usr/lib/systemd/system/multi-user.target.wants/sound-server.path
 
 # FIXME: remove after systemd is in
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc4.d
 mkdir -p ${D}/etc/rc.d/rc5.d
 ln -s /etc/rc.d/init.d/soundserver ${D}/etc/rc.d/rc3.d/S23soundserver
 ln -s /etc/rc.d/init.d/soundserver ${D}/etc/rc.d/rc4.d/S23soundserver
 
 
 
 
}

PACKAGES = ""
PACKAGES += "libmm-sound-devel"
PACKAGES += "libmm-sound"
PACKAGES += "libmm-sound-tool"
PACKAGES += "libmm-sound-sdk-devel"

libmm-sound-devel_files = ""
libmm-sound-devel_files += "libmm-sound.manifest"
libmm-sound-devel_files += "/usr/lib/libmmfkeysound.so"
libmm-sound-devel_files += "/usr/lib/libmmfsound.so"
libmm-sound-devel_files += "/usr/lib/libmmfsoundcommon.so"
libmm-sound-devel_files += "/usr/include/mmf/mm_sound_private.h"
libmm-sound-devel_files += "/usr/include/mmf/mm_sound_plugin.h"
libmm-sound-devel_files += "/usr/include/mmf/mm_sound_plugin_hal.h"

libmm-sound_files = ""
libmm-sound_files += "libmm-sound.manifest"
libmm-sound_files += "/usr/bin/sound_server"
libmm-sound_files += "/usr/lib/libmmfsound.so.*"
libmm-sound_files += "/usr/lib/libmmfsoundcommon.so.*"
libmm-sound_files += "/usr/lib/libmmfkeysound.so.*"
libmm-sound_files += "/usr/lib/libsoundplugintone.so*"
libmm-sound_files += "/usr/lib/libsoundpluginwave.so*"
libmm-sound_files += "/usr/lib/libsoundpluginkeytone.so*"
libmm-sound_files += "/usr/lib/soundplugins/libsoundplugintone.so"
libmm-sound_files += "/usr/lib/soundplugins/libsoundpluginwave.so"
libmm-sound_files += "/usr/lib/soundplugins/libsoundpluginkeytone.so"
libmm-sound_files += "/etc/rc.d/rc3.d/S23soundserver"
libmm-sound_files += "/etc/rc.d/rc4.d/S23soundserver"
libmm-sound_files += "/usr/share/sounds/sound-server/*"
libmm-sound_files += "/usr/lib/systemd/system/multi-user.target.wants/sound-server.path"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.service"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.path"

libmm-sound-tool_files = ""
libmm-sound-tool_files += "libmm-sound.manifest"
libmm-sound-tool_files += "/usr/bin/mm_sound_testsuite"

libmm-sound-sdk-devel_files = ""
libmm-sound-sdk-devel_files += "libmm-sound.manifest"
libmm-sound-sdk-devel_files += "/usr/include/mmf/mm_sound.h"
libmm-sound-sdk-devel_files += "/usr/lib/pkgconfig/mm-keysound.pc"
libmm-sound-sdk-devel_files += "/usr/lib/pkgconfig/mm-sound.pc"

FILES_${PN}-devel = "${libmm-sound-devel_files}"
FILES_${PN} = "${libmm-sound_files}"
FILES_${PN}-tool = "${libmm-sound-tool_files}"
FILES_${PN}-sdk-devel = "${libmm-sound-sdk-devel_files}"

PKG_libmm-sound-devel= "libmm-sound-devel"
PKG_libmm-sound= "libmm-sound"
PKG_libmm-sound-tool= "libmm-sound-tool"
PKG_libmm-sound-sdk-devel= "libmm-sound-sdk-devel"

require libmm-sound-extraconf.inc
