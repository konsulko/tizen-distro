require com-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/com-core;tag=a83dbae72a28c263abb7bf5374a1b41290eca00d;nobranch=1"

BBCLASSEXTEND = "native"

