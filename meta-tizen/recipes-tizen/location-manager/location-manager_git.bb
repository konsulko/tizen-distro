require location-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/location-manager;tag=d798d95b06c0fab2ac22701f6cbba2778236bc36;nobranch=1"

BBCLASSEXTEND += " native "

