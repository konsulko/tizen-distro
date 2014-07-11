require alarm-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/alarm-manager;tag=90ac77c2887b9d409bb834c8212a82bd60fa3387;nobranch=1"

BBCLASSEXTEND += " native "

