require capi-web-favorites.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/favorites;tag=65cfd6936edd8d6996b1c2e067997d77decb3309;nobranch=1"

BBCLASSEXTEND += " native "

