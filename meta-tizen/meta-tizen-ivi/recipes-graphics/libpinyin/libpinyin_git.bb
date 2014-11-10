require libpinyin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpinyin;tag=14286edcdd3b2b64c9270c3b93f38013c25a011a;nobranch=1"

BBCLASSEXTEND += " native "

