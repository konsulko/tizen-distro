require desktop-skin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/desktop-skin;tag=cc05dcc61a2545eaa29a18c59d926639c0636cad;nobranch=1"

BBCLASSEXTEND += " native "

