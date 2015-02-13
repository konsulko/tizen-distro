require ivi-sanity-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/ivi/ivi-sanity-suite;tag=ef7ddc2e489672dc5567e511da57283fe22859fb;nobranch=1"

BBCLASSEXTEND += " native "

