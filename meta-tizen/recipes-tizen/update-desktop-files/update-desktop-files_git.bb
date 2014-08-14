require update-desktop-files.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/update-desktop-files;tag=ca1b55134e1f144f7d06d69e9edb8197a3cfc9e1;nobranch=1"

BBCLASSEXTEND += " native "

