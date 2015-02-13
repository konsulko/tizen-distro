require gsignond-plugin-oauth.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond-plugin-oauth;tag=8dddc2078d70cc193189e02d07f66f75fc828843;nobranch=1"

BBCLASSEXTEND += " native "

