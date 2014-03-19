require contacts-service.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/contacts-service;protocol=ssh;tag=51a7dda371559d3363d5406a630894fc8c3935d5;nobranch=1"

