require dlt.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/dlt-daemon;tag=9dbf393c4c9ca8f1dbf3b4a925a14d0e9c2dd179;nobranch=1"

BBCLASSEXTEND += " native "

