require autoconf.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/autoconf;protocol=ssh;tag=f0cbc9a7782ecebf4991aa7f4155ee2e58471c20;nobranch=1"

