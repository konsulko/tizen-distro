require aul-1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=35b19df9d1cc8fe299fe29ea450cb9ec9c464d31;nobranch=1"

BBCLASSEXTEND += " native "

