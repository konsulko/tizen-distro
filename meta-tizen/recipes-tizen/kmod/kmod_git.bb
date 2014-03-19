require kmod.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/kmod;protocol=ssh;tag=4dbc9bf5e38ddbc103b14142ba91377a1b393679;nobranch=1"

