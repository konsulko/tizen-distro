require zypper-plugin.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/zypper-plugin;protocol=ssh;tag=d6f3ebd459bc41f2638d4232ad323433d382f454;nobranch=1"

