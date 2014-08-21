require dlt-daemon.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/dlt-daemon;tag=98d19103951eec42611896e5115fe8ebb584fa88;nobranch=1"

BBCLASSEXTEND += " native "

