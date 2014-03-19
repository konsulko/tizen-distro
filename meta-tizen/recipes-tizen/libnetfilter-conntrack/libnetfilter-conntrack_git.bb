require libnetfilter-conntrack.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libnetfilter_conntrack;protocol=ssh;tag=7882d2864cf44efd8ac602cae535700b454a54df;nobranch=1"

