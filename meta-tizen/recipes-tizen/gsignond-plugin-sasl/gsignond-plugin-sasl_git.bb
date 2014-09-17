require gsignond-plugin-sasl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond-plugin-sasl;tag=b96426197f13e7a3e97fd4e5219e33fe30dbca88;nobranch=1"

BBCLASSEXTEND += " native "

