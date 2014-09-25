require sync-agent.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/sync-agent;tag=65d4fdceb1d079d92b794bcf47684ddc8e8b7307;nobranch=1"

BBCLASSEXTEND += " native "

