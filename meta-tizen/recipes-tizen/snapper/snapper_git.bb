require snapper.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/snapper;protocol=ssh;tag=77bcc296e7c6dc40cb2131f94d05c8281ce8e1f1;nobranch=1"

