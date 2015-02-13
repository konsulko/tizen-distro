require nfc-manager-neard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/nfc-manager-neard;tag=45f2831a6d738c5df32b065c6853636fea85f42a;nobranch=1"

BBCLASSEXTEND += " native "

