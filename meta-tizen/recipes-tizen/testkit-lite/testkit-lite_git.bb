require testkit-lite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-lite;tag=6ebfe1474b3c2db6c052fa3d2f90a1bac25c3ec2;nobranch=1"

BBCLASSEXTEND += " native "

