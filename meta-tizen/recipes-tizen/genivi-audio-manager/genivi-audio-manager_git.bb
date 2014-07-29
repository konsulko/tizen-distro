require genivi-audio-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/genivi/genivi-audio-manager;tag=c408bbaa028e734b541f08fe4cff122b3da4c4ec;nobranch=1"

BBCLASSEXTEND += " native "

