require libsqlfs.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/libsqlfs;protocol=ssh;tag=c96cead807b7d479db0b3cc3745db9df92b6a564;nobranch=1"

