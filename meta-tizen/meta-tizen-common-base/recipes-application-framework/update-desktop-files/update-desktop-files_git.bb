require update-desktop-files.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/update-desktop-files;tag=41a39c9fe36dbbbc769ca391c32d5f8a3c0c0291;nobranch=1"

BBCLASSEXTEND += " native "

