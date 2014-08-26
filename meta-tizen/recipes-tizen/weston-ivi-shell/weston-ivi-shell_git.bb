require weston-ivi-shell.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi-shell;tag=83551d5c31757ec5f835ecb496a78d2c5e1006ed;nobranch=1"

BBCLASSEXTEND += " native "

