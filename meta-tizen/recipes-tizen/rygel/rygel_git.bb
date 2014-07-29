require rygel.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/rygel;tag=be0b78a986fe3d55ec3353afc4661f54351a3766;nobranch=1"

BBCLASSEXTEND += " native "

