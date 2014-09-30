require capi-location-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/location-manager;tag=43decd22f1ae4fe02710e029e3f73b97b4b1778f;nobranch=1"

BBCLASSEXTEND += " native "

