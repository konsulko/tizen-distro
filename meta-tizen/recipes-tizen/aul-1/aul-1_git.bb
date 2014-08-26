require aul-1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=33faaaa1d1d72ed982c1c2454457858a24bea405;nobranch=1"

BBCLASSEXTEND += " native "

