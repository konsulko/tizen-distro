require Modello-Dashboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Dashboard;tag=164d84b5f21047ba0fcacf2a954d25d30ab6f5fd;nobranch=1"

BBCLASSEXTEND += " native "

