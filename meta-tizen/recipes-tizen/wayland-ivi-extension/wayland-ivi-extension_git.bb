require wayland-ivi-extension.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/wayland-ivi-extension;tag=da1215f2271a7e77944f50072a3898f9db2b76cc;nobranch=1"

BBCLASSEXTEND += " native "

