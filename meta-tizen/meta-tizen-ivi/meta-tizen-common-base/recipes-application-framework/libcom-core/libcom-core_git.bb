require libcom-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/com-core;tag=dbfd87c27e0f73b95b2ae16d0b76e059484d5375;nobranch=1"

BBCLASSEXTEND += " native "

