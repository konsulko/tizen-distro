FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://defconfig"
SRC_URI += "file://0001-Smack-Cgroup-filesystem-access.patch"
SRC_URI += "file://0002-SMACK-Fix-handling-value-NULL-in-post-setxattr.patch"