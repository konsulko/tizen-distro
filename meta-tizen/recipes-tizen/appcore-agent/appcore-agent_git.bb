require appcore-agent.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/appcore-agent;tag=1fa9a258c13d31fea03528529d6b40e040ac53d0;nobranch=1"

BBCLASSEXTEND = "native"

