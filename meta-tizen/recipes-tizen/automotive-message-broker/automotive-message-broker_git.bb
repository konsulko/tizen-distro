require automotive-message-broker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/automotive-message-broker;tag=4d85122ae488d43757855760da785171f06e7552;nobranch=1"

BBCLASSEXTEND += " native "

