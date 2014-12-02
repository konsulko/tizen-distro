require bluetooth-frwk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-frwk;tag=903f4abdc198a6360e7f02a8cc6b876a2f463d2a;nobranch=1"

BBCLASSEXTEND += " native "

