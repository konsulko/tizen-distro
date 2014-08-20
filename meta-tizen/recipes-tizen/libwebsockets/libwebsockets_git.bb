require libwebsockets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/libwebsockets;tag=d23ec16cf1cd3cc8c85884ed2b2c9afbcdedc027;nobranch=1"

BBCLASSEXTEND += " native "

