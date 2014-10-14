require audio-session-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/audio-session-manager;tag=ee4096c72a636cd1112a62903fefb0432e720bea;nobranch=1"

BBCLASSEXTEND += " native "

