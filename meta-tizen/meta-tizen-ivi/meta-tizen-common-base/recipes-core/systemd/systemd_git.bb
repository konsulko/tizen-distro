require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=95e1a70c5104b47874519b24e12022e878f2572a;nobranch=1"

BBCLASSEXTEND += " native "

