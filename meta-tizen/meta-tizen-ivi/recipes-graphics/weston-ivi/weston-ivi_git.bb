require weston-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi;tag=c9c00219d70e399d471fe61c658afa77cf48e84c;nobranch=1"

BBCLASSEXTEND += " native "

