FILES_${PN}-dbg += "${prefix}/lib/tlm/plugins/.debug"
inherit systemd
SYSTEMD_SERVICE_${PN} = "tlm.service"