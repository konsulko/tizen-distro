require message-port-dbus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/message-port-dbus;tag=ef16456ae0ecf48a32f6907c361f5e42bdc06f25;nobranch=1"

BBCLASSEXTEND += " native "

