require genivi-shell.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/wayland-ivi-extension;tag=06b52cbfdfa6da7cfd0103918da801199fd4bc4b;nobranch=1"

BBCLASSEXTEND += " native "

