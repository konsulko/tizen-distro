require app-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-core;tag=58b4a5a46100477fe7164a02ba9afe05eec0599d;nobranch=1"

BBCLASSEXTEND += " native "

