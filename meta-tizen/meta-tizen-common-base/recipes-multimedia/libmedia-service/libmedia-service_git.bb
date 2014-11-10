require libmedia-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-service;tag=b7f1f1ec421c16a4e6fea164495c281887a5d3b8;nobranch=1"

BBCLASSEXTEND += " native "

