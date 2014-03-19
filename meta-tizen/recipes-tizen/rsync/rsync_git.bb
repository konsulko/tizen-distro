require rsync.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rsync;protocol=ssh;tag=3381e6608736923263ab869d5994de8554038a67;nobranch=1"

