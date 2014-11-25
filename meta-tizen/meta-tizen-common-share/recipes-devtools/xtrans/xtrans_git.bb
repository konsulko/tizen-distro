require xtrans.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xtrans;tag=b550c438464ec47ab8013f766f460737a2375676;nobranch=1"

BBCLASSEXTEND += " native "

