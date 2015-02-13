require capi-system-sensor.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/sensor;tag=792636269f94a15b9765e0f1c387289f573eacbd;nobranch=1"

BBCLASSEXTEND += " native "

