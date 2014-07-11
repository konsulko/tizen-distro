require xdgmime.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/xdgmime;tag=5e5be094af84c8443a42e1981c649dece1693ae3;nobranch=1"

BBCLASSEXTEND += " native "

