require libgee.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgee;tag=24bb6db9d4111a80493e5658b746c34ab80f4dbc;nobranch=1"

BBCLASSEXTEND += " native "

