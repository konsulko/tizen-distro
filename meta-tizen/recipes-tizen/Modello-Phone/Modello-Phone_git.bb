require Modello-Phone.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Phone;tag=a534d4f2866424307dc177fa1269ab22cf3d2d73;nobranch=1"

BBCLASSEXTEND += " native "

