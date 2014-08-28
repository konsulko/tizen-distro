require package-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/package-manager;tag=19fa6e082a246e0ec427fca79591e4fe564442e2;nobranch=1"

BBCLASSEXTEND += " native "

