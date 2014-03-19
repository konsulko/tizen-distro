require squashfs.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/squashfs;protocol=ssh;tag=c06efd7649f50d77ad9b0e21d22416d2f383b6c6;nobranch=1"

