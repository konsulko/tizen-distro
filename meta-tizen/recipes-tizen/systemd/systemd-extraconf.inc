SRC_URI += "file://systemd-user \
            file://user@.service \
           "

systemd_files += "${sysconfdir}/*"

systemd_files += "/usr/lib64/python2.7"
systemd_files += "/usr/lib64/python2.7/site-packages"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/__init__.py"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/daemon.py"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/_daemon.so"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/_reader.so"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/_journal.so"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/__init__.pyo"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/daemon.pyo"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/journal.pyo"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/journal.py"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/id128.so"
systemd_files += "/usr/lib64/python2.7/site-packages/systemd/login.so"

systemd_files += "${prefix}/lib/rpm"
systemd_files += "${prefix}/lib/rpm/macros.d"

systemd_files += "/var/log"
systemd_files += "/var/lib/systemd"
systemd_files += "/var/volatile/log"
systemd_files += "/var/volatile/log/README"
systemd_files += "/var/volatile/log/journal"

systemd-dbg_files += "${prefix}/lib/security/.debug"
systemd-dbg_files += "${prefix}/lib/systemd/system-generators/.debug"
systemd-dbg_files += "${prefix}/lib/udev/.debug"
systemd-dbg_files += "${prefix}/lib64/python2.7/site-packages/systemd/.debug"

FILES_${PN}-dbg += "${systemd-dbg_files}"

do_install_append() {
 rm ${D}${sysconfdir}/hostname
 rm ${D}${sysconfdir}/vconsole.conf
 rm ${D}${sysconfdir}/locale.conf
 rm ${D}${sysconfdir}/machine-id
 rm ${D}${sysconfdir}/machine-info
 rm ${D}${sysconfdir}/timezone

 install -m 0644 ${WORKDIR}/systemd-user ${D}${sysconfdir}/pam.d
 install -m 0644 ${WORKDIR}/user@.service ${D}/usr/lib/systemd/system/
}

EXTRA_OECONF = " --disable-manpages \
                 --without-python \
               "
GTKDOC_DOCDIR = "${S}/docs/"

do_configure_prepend() {
    rm -f ${S}/docs/gtk-doc.make
    echo 'EXTRA_DIST =' > ${S}/docs/gtk-doc.make

    sed -i 's!@MKDIR_P@!/bin/mkdir -p!g' ${S}/units/kmod-static-nodes.service.in
    sed -i 's!@KMOD@!/bin/kmod!g' ${S}/units/kmod-static-nodes.service.in
    sed -i 's!@KILL@!/bin/kill!g' ${S}/units/user/systemd-exit.service.in
}
