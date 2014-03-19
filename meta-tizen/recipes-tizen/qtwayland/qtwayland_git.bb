require qtwayland.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtwayland;protocol=ssh;tag=ce73ccf54ff9bd5dbba9289d2eb4ebbea8002549;nobranch=1"

