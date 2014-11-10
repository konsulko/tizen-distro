require gsignond-plugin-sasl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond-plugin-sasl;tag=74233b7793f7f012aaeb3118694f7dfbe35f0d38;nobranch=1"

BBCLASSEXTEND += " native "

