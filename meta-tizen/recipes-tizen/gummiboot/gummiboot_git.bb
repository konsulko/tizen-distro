require gummiboot.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gummiboot;protocol=ssh;tag=64eee6dd93de8bcfe4ae79c8b5bfd39126a86716;nobranch=1"

