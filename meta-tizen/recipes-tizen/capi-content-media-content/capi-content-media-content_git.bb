require capi-content-media-content.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/media-content;tag=49cf7dead7122d4a475a6cfd5f7bc8959a14865f;nobranch=1"

BBCLASSEXTEND += " native "

