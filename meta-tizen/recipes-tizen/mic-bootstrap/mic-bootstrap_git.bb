require mic-bootstrap.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/tools/mic-bootstrap;protocol=ssh;tag=dd4a5d486e1c6dfdde6044d7e6840020a8cf3ac3;nobranch=1"

