require desktop-skin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/desktop-skin;tag=2f3deede9240f192b540266a923b98425d072f92;nobranch=1"

BBCLASSEXTEND += " native "

