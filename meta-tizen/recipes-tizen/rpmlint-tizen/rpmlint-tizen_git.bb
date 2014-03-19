require rpmlint-tizen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpmlint-tizen;protocol=ssh;tag=f16ab02b9e5f12fdfd375351acf5ff0455c58215;nobranch=1"

