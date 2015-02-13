require libfeedback.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libsvi;tag=7780e7ea0ea03dcc8e796aa6b22ec53ec34b98d1;nobranch=1"

BBCLASSEXTEND += " native "

