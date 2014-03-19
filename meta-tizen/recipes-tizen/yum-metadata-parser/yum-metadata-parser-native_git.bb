require yum-metadata-parser.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/yum-metadata-parser;protocol=ssh;tag=0b140b5d0c96edbc7323a70cf842ecfe7b6ba424;nobranch=1"

