
do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 ./autogen.sh
 CFLAGS="-DMM_DEBUG_FLAG -DSEPARATE_SPEAKER_AND_WIRED_ACCESSORY -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\""; export CFLAGS
 
   autoreconf -v --install --force  
   ./configure --host=${HOST_SYS} \
         --prefix=${prefix} --enable-pulse --enable-security
 oe_runmake ${PARALLEL_MAKE}

}

libmm-sound-dev_files = ""
libmm-sound-dev_files += "libmm-sound.manifest"
libmm-sound-dev_files += "${prefix}/lib/libmmfkeysound.so"
libmm-sound-dev_files += "${prefix}/lib/libmmfsound.so"
libmm-sound-dev_files += "${prefix}/lib/libmmfsoundcommon.so"
libmm-sound-dev_files += "${prefix}/lib/libsoundpluginwave.so"
libmm-sound-dev_files += "${prefix}/lib/libsoundpluginkeytone.so"
libmm-sound-dev_files += "${prefix}/lib/libsoundplugintone.so"
libmm-sound-dev_files += "${prefix}/lib/soundplugins/libsoundplugintone.so"
libmm-sound-dev_files += "${prefix}/lib/soundplugins/libsoundpluginwave.so"
libmm-sound-dev_files += "${prefix}/lib/soundplugins/libsoundpluginkeytone.so"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_private.h"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_plugin.h"
libmm-sound-dev_files += "${prefix}/include/mmf/mm_sound_plugin_hal.h"

libmm-sound_files = ""
libmm-sound_files += "libmm-sound.manifest"
libmm-sound_files += "${prefix}/bin/sound_server"
libmm-sound_files += "${prefix}/lib/libmmfsound.so.*"
libmm-sound_files += "${prefix}/lib/libmmfsoundcommon.so.*"
libmm-sound_files += "${prefix}/lib/libmmfkeysound.so.*"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundplugintone.so.*"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundpluginwave.so.*"
libmm-sound_files += "${prefix}/lib/soundplugins/libsoundpluginkeytone.so.*"
libmm-sound_files += "${prefix}/lib/libsoundplugintone.so.*"
libmm-sound_files += "${prefix}/lib/libsoundpluginwave.so.*"
libmm-sound_files += "${prefix}/lib/libsoundpluginkeytone.so.*"
libmm-sound_files += "${sysconfdir}/rc.d/init.d/soundserver"
libmm-sound_files += "${sysconfdir}/rc.d/rc5.d"
libmm-sound_files += "${sysconfdir}/rc.d/rc3.d/S23soundserver"
libmm-sound_files += "${sysconfdir}/rc.d/rc4.d/S23soundserver"
libmm-sound_files += "/usr/share/sounds/sound-server/*"
libmm-sound_files += "/usr/lib/systemd/system/multi-user.target.wants/sound-server.path"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.service"
libmm-sound_files += "/usr/lib/systemd/system/sound-server.path"

FILES_${PN}-dev = "${libmm-sound-dev_files}"
FILES_${PN} = "${libmm-sound_files}"

PKG_libmm-sound-dev= "libmm-sound-dev"
PKG_libmm-sound= "libmm-sound"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    vconftool set -t int memory/Sound/ASMReady 0 -g 29 -f -i
    vconftool set -t int file/private/sound/volume/system 5 -g 29 -f
    vconftool set -t int file/private/sound/volume/notification 7 -g 29 -f
    vconftool set -t int file/private/sound/volume/alarm 7 -g 29 -f
    vconftool set -t int file/private/sound/volume/ringtone 13 -g 29 -f
    vconftool set -t int file/private/sound/volume/media 7 -g 29 -f
    vconftool set -t int file/private/sound/volume/call 7 -g 29 -f
    vconftool set -t int file/private/sound/volume/voip 7 -g 29 -f
    vconftool set -t int file/private/sound/volume/fixed 0 -g 29 -f
    vconftool set -t int file/private/sound/volume/java 11 -g 29 -f

}