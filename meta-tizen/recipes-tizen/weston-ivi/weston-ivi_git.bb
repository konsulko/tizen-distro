require weston-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi;tag=057a26dfa55045dd269f58c9e9ee8f608d37e340;nobranch=1"

BBCLASSEXTEND += " native "

