require avsystem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/avsystem;tag=e2bc7b88d123b0ff997061e9a4998106f7f5c3f3;nobranch=1"

BBCLASSEXTEND += " native "

