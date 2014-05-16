require uthash.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/uthash;tag=1436c7858fa133d830a18d27c879af301000a70f;nobranch=1"

BBCLASSEXTEND += " native "

