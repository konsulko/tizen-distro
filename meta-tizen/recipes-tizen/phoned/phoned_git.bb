require phoned.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/phoned;tag=11632547d96d1b02b8ece75789e420a3d1ca95d3;nobranch=1"

BBCLASSEXTEND += " native "

