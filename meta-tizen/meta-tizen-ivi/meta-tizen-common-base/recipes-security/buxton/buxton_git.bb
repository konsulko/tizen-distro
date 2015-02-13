require buxton.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/buxton;tag=30ff93b6f03098ab14626e2212776b05594cb212;nobranch=1"

BBCLASSEXTEND += " native "

