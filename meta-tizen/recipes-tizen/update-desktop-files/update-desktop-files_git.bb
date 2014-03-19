require update-desktop-files.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/update-desktop-files;protocol=ssh;tag=0712f9c0f8b5baffbe82ae63fc0fb8efc4078844;nobranch=1"

