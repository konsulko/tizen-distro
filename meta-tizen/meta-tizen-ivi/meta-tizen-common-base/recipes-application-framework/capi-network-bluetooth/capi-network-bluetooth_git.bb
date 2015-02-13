require capi-network-bluetooth.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/bluetooth;tag=0b035a3d6f8ce6d94742575578c9daee1bab6bb3;nobranch=1"

BBCLASSEXTEND += " native "

