require ui-gadget-1.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ui-gadget-1;protocol=ssh;tag=273a36f1c8a1485b584301fd033376430c79c73a;nobranch=1"

