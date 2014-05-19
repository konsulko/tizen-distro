SRC_URI += "file://add-subdir-objects-option.patch"
SRC_URI += "file://add-PA_PROP_MEDIA_POLICY-Define.patch"




do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
    autoreconf -v --install --force
    ./configure --host=${HOST_SYS}
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autoreconf -v --install --force
   ./configure --host=${HOST_SYS} \
	--enable-audiotest
 make -j16
 
 
 
}
#PACKAGES += "avsystem-dbg"

#avsystem-dbg_files = ""
#avsystem-dbg_files += "avsystem.manifest"
avsystem-dbg_files += "${prefix}/local/bin/.debug"
avsystem-dbg_files += "${prefix}/local/bin/.debug/*"
avsystem-dbg_files += "${prefix}/local/lib/.debug/*.so.*"


avsystem-dev_files = ""
avsystem-dev_files += "avsystem.manifest"
avsystem-dev_files += "${prefix}/local/lib/pkgconfig/*.pc"
avsystem-dev_files += "${prefix}/local/lib/*.so"
avsystem-dev_files += "${prefix}/local/include/avsystem/*.h"


libavsysaudio_files = ""
libavsysaudio_files += "avsystem.manifest"
libavsysaudio_files += "${prefix}/local/lib/lib*.so.*"
libavsysaudio_files += "${prefix}/local/bin/sound_initializer"
libavsysaudio_files += "${prefix}/local/bin/avsys_volume_dump"
libavsysaudio_files += "${prefix}/local/bin/avsys_audio_test"

FILES_${PN} = "${avsystem_files}"
FILES_${PN}-dbg += "${avsystem-dbg_files}"
FILES_${PN}-dev = "${avsystem-dev_files}"
FILES_libavsysaudio = "${libavsysaudio_files}"

PKG_avsystem= "avsystem"
PKG_avsystem-dev= "avsystem-dev"
PKG_avsystem-dbg = "avsystem-dbg"
PKG_libavsysaudio= "libavsysaudio"

