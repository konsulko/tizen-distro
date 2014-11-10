require gupnp.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GUPnP;tag=6133eb3c531b27747fa8277ea8e92e10e5eb4688;nobranch=1"

BBCLASSEXTEND += " native "

