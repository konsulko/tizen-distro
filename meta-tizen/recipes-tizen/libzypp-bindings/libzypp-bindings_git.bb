require libzypp-bindings.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libzypp-bindings;protocol=ssh;tag=409530a62d49b0e76e1c045d105ffd6a5ca97327;nobranch=1"

