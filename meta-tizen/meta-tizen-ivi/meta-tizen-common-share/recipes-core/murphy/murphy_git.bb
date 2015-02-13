require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=b9d006e4db4bc964e5acad83feab71e00d34968d;nobranch=1"

BBCLASSEXTEND += " native "

