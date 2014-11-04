require vala.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vala;tag=840fd0f666c91fba0169b8176cb88a80b689ad8a;nobranch=1"

BBCLASSEXTEND += " native "

