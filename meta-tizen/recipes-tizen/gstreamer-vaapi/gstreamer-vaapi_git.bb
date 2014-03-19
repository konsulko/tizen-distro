require gstreamer-vaapi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gstreamer-vaapi;protocol=ssh;tag=79fb24fd932f92fdc802e1fd74fe5a25d0510912;nobranch=1"

