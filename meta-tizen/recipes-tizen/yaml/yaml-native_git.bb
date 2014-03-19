require yaml.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/yaml;protocol=ssh;tag=83df6fc09a8f2ce52b5c2711e0ddef2f321704d3;nobranch=1"

