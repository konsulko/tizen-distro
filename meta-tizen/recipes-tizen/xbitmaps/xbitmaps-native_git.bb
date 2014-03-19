require xbitmaps.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xbitmaps;protocol=ssh;tag=5fd28428f6b03b3e65892dac563557debaafb92f;nobranch=1"

