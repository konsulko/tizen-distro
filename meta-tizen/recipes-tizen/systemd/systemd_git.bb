require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=9986a304a0a3f771d671f04d1eebfea6d9a32a20;nobranch=1"

BBCLASSEXTEND += " native "

