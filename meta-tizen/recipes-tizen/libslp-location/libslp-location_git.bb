require libslp-location.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/location/libslp-location;tag=165868e3ca2d034e4eec9d285e6531c1cc018738;nobranch=1"

BBCLASSEXTEND = "native"

