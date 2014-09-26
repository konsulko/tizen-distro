require alsa-scenario-0.2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/framework/multimedia/alsa-scenario-0.2;tag=b32d188303681bc9a441edc464e60b62de51ae0e;nobranch=1"

BBCLASSEXTEND += " native "

