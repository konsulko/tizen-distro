FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://defconfig"
SRC_URI += "file://0001-Smack-Cgroup-filesystem-access.patch"
SRC_URI += "file://0002-SMACK-Fix-handling-value-NULL-in-post-setxattr.patch"

# Setting the KCONFIG_MODE variable prevents it to being set to
# "--allnoconfig" which disable all kernel options.
KCONFIG_MODE = "--reconfig"

# Per MACHINE defconfig files.
# Since only two different defconfig files exist, one for i586 arch and
# the other one for x86_64 arch, there may be a better way to select the
# right defconfig file so we don't have to add all the MACHINE.
# i586 defconfig
COMPATIBLE_MACHINE_genericx86 = "(.*)"
# x86_64 defconfig
COMPATIBLE_MACHINE_valleyisland-64 = "(.*)"
COMPATIBLE_MACHINE_romley-ivb = "(.*)"
