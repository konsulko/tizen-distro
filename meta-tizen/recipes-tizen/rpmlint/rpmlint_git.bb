require rpmlint.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpmlint;protocol=ssh;tag=2a2ab3bb783a40c9b0610f84723202be197ba86c;nobranch=1"

