FILESEXTRAPATHS_append := "${THISDIR}/user-session-units"

do_install_append() {
    rm -f ${D}${systemd_unitdir}/user/dbus.socket

    echo "[Unit]" > ${D}${systemd_unitdir}/user/default.target
    echo "Description=User session default target" >> ${D}${systemd_unitdir}/user/default.target

    mkdir -p ${D}${systemd_unitdir}/user/default.target.wants
    ln -sf ../dbus.service ${D}${systemd_unitdir}/user/default.target.wants/dbus.service
    rm ${D}${systemd_unitdir}/user/dbus.service
    
    rm -f ${D}${systemd_unitdir}/user/default.target
    ln -sf weston.target ${D}${systemd_unitdir}/user/default.target
}

user-session-units_files += "${systemd_unitdir}/user/*"
