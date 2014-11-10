require capi-network-connection.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/connection;tag=5ec3b5009863330a604936cedcc75cd9fee3d89a;nobranch=1"

BBCLASSEXTEND += " native "

