require capi-appfw-package-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/package-manager;tag=16c0f38bfe8b93b54dee0668a87d6164d7342782;nobranch=1"

BBCLASSEXTEND += " native "

