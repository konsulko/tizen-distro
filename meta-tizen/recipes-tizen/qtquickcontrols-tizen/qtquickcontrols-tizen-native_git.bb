require qtquickcontrols-tizen.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtquickcontrols-tizen;protocol=ssh;tag=f4a4872aff9e0f02daf2dbf77d1258c6ead27b52;nobranch=1"

