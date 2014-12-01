require nfc-manager-neard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/nfc-manager-neard;tag=2d1f3df127d3b84ebf9d1cdc0d95e69e920933b1;nobranch=1"

BBCLASSEXTEND += " native "

