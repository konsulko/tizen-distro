require aul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=0d949a469c25c6ace4b406a619c48c9534141045;nobranch=1"

BBCLASSEXTEND += " native "

