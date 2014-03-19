require btrfs-progs.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/btrfs-progs;protocol=ssh;tag=40fe08677f183fcb6808377950d87a65115b0274;nobranch=1"

