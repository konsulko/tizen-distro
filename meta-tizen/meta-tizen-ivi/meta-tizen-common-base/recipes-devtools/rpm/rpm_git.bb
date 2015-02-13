require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=34297356fec103c001cacc7c40efef374fff211a;nobranch=1"

BBCLASSEXTEND += " native "

