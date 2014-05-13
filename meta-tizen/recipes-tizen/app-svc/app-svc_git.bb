require app-svc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-svc;tag=9b9315bfadc5764fabbf8c310db051dc30648fba;nobranch=1"

BBCLASSEXTEND = "native"

