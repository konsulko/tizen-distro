require app-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/app-manager;tag=2c759cfd660bf72182d9abaa554b086ad21bedb3;nobranch=1"

BBCLASSEXTEND += " native "

