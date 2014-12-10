require capi-network-bluetooth.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/bluetooth;tag=768f05234c91713dc75a70c75006d05fc5183daf;nobranch=1"

BBCLASSEXTEND += " native "

