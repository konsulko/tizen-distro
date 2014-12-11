SECTION = "System/Network"

FILESEXTRAPATHS_prepend := "${THISDIR}/openssh:"

SRC_URI += "file://pam.d/sshd"

do_install_append () {
    # Use Tizen pam rule for sshd instead of the upstream one
    if [ "${@bb.utils.contains('DISTRO_FEATURES', 'pam', 'pam', '', d)}" = "pam" ]; then
        install -D -m 0755 ${WORKDIR}/pam.d/sshd ${D}${sysconfdir}/pam.d/sshd
    fi
}
