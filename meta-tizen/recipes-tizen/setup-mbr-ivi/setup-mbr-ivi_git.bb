require setup-mbr-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/setup-mbr-ivi;protocol=ssh;tag=d1b5242b3219a90ca39179a72addee00ab7713ab;nobranch=1"

