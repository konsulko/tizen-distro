require app-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-core;tag=d86d0066b93cf402badc408de591e54d6db6c164;nobranch=1"

BBCLASSEXTEND += " native "

