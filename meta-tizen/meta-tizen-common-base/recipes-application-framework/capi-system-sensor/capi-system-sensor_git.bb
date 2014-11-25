require capi-system-sensor.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/sensor;tag=536527ac22998472146e004b6ccdb8476a444576;nobranch=1"

BBCLASSEXTEND += " native "

