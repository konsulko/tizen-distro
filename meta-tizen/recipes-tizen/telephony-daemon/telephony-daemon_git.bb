require telephony-daemon.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/telephony-daemon;protocol=ssh;tag=ec53d6262402d3bdf87c891255897997bfab6733;nobranch=1"

