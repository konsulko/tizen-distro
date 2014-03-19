require mtdev.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mtdev;protocol=ssh;tag=c54956ad4584b3cc851baeadd50eb8a7f6f4d18d;nobranch=1"

