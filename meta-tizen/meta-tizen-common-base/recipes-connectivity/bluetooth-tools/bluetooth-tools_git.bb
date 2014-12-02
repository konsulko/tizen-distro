require bluetooth-tools.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-tools;tag=ecb6831625572976a78a5ebdbe32fa0c0dfdb45e;nobranch=1"

BBCLASSEXTEND += " native "

