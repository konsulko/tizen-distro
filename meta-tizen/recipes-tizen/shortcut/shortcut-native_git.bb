require shortcut.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/shortcut;protocol=ssh;tag=502c7807b32ad01020a8b679bd7f4160d9992f6f;nobranch=1"

