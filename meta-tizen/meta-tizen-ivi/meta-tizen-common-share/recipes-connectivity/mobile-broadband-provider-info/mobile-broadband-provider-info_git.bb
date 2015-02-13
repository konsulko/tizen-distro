require mobile-broadband-provider-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mobile-broadband-provider-info;tag=8a9d3c13cfccb63b48f9818aca07036e32c90396;nobranch=1"

BBCLASSEXTEND += " native "

