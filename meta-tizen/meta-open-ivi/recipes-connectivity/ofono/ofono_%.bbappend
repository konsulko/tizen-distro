# Enable handsfree audio agent oFono backend required by PulseAudio

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "file://0001-ofono.conf-Enable-Handsfree-Audio-Agent.patch"

RDEPENDS_${PN} += "pulseaudio"
