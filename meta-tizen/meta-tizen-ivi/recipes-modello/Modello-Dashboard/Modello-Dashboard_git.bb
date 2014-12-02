require Modello-Dashboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Dashboard;tag=bd92737dd272e5dc55fdca2fa9ab47f1c03ac0fa;nobranch=1"

BBCLASSEXTEND += " native "

