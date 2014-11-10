require libmm-log.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-log;tag=4b994c87d76bafd03b02833a5645c524487f914a;nobranch=1"

BBCLASSEXTEND += " native "

