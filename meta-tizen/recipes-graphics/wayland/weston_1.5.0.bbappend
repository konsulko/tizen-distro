FILESEXTRAPATHS_prepend := "${THISDIR}/weston"

SRC_URI += "file://weston.target \
            file://0001-downstream-allow-to-start-for-system-users.patch \
            file://0002-downstream-shell-make-panel-optional-panel-false-in-.patch \
            file://0003-downstream-Hack-to-allow-selecting-a-default-output.patch \
            "

do_install_append() {
    install -d ${D}/usr/lib/systemd/user
    install -m 644 ${WORKDIR}/weston.target ${D}/usr/lib/systemd/user/weston.target
}

FILES_${PN} += " ${prefix}/lib/systemd/user/weston.target"