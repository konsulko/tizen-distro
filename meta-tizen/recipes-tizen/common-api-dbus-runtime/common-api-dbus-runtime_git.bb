require common-api-dbus-runtime.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/common-api-dbus-runtime;tag=f5383391b93eaa4640494f87bbadeb7ad97504a9;nobranch=1"

BBCLASSEXTEND += " native "

