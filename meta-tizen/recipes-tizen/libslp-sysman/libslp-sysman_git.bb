require libslp-sysman.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libslp-sysman;tag=377c4ba43340e0258b5bbb44ebfc9837930bc63f;nobranch=1"

BBCLASSEXTEND += " native "

