require ico-vic-carsimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-carsimulator;tag=292dd5f55444764ad1e3243cf9d90d63e752ef64;nobranch=1"

BBCLASSEXTEND += " native "

