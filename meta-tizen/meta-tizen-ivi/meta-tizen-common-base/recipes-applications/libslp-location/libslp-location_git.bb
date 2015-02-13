require libslp-location.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/location/libslp-location;tag=ae7068a66179d52f94d9f7a5964885a54f5057e9;nobranch=1"

BBCLASSEXTEND += " native "

