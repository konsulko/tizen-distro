require bluetooth-frwk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-frwk;tag=2fb774848a3e3dd4c11e260052786c2572e0bbe2;nobranch=1"

BBCLASSEXTEND += " native "

