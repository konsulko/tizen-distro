require capi-system-runtime-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/runtime-info;tag=03db94f453f8a070164efd0369d192f739773a80;nobranch=1"

BBCLASSEXTEND += " native "

