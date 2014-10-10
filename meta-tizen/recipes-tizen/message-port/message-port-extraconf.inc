inherit pkgconfig useradd

INSANE_SKIP_libmessage-port = "dev-so"

RPROVIDES_message-port += "message-port-dbus"

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} += "-r messageport"
USERADD_PARAM_${PN} += "-r -g messageport -s /bin/false -d /run/messageport -c \"Message Port daemon\" messageport"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && systemctl enable messageportd.service
}
