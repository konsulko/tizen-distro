require smack.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/smack;tag=66a110344be79ff2968ff6817ec72f569d852c17;nobranch=1"

BBCLASSEXTEND += " native "

