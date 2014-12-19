SRC_URI += "file://systemd-user"

inherit useradd

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} += "--system -g 11 cdrom;"
GROUPADD_PARAM_${PN} += "--system -g 33 tape;"
GROUPADD_PARAM_${PN} += "--system -g 18 dialout;"
GROUPADD_PARAM_${PN} += "--system -g 19 floppy"

EXTRA_OECONF += "--disable-manpages"
EXTRA_OECONF += "--without-python"
EXTRA_OECONF += "--disable-libcurl"

GTKDOC_DOCDIR = "${S}/docs/"

do_configure_prepend() {
    rm -f ${S}/docs/gtk-doc.make
    echo 'EXTRA_DIST =' > ${S}/docs/gtk-doc.make

    sed -i 's!@MKDIR_P@!/bin/mkdir -p!g' ${S}/units/kmod-static-nodes.service.in
    sed -i 's!@KMOD@!/bin/kmod!g' ${S}/units/kmod-static-nodes.service.in
    sed -i 's!@KILL@!/bin/kill!g' ${S}/units/user/systemd-exit.service.in
}

do_install_append() {
    rm -fr ${D}${prefix}/share/factory
    rm -fr ${D}/lib/systemd/network/80-container-ve.network
    rm -fr ${D}/lib/systemd/network/80-container-host0.network
    rm -fr ${D}/lib/systemd/system-preset/90-systemd.preset
    
    rm -fr ${D}${sysconfdir}/hostname
    rm -fr ${D}${sysconfdir}/timezone
    
    install -m 0644 ${WORKDIR}/systemd-user ${D}${sysconfdir}/pam.d
}

pkg_preinst_${PN}() {
    #!/bin/sh -e

    # Rename configuration files that changed their names
    mv -n $D${sysconfdir}/systemd/systemd-logind.conf $D${sysconfdir}/systemd/logind.conf >/dev/null 2>&1 || :
    mv -n $D${sysconfdir}/systemd/systemd-journald.conf $D${sysconfdir}/systemd/journald.conf >/dev/null 2>&1 || :
}



systemd-dbg_files += "/lib/systemd/.debug"
systemd-dbg_files += "/lib/security/.debug"
systemd-dbg_files += "/lib/systemd/system-generators/.debug"
systemd-dbg_files += "/lib/udev/.debug"

FILES_${PN}-dbg += "${systemd-dbg_files}"


FILES_${PN}-locale-fr += "${prefix}/lib/systemd/catalog/systemd.fr.catalog"
FILES_${PN}-locale-it += "${prefix}/lib/systemd/catalog/systemd.it.catalog"
FILES_${PN}-locale-ru += "${prefix}/lib/systemd/catalog/systemd.ru.catalog"
FILES_${PN}-locale    += "${prefix}/lib/systemd/catalog/systemd.catalog"
  

systemd_files += "${prefix}/lib/systemd/network"
systemd_files += "${sysconfdir}/machine-id"
systemd_files += "${sysconfdir}/vconsole.conf"
systemd_files += "${sysconfdir}/locale.conf"
systemd_files += "${sysconfdir}/machine-info"
