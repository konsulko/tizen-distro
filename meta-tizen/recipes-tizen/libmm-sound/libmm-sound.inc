DESCRIPTION = "MMSound Package contains client lib and sound_server binary"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by libmm-sound-dev 


#PROVIDES by libmm-sound 


#PROVIDES by libmm-sound-tool 


#PROVIDES by libmm-sound-sdk-dev 


RDEPENDS = ""
#RDEPENDS of libmm-sound-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libmm-sound"

#RDEPENDS of libmm-sound-sdk-dev (${PN}-sdk-dev)
RDEPENDS_${PN}-sdk-dev += "libmm-sound-dev"

#RDEPENDS of libmm-sound-tool (${PN}-tool)
RDEPENDS_${PN}-tool += "libmm-sound"

#RDEPENDS of libmm-sound (${PN})
RDEPENDS_${PN} += "eglibc"
RDEPENDS_${PN} += "vconf"


DEPENDS = ""
#DEPENDS of libmm-sound 
DEPENDS += "avsystem"
DEPENDS += "libmm-common"
DEPENDS += "audio-session-manager"
DEPENDS += "libmm-log"
DEPENDS += "security-server"
DEPENDS += "glib-2.0"
DEPENDS += "vconf"
DEPENDS += "libslp-sysman"
DEPENDS += "heynoti"
DEPENDS += "libmm-session"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-sound.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --prefix=/usr --enable-pulse --enable-security
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -d ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m0644 ${S}/packaging/sound-server.service ${D}/usr/lib/systemd/system/
 install -m0644 ${S}/packaging/sound-server.path ${D}/usr/lib/systemd/system/
 ln -sf ../sound-server.path ${D}/usr/lib/systemd/system/multi-user.target.wants/sound-server.path
 
 # FIXME: remove after systemd is in
 mkdir -p ${D}${sysconfdir}/rc.d/rc3.d
 mkdir -p ${D}${sysconfdir}/rc.d/rc4.d
 mkdir -p ${D}${sysconfdir}/rc.d/rc5.d
 ln -s ${sysconfdir}/rc.d/init.d/soundserver ${D}${sysconfdir}/rc.d/rc3.d/S23soundserver
 ln -s ${sysconfdir}/rc.d/init.d/soundserver ${D}${sysconfdir}/rc.d/rc4.d/S23soundserver
 
 
 
 
}

PACKAGES += " libmm-sound-tool "
PACKAGES += " libmm-sound-sdk-dev "

libmm-sound-dev_files = ""
libmm-sound-dev_files += "libmm-sound.manifest"
libmm-sound-dev_files += "${prefix}/lib/libmmfkeysound.so"
libmm-sound-dev_files += "${prefix}/lib/libmmfsound.so"
libmm-sound-dev_files += "${prefix}/lib/libmmfsoundcommon.so"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_private.h"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_plugin.h"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_plugin_hal.h"

libmm-sound_files = ""
libmm-sound_files += "libmm-sound.manifest"
libmm-sound_files += "${prefix}/bin/sound_server"
libmm-sound_files += "${prefix}/lib/libmmfsound.so.*"
libmm-sound_files += "${prefix}/lib/libmmfsoundcommon.so.*"
libmm-sound_files += "${prefix}/lib/libmmfkeysound.so.*"
libmm-sound_files += "${prefix}/lib/libsoundplugintone.so*"
libmm-sound_files += "${prefix}/lib/libsoundpluginwave.so*"
libmm-sound_files += "${prefix}/lib/libsoundpluginkeytone.so*"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundplugintone.so"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundpluginwave.so"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundpluginkeytone.so"
libmm-sound_files += "${sysconfdir}/rc.d/init.d/soundserver"
libmm-sound_files += "${sysconfdir}/rc.d/rc3.d/S23soundserver"
libmm-sound_files += "${sysconfdir}/rc.d/rc4.d/S23soundserver"
libmm-sound_files += "/usr/share/sounds/sound-server/*"
libmm-sound_files += "/usr/lib/systemd/system/multi-user.target.wants/sound-server.path"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.service"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.path"

libmm-sound-tool_files = ""
libmm-sound-tool_files += "libmm-sound.manifest"
libmm-sound-tool_files += "${prefix}/bin/mm_sound_testsuite"

libmm-sound-sdk-dev_files = ""
libmm-sound-sdk-dev_files += "libmm-sound.manifest"
libmm-sound-sdk-dev_files += "${prefix}/include/mmf/mm_sound.h"
libmm-sound-sdk-dev_files += "${prefix}/lib/pkgconfig/mm-keysound.pc"
libmm-sound-sdk-dev_files += "${prefix}/lib/pkgconfig/mm-sound.pc"

FILES_${PN}-dev = "${libmm-sound-dev_files}"
FILES_${PN} = "${libmm-sound_files}"
FILES_${PN}-tool = "${libmm-sound-tool_files}"
FILES_${PN}-sdk-dev = "${libmm-sound-sdk-dev_files}"

PKG_libmm-sound-dev= "libmm-sound-dev"
PKG_libmm-sound= "libmm-sound"
PKG_libmm-sound-tool= "libmm-sound-tool"
PKG_libmm-sound-sdk-dev= "libmm-sound-sdk-dev"

require libmm-sound-extraconf.inc

