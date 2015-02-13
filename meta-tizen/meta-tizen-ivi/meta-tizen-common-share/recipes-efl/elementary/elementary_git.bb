require elementary.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/elementary;tag=0d21f750a7b9bd09e896ada235518bfea9735b7b;nobranch=1"

BBCLASSEXTEND += " native "

