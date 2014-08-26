require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=132f817dfa1b64127ba83bdab1d9c7fed898e6a5;nobranch=1"

BBCLASSEXTEND += " native "

