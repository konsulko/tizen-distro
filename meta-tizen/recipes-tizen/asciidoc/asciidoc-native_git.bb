require asciidoc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/asciidoc;protocol=ssh;tag=9c94d2935ad4e4a05c43cc595f251b6e45e8c0c9;nobranch=1"

