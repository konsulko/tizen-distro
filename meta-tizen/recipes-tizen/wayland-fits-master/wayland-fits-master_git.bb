require wayland-fits-master.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/generic/wayland-fits;tag=4daee8f77b2589fc14f98cbf4c4a6b1967c5d06e;nobranch=1"

BBCLASSEXTEND += " native "

