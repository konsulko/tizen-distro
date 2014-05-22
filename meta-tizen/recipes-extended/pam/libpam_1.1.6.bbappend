FILESEXTRAPATHS_prepend := "${THISDIR}/libpam"

SRC_URI += "file://system-auth \
            file://other \
            file://0001-add-packaging.patch \
            file://0002-fix-includes.patch \
            file://0003-add-missing-files.patch \
            file://0004-Update-to-1.1.6.patch \
            file://0006-Update-to-1.1.6.patch \
            file://0007-Move-pam_mkhomedir.so-to-main-package-systemd-needs-.patch \
            file://0008-remove-manifest-macro.patch \
            file://0009-remove-manifest-macro.patch \
            file://0010-remove-manifest.patch \
            file://0011-remove-non-existant-manifest-macro.patch \
            file://0012-Add-multi-lib-support.patch \
            file://0013-Fixed-package-groups.patch \
            file://0014-resetting-manifest-requested-domain-to-floor.patch \
            file://0015-build-locale-package.patch \
            file://0016-optimize-package-groups.patch \
            file://0017-fixed-license.patch \
            file://0018-Add-a-pam-module-to-set-smack-label-PTREL-549.patch \
            file://0019-adding-.changes.patch \
            file://0020-Packaging-spec-cleanup.patch \
            "

# Patch fail:
# 0005-add-missing-DESTDIR.patch

do_install_append() {
    install -d -m 0755 ${D}/etc/pam.d
    install -m 0644 ${WORKDIR}/system-auth ${D}/etc/pam.d
    install -m 0644 ${WORKDIR}/other ${D}/etc/pam.d
}

FILES_${PN} += " /etc/pam.d/system-auth /etc/pam.d/other"