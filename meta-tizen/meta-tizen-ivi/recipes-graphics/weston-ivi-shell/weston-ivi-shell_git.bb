require weston-ivi-shell.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi-shell;tag=f06dbe919fe5574ab132ba0bbd3c2f2300815b26;nobranch=1"

BBCLASSEXTEND += " native "

