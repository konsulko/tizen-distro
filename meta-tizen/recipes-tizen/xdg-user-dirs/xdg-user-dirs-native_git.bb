require xdg-user-dirs.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xdg-user-dirs;protocol=ssh;tag=a0a4a85f022129731f19d2e36f9e234e62736a57;nobranch=1"

