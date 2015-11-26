require ofono.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://github.com/konsulko/ofono.git;tag=d7fbeddbe62cc7b477fcb2fc220cd497e0efde18;nobranch=1"

BBCLASSEXTEND += " native "

