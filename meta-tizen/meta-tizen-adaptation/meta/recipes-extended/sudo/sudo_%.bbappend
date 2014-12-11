SECTION = "Base/Utilities"

FILESEXTRAPATHS_prepend := "${THISDIR}/sudo:"

SRC_URI += "file://pam.d/sudo"

do_install_append () {
    # Use Tizen pam rule for sudo instead of the upstream one
    if [ "${@bb.utils.contains('DISTRO_FEATURES', 'pam', 'pam', '', d)}" = "pam" ]; then
        install -D -m 664 ${WORKDIR}/pam.d/sudo ${D}/${sysconfdir}/pam.d/sudo
    fi
}
