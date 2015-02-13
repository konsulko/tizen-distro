require capi-appfw-package-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/package-manager;tag=bdf7aa8d670c54979f59f23e07ecd70458eaf27e;nobranch=1"

BBCLASSEXTEND += " native "

