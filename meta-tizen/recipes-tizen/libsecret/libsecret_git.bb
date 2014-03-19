require libsecret.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libsecret;protocol=ssh;tag=323fd83e4fa5a23e79e83b210d853705e21bdd81;nobranch=1"

