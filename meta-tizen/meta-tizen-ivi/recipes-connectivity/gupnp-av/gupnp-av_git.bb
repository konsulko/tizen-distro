require gupnp-av.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GUPnP-AV;tag=71094b9473dad3d2a9bf7c77e5f920879fae8290;nobranch=1"

BBCLASSEXTEND += " native "

