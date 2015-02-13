require appcore-agent.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/appcore-agent;tag=e30036bce3773d3f647a35bc924d01e17da42962;nobranch=1"

BBCLASSEXTEND += " native "

