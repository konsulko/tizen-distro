require tizen-extensions-crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/tizen-extensions-crosswalk;tag=4c28c16150d492f1d77df6c53aa62d2d969d303d;nobranch=1"

BBCLASSEXTEND += " native "

