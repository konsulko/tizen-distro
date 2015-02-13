require capi-system-device.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/device;tag=b3d72a64ca39fef39127aeb040f370c9e2798c2e;nobranch=1"

BBCLASSEXTEND += " native "

