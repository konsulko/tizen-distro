require meta-generic.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/meta-generic;tag=966ec85226e3aeb07dc4294d77c32a5746994690;nobranch=1"

BBCLASSEXTEND += " native "

