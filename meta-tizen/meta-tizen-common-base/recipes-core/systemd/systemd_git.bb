require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=f1a985d567a9094ef916d59d8e528810bdbffc0a;nobranch=1"

BBCLASSEXTEND += " native "

