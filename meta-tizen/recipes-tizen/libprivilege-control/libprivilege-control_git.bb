require libprivilege-control.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/libprivilege-control;tag=e613fc4d3632b7cc79187ade3186d1e07ec79170;nobranch=1"

BBCLASSEXTEND += " native "

