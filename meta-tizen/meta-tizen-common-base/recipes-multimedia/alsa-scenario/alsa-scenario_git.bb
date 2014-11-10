require alsa-scenario.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/framework/multimedia/alsa-scenario-0.2;tag=915491684441521d60e55c6a5cbb65d482e5e5ab;nobranch=1"

BBCLASSEXTEND += " native "

