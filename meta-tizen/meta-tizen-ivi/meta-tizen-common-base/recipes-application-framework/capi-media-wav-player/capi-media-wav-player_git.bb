require capi-media-wav-player.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/wav-player;tag=e12356a988051f36a2b69dfc6ce0a067117c72d8;nobranch=1"

BBCLASSEXTEND += " native "

