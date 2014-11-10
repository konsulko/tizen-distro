SRC_URI += "file://add-subdir-objects-option.patch"
SRC_URI += "file://add-PA_PROP_MEDIA_POLICY-Define.patch"

avsystem-dbg_files += "${prefix}/local/bin/.debug"
avsystem-dbg_files += "${prefix}/local/bin/.debug/*"
avsystem-dbg_files += "${prefix}/lib/.debug/*.so.*"

avsystem-dev_files = ""
avsystem-dev_files += "avsystem.manifest"
avsystem-dev_files += "${prefix}/lib/pkgconfig/*.pc"
avsystem-dev_files += "${prefix}/lib/*.so"
avsystem-dev_files += "${prefix}/include/avsystem/*.h"

libavsysaudio_files = ""
libavsysaudio_files += "avsystem.manifest"
libavsysaudio_files += "${prefix}/lib/lib*.so.*"
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

