FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += " file://dbus-user.service \
             file://dbus-user.socket \
           "

#SRC_URI += " file://0001-Set-correct-address-when-using-address-systemd.patch "

SRC_URI += " file://0002-Add-_DBUS_GNUC_WARN_UNUSED_RESULT-similar-to-GLib-s.patch \
             file://0003-DBusAtomic-on-Unix-use-pthreads-mutexes-for-fallback.patch \
             file://0004-dbus_threads_init-call-_dbus_threads_init_platform_s.patch \
             file://0005-dbus_threads_init_default-dbus_threads_init-be-safe-.patch \
             file://0006-Remove-unused-global-mutexes-for-win_fds-sid_atom_ca.patch \
             file://0007-Turn-a-runtime-assertion-into-a-compile-time-asserti.patch \
             file://0008-Replace-individual-global-lock-variables-with-an-arr.patch \
             file://0009-Make-taking-a-global-lock-automatically-initialize-l.patch \
             file://0010-Always-initialize-threading-before-allocating-a-dyna.patch \
             file://0011-Add-a-statically-initialized-implementation-of-_dbus.patch \
             file://0012-Enable-checking-of-smack-context-from-DBus-interface.patch \
             file://0013-Enforce-smack-policy-from-conf-file.patch \
           "

SRC_URI += " file://dbus.sh"

DEPENDS += "smack"

do_install_append() {
	mkdir -p ${D}${prefix}/lib/systemd/user
	install -m 0644 ${WORKDIR}/dbus-user.service ${D}${prefix}/lib/systemd/user/dbus.service
	install -m 0644 ${WORKDIR}/dbus-user.socket ${D}${prefix}/lib/systemd/user/dbus.socket
	mkdir -p ${D}/etc/profile.d
	install -m 0755 ${WORKDIR}/dbus.sh ${D}/etc/profile.d/dbus.sh
}

FILES_${PN} += "${prefix}/lib/systemd/user/dbus.service \
               ${prefix}/lib/systemd/user/dbus.socket \
              "

FILES_${PN} += "/etc/profile.d/dbus.sh"

EXTRA_OECONF += " --enable-smack "

