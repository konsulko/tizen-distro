require capi-network-connection.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/connection;tag=141a0c47e0e014b2fe78fb2f5f8f61429a2ba86c;nobranch=1"

BBCLASSEXTEND += " native "

