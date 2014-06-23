require xdgmime.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/xdgmime;tag=93ad04ea3339d7a4b8122bd9bf5ea36d4816f4bc;nobranch=1"

BBCLASSEXTEND += " native "

