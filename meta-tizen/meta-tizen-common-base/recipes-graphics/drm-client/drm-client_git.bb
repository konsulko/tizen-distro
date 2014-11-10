require drm-client.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/drm-client;tag=fe8dfafce86716d18f727492175896a50969923b;nobranch=1"

BBCLASSEXTEND += " native "

