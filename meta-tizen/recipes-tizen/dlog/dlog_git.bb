require dlog.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/dlog;tag=da8fd9cf10bb30ee1bf1f1398c0bffc33ac55b08;nobranch=1"

BBCLASSEXTEND += " native "

