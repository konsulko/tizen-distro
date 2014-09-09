FILESEXTRAPATHS_prepend := "${THISDIR}/weston"

SRC_URI += "file://weston.target \
            file://0001-comp-wayland-use-safe-foreach-when-destroying-output.patch \
            file://0002-This-vfunc-lets-us-read-out-a-rectangle-of-pixels-fr.patch \
            file://0003-downstream-allow-to-start-for-system-users.patch \
            file://0004-downstream-shell-make-panel-optional-panel-false-in-.patch \
            file://0005-downstream-Hack-to-allow-selecting-a-default-output.patch \
            file://0006-downstream-accept-the-new-enable-sys-uid-configure-o.patch \
            "

do_install_append() {
    install -d ${D}/lib/systemd/user
    install -m 644 ${WORKDIR}/weston.target ${D}/lib/systemd/user/weston.target
}

FILES_${PN} += " /lib/systemd/user/weston.target"

EXTRA_OECONF += "--enable-sys-uid"