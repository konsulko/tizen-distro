require libaccounts-svc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/libaccounts-svc;tag=07c30a90874972c242f9291a7bfe211d50bb2227;nobranch=1"

BBCLASSEXTEND += " native "

