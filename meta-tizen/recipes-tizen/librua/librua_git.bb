require librua.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/librua;tag=cc94b25aa675fc061d456568f60fe56d536a540f;nobranch=1"

BBCLASSEXTEND = "native"

