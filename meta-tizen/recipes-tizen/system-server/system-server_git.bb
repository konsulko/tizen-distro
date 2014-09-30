require system-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/system-server;tag=9c78025072cb67f27da99d22bac34afb01ea0a23;nobranch=1"

BBCLASSEXTEND += " native "

