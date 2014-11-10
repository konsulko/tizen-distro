require python-setuptools.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-setuptools;tag=556fe37505b60a30d7e053d95d8a9aeb789a7b30;nobranch=1"

BBCLASSEXTEND += " native "

