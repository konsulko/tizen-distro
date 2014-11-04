require capi-network-bluetooth.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/bluetooth;tag=ea4787499cb21d2bfc744aad7b8ba103efe67845;nobranch=1"

BBCLASSEXTEND += " native "

