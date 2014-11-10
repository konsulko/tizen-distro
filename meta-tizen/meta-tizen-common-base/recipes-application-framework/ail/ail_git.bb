require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=4df6f91071ef4ddc2918cbe7679c787b835e8c7a;nobranch=1"

BBCLASSEXTEND += " native "

