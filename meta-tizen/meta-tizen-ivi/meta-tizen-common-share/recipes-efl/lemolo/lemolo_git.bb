require lemolo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/lemolo;tag=24fe80b297c7498c9c4f72ed67a1e2fedaabcfd7;nobranch=1"

BBCLASSEXTEND += " native "

