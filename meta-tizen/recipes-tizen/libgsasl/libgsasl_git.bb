require libgsasl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgsasl;tag=2f967f78ec7fd99025a69c21b470e2328b73ea0d;nobranch=1"

BBCLASSEXTEND += " native "

