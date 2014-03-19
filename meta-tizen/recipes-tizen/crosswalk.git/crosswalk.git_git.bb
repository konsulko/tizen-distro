require crosswalk.git.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk.git;protocol=ssh;tag=7338fba38ba696536d1cc9d389afd716a6ab2fe6;nobranch=1"

