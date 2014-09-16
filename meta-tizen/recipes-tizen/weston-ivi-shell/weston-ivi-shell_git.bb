require weston-ivi-shell.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi-shell;tag=03ba0c96cfb2e7a32d92a1c5a833d05922dfee34;nobranch=1"

BBCLASSEXTEND += " native "

