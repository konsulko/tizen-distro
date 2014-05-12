require libprivilege-control.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/libprivilege-control;tag=3887c2c7b94bb5473274e93f7479c572a412f9ef;nobranch=1"

BBCLASSEXTEND = "native"

