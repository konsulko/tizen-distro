require crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk;tag=893693a3709897c9b72d899582bb7ebe29702aa9;nobranch=1"

BBCLASSEXTEND += " native "

