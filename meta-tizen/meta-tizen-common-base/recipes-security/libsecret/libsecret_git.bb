require libsecret.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libsecret;tag=115bcbe47059371f172286c68d730d7c59f9e8fc;nobranch=1"

BBCLASSEXTEND += " native "

