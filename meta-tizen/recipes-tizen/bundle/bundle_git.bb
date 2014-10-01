require bundle.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/bundle;tag=71b36b170c377bfd15cb5601c49340ba95a1a30d;nobranch=1"

BBCLASSEXTEND += " native "

