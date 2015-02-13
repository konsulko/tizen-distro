require libsecret.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libsecret;tag=51c1459c069ef6a311d30c7cd8d9304feb4a1b24;nobranch=1"

BBCLASSEXTEND += " native "

