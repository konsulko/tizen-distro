require meta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=7ce5aa04ad9c962d506d06e6e8a626295645eb26;nobranch=1"

BBCLASSEXTEND += " native "

