require automotive-message-broker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/automotive-message-broker;tag=e059fd68a2e1da18084466b24a83ce889fc7a015;nobranch=1"

BBCLASSEXTEND += " native "

