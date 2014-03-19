require kernel-generic.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/kernel/kernel-generic;protocol=ssh;tag=6cc2114127cb4780e36e951e10b987699be158a8;nobranch=1"

