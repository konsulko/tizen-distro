require dmidecode.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dmidecode;protocol=ssh;tag=98dd846011c4be12bb7d03b25d3ef991b669db7b;nobranch=1"

