require msg-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/messaging/msg-service;tag=3e2fbed353a12948ed01610a5910bb967cad1445;nobranch=1"

BBCLASSEXTEND += " native "

