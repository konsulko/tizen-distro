require crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk;tag=b3b99a64df6ab54abcc1b7ceb27aa6926d7d0943;nobranch=1"

BBCLASSEXTEND += " native "

