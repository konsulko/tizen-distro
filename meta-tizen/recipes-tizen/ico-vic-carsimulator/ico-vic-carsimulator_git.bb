require ico-vic-carsimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-carsimulator;tag=bf9beedad80666c9ddff39154e6fc741bbaed5e4;nobranch=1"

BBCLASSEXTEND += " native "

