require rygel.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/rygel;tag=691ca909d4afd0f79145d760583dfe4756de1411;nobranch=1"

BBCLASSEXTEND += " native "

