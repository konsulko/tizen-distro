require expect.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/expect;protocol=ssh;tag=579d1c972c9603cfc5bdfad2a1397ae1ba4cbb2d;nobranch=1"

