require wayland-ivi-extension.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/wayland-ivi-extension;tag=38accb3b08d2e4c0f4669aaca658470d56a97bd2;nobranch=1"

BBCLASSEXTEND += " native "

