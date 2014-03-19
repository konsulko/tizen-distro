require device-config-touch.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/adaptation/device-config-touch;protocol=ssh;tag=37c79b60ba25c4a14fabd20a58093320ccae930c;nobranch=1"

