require xdgmime.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/xdgmime;tag=67141100ad0f940567492958ae9c315c80dd579e;nobranch=1"

BBCLASSEXTEND = "native"
