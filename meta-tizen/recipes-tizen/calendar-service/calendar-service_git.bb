require calendar-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/calendar-service;tag=8329a2a463edae1e65d5020eab197a7fa2ad6e98;nobranch=1"

BBCLASSEXTEND += " native "

