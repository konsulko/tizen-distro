require default-ac-domains.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/default-ac-domains;tag=ba096c8ca6fb42146a2541ea6e5df8973593ea9d;nobranch=1"

BBCLASSEXTEND += " native "

