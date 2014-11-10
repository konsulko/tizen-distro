require capi-web-url-download.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/url-download;tag=284d7254c1c229ef4dd219db9978c0164bb49c69;nobranch=1"

BBCLASSEXTEND += " native "

