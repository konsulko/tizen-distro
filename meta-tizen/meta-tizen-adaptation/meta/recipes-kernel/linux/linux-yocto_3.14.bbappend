FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Tizen defconfig
SRC_URI += "${DEFCONFIG}"

# TMP fix for error: "implicit declaration of function 'sk_run_filter'"
SRC_URI += "file://0001-net-ptp-use-sk_unattached_filter_create-for-BPF.patch"
SRC_URI += "file://0001-net-ptp-do-not-reimplement-PTP-BPF-classifier.patch"
SRC_URI += "file://0001-net-ptp-move-PTP-classifier-in-its-own-file.patch"

# Tizen patches
SRC_URI += "file://0001-Smack-Cgroup-filesystem-access.patch"
SRC_URI += "file://0002-SMACK-Fix-handling-value-NULL-in-post-setxattr.patch"
SRC_URI += "file://0003-Revert-x86-efi-Correct-EFI-boot-stub-use-of-code32_s.patch"
SRC_URI += "file://0004-KEYS-Move-the-flags-representing-required-permission.patch"
SRC_URI += "file://0005-smack-fix-key-permission-verification.patch"
SRC_URI += "file://0006-Minor-improvement-of-smack_sb_kern_mount.patch"
SRC_URI += "file://0007-Smack-fix-the-subject-object-order-in-smack_ptrace_t.patch"
SRC_URI += "file://0008-Smack-unify-all-ptrace-accesses-in-the-smack.patch"
SRC_URI += "file://0009-Smack-adds-smackfs-ptrace-interface.patch"
SRC_URI += "file://0010-bugfix-patch-for-SMACK.patch"
SRC_URI += "file://0011-Smack-Correctly-remove-SMACK64TRANSMUTE-attribute.patch"
SRC_URI += "file://0012-Smack-bidirectional-UDS-connect-check.patch"
SRC_URI += "file://0013-Smack-Verify-read-access-on-file-open-v3.patch"
SRC_URI += "file://0014-Warning-in-scanf-string-typing.patch"
SRC_URI += "file://0015-Smack-fix-behavior-of-smack_inode_listsecurity.patch"
SRC_URI += "file://0016-Smack-handle-zero-length-security-labels-without-pan.patch"
SRC_URI += "file://0017-Smack-remove-unneeded-NULL-termination-from-securtit.patch"
SRC_URI += "file://0018-Smack-Fix-setting-label-on-successful-file-open.patch"
SRC_URI += "file://0019-perf-tools-define-_DEFAULT_SOURCE-for-glibc_2.20.patch"
SRC_URI += "file://0020-SMACK-Fix-wrong-copy-size.patch"

# Per architecture defconfig files.
DEFCONFIG_i586 = "file://defconfig"
DEFCONFIG_x86-64 = "file://defconfig"
DEFCONFIG_arm= "file://defconfig"

# Setting the KCONFIG_MODE variable prevents it to being set to
# "--allnoconfig" which disable all kernel options.
KCONFIG_MODE = "--reconfig"

COMPATIBLE_MACHINE_genericx86 = "genericx86"
COMPATIBLE_MACHINE_genericx86-64 = "genericx86-64"