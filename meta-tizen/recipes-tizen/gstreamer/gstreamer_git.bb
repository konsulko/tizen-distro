require gstreamer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gstreamer;protocol=ssh;tag=dff390db6605ad8f42b75b34ca0575e82144ca94;nobranch=1"

