require gpg2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gpg2;tag=fd45bba47cfbab680118e8154c47993549dfbad6;nobranch=1"

BBCLASSEXTEND += " native "

