require Modello-Common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Common;tag=9adf1e91f84a53b3b4c2b3723d1d05363ed14933;nobranch=1"

BBCLASSEXTEND += " native "

