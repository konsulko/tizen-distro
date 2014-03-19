require python-cython.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-cython;protocol=ssh;tag=81337cc58f1036fa314aa1c76ef79502cf6e7f05;nobranch=1"

