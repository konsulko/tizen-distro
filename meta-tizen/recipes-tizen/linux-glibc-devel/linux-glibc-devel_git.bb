require linux-glibc-devel.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/linux-glibc-devel;protocol=ssh;tag=e42dce452f7a10dd9f1cdfc8665b30bd758902fc;nobranch=1"

