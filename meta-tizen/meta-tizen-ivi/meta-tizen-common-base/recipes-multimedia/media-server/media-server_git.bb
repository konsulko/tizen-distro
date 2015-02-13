require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=ca93eb1f529cab34a461422d7e22b893d827f9e5;nobranch=1"

BBCLASSEXTEND += " native "

