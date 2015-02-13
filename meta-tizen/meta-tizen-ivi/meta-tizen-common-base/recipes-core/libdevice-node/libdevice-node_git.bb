require libdevice-node.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libdevice-node;tag=04fd20f5a06355fc0afe110337ccb9dc7445ad1d;nobranch=1"

BBCLASSEXTEND += " native "

