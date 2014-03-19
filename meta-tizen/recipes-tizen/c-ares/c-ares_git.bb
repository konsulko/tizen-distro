require c-ares.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/c-ares;protocol=ssh;tag=ba059bf72831e78eeb7d4d72069d0d2a6455f839;nobranch=1"

