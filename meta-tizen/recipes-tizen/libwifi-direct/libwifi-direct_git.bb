require libwifi-direct.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/libwifi-direct;tag=0371caae5f0c66a74501c1fd44ad398cee16b31d;nobranch=1"

BBCLASSEXTEND += " native "

