require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=0bb915deb1aef7e677db41a9b6a7efdec1e34f68;nobranch=1"

BBCLASSEXTEND += " native "

