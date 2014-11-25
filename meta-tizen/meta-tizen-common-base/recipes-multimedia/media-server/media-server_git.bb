require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=1ca2a80b79c5b5153d46a8e722730882e7fa7efb;nobranch=1"

BBCLASSEXTEND += " native "

