require Modello-Dashboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Dashboard;tag=96d57eca5bd13b5a807a7da746bc96dbdcbcf539;nobranch=1"

BBCLASSEXTEND += " native "

