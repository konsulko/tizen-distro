require v4l-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/v4l-utils;protocol=ssh;tag=9e9479b7191e3ca64026aa67add29c260c17a83e;nobranch=1"

