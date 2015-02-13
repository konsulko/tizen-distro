require capi-network-wifi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/wifi;tag=e4f3757407a3f24d8b1d182c43b880e867788fd7;nobranch=1"

BBCLASSEXTEND += " native "

