require capi-network-connection.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/connection;tag=0a34c7d798343a87c4640936bcab3a55fc18da52;nobranch=1"

BBCLASSEXTEND += " native "

