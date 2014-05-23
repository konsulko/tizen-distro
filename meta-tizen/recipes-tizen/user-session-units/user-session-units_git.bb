require user-session-units.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/user-session-units;tag=545e17bc1926c6f7967aeefc128a95ee8483010d;nobranch=1"

BBCLASSEXTEND += " native "

