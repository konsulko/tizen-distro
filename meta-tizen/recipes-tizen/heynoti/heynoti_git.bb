require heynoti.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/heynoti;tag=bc2fb69c89c2046e58a1cd47a4b59acb43405bfa;nobranch=1"

BBCLASSEXTEND += " native "

