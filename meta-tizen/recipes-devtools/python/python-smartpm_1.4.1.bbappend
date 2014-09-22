FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_remove = "file://smart-dflags.patch"

DEPENDS_append = " python-rpm-native "

SRC_URI_append = " file://remove_checkrpm_public_key.patch "
SRC_URI_append = " file://add_archscore.patch "
SRC_URI_append = " file://ignorearch_for_ts.patch "
