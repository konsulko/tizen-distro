require python-markdown.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-markdown;protocol=ssh;tag=c42db7e0384c74cb4f55366a9e8b00edd0973885;nobranch=1"

