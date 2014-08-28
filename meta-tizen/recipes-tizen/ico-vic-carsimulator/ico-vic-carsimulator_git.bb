require ico-vic-carsimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-carsimulator;tag=190114204368bc5a7449b575c1710c7cd8620b16;nobranch=1"

BBCLASSEXTEND += " native "

