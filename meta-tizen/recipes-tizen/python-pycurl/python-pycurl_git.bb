require python-pycurl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-pycurl;protocol=ssh;tag=e6210e3c041913a4b0c27e20b8ebf2926626b85a;nobranch=1"

