require wayland-ivi-extension.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/wayland-ivi-extension;tag=3b85503152f78b98a1edb0381984966638156482;nobranch=1"

BBCLASSEXTEND += " native "

B="${S}"