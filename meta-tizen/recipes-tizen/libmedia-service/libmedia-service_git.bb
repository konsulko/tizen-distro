require libmedia-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-service;tag=f9d91e58b273253f324e5b7982103c3ce6a8664f;nobranch=1"

BBCLASSEXTEND += " native "

