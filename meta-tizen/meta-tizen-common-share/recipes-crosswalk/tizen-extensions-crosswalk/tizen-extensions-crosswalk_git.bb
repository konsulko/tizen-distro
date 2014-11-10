require tizen-extensions-crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/tizen-extensions-crosswalk;tag=4c352c139d2cec125017d383886eff943ea57046;nobranch=1"

BBCLASSEXTEND += " native "

