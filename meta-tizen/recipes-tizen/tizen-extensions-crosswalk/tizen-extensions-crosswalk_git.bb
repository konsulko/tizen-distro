require tizen-extensions-crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/tizen-extensions-crosswalk;tag=0fe4e0e235b5e5be2b1398be1eb69d7b9c181fa9;nobranch=1"

BBCLASSEXTEND += " native "

