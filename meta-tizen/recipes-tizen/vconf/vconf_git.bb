require vconf.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/vconf;tag=119de39565de2390bbc18a91e4b9d0c7b6b083a8;nobranch=1"

BBCLASSEXTEND += " native "

