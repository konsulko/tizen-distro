require system-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/system-server;protocol=ssh;tag=af4659b815ca2ecd421c0d84b6a3aa0176ccae57;nobranch=1"

