require wayland-fits-master.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/generic/wayland-fits;tag=c299b70e1df4b8e28beeac3bc80134b7baf2abe6;nobranch=1"

BBCLASSEXTEND += " native "

