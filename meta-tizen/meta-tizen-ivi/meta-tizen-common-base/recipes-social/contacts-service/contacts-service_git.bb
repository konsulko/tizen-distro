require contacts-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/contacts-service;tag=65311cfbd4a5530192daba9099ff9454318b907e;nobranch=1"

BBCLASSEXTEND += " native "

