require privacy-manager-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/privacy-manager;tag=9771931036d2c3ced1e962f3caf149999b43f23b;nobranch=1"

BBCLASSEXTEND += " native "

