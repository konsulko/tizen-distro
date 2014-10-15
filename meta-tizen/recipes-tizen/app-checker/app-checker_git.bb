require app-checker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-checker;tag=70200243a1e419ff81a30fa8a436571422a33a3d;nobranch=1"

BBCLASSEXTEND += " native "

