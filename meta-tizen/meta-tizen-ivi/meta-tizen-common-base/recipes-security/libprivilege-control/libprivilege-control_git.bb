require libprivilege-control.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/libprivilege-control;tag=02e047c543cc35b40f0a59c81f65570cc557038e;nobranch=1"

BBCLASSEXTEND += " native "

