require sphinxbase.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/sphinxbase;tag=098e67f24f18c6374152ca863d354d00bdec3fe0;nobranch=1"

BBCLASSEXTEND += " native "

