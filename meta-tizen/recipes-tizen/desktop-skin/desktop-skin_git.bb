require desktop-skin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/desktop-skin;tag=be6c8a8d18bb533dcbe4f5c25cd2c1fd1248a940;nobranch=1"

BBCLASSEXTEND += " native "

