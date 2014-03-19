require download-provider.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/download-provider;protocol=ssh;tag=0d3754bc9540db26863fe8ab36df518176dbcf50;nobranch=1"

