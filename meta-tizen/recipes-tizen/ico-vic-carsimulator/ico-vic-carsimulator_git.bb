require ico-vic-carsimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-carsimulator;tag=7f54d8d41f57877e3a701fd97fe0afdfaac1776e;nobranch=1"

BBCLASSEXTEND += " native "

