require ico-vic-amb-plugin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-amb-plugin;tag=e4130dfc7c8b75aa2e8a81bb90b03dd3c3aba0a1;nobranch=1"

BBCLASSEXTEND += " native "

