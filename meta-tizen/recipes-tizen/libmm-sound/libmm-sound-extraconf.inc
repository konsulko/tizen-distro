
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
   autoreconf -v --install --force  
   ./configure --host=${HOST_SYS} \
         --prefix=${prefix} --enable-pulse --enable-security
 make -j16

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
