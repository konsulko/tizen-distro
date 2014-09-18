require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=b5306fc32c824c1620cb7beebeb8908d8121cac1;nobranch=1"

BBCLASSEXTEND += " native "

