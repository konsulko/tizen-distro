require node-startup-controller.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/node-startup-controller;tag=6043da529f31137dd5acee16ab4ae45e8aab64d7;nobranch=1"

BBCLASSEXTEND += " native "

