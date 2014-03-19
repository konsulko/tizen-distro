require augeas.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/augeas;protocol=ssh;tag=f50575830835888c0065a423cbf5b92347fc47da;nobranch=1"

