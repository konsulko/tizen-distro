require aul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=6a5c0b16ac45835babaca4fc8984bbf27469725c;nobranch=1"

BBCLASSEXTEND += " native "

