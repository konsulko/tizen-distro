require automotive-message-broker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/automotive-message-broker;tag=21d9604f5e11ea7fb63828b30f23af0a07ed08a7;nobranch=1"

BBCLASSEXTEND += " native "

