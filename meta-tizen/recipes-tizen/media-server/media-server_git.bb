require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=2cdbd222416f212c4969365c8555c6b45da7f386;nobranch=1"

BBCLASSEXTEND += " native "

