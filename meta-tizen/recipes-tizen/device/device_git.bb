require device.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/device;tag=cc0fd4686ca93c08be80db52b4655ebc24ec0814;nobranch=1"

BBCLASSEXTEND += " native "

