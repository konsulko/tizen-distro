require xmlsec1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xmlsec1;tag=fe8ea3dba5971ab3f47090ba52d7f824c3d23545;nobranch=1"

BBCLASSEXTEND += " native "

