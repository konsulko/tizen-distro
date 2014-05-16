require doxygen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/doxygen;tag=90bb82245a271bdc3c9d75c07f3f62043311102b;nobranch=1"

BBCLASSEXTEND += " native "

