require monotype-fonts.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/monotype-fonts;protocol=ssh;tag=b290de4bb22346b179bf642edfeff2e0f8e41411;nobranch=1"

