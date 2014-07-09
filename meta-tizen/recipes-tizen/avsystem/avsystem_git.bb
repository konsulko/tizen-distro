require avsystem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/avsystem;tag=72435ebdb656183ee0b74c8232757498987fe34a;nobranch=1"

BBCLASSEXTEND += " native "

