FILESEXTRAPATHS_prepend := "${THISDIR}/pulseaudio_5.0"

SRC_URI += "file://change_libsystemd_to_libsystemd-login_in_configure.patch"
SRC_URI += "file://changes-to-pa-simple-api-samsung.patch"
