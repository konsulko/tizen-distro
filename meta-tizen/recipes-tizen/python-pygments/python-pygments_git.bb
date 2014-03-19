require python-pygments.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-pygments;protocol=ssh;tag=4c0f547ab0e94189f9b44a053abf0819984c629b;nobranch=1"

