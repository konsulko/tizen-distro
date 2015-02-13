require libwifi-direct.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/libwifi-direct;tag=0ad8520db6635de545423d462744d14a1f11d329;nobranch=1"

BBCLASSEXTEND += " native "

