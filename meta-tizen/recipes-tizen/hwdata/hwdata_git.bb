require hwdata.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/hwdata;tag=2805db5ffcb5d4022d6bd797e58b97400ecad2d7;nobranch=1"

BBCLASSEXTEND += " native "

