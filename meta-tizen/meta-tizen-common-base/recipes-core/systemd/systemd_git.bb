require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=539e73cf03d12b5d50f7fd3f2a70aea63d9e945f;nobranch=1"

BBCLASSEXTEND += " native "

