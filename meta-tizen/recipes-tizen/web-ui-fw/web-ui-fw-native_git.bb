require web-ui-fw.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/web-ui-fw;protocol=ssh;tag=df41c9dc4ba7e82f138b798debbe1133e329680a;nobranch=1"

