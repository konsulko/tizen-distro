require gupnp-dlna.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GUPnP-DLNA;tag=fcf4110293c50f0299142bc9ef56f29266fb8d78;nobranch=1"

BBCLASSEXTEND += " native "

