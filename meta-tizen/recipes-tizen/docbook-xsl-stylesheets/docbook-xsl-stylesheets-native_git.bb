require docbook-xsl-stylesheets.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/docbook-xsl-stylesheets;protocol=ssh;tag=e07c2569364af34bf5041083e4cbea08b95937f5;nobranch=1"

