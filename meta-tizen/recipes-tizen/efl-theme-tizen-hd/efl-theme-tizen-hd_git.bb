require efl-theme-tizen-hd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/efl-theme-tizen;tag=3fa1ccde4d2fd7436720accabb70c63deedb87f3;nobranch=1"

BBCLASSEXTEND += " native "

