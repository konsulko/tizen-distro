require genivi-audio-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/genivi/genivi-audio-manager;tag=ecbfb15600353a7191cdeca2e0148832bf79e1e2;nobranch=1"

BBCLASSEXTEND += " native "

