require libvpx.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libvpx;protocol=ssh;tag=5c09a05423e8ac707f5dd47cb02d22c31776c0c7;nobranch=1"

