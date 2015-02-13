require vala.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vala;tag=f075306bb9eccbb59c731f441b2b465d9476f80c;nobranch=1"

BBCLASSEXTEND += " native "

