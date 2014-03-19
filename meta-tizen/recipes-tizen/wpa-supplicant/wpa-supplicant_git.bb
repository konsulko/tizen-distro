require wpa-supplicant.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/wpa_supplicant;protocol=ssh;tag=ebfabc831b96666cd193fe7d54ce1d1971a0f224;nobranch=1"

