require genivi-shell.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/wayland-ivi-extension;tag=fd633eb0761da7a0be4bc1f920f62b5bb6dfe639;nobranch=1"

BBCLASSEXTEND += " native "

