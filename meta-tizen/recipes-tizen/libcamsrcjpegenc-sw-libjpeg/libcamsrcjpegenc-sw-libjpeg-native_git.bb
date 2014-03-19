require libcamsrcjpegenc-sw-libjpeg.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libcamsrcjpegenc-sw-libjpeg;protocol=ssh;tag=24a642db5962e1fd91573eaea766fbf23f42fd1d;nobranch=1"

