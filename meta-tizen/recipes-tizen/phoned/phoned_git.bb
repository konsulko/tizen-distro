require phoned.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/phoned;tag=9bc11b7607090e103bf0f87a83d06f4f637bea46;nobranch=1"

BBCLASSEXTEND += " native "

