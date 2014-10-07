require evolution-data-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/evolution-data-server;tag=a30577d9663f329a258fd3f774e43979bb3f3e1b;nobranch=1"

BBCLASSEXTEND += " native "

