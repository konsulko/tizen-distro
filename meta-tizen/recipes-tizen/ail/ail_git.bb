require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=84d6c89b12efe4af20c21ced0e7775035b3d50e4;nobranch=1"

BBCLASSEXTEND += " native "

