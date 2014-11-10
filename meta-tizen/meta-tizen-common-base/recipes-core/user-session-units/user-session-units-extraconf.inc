FILESEXTRAPATHS_append := "${THISDIR}/user-session-units"

do_install_append() {
    rm -f ${D}${prefix}/lib/systemd/user/dbus.socket

    echo "[Unit]" > ${D}${prefix}/lib/systemd/user/default.target
    echo "Description=User session default target" >> ${D}${prefix}/lib/systemd/user/default.target

    mkdir -p ${D}${prefix}/lib/systemd/user/default.target.wants
    ln -sf ../dbus.service ${D}${prefix}/lib/systemd/user/default.target.wants/dbus.service
    rm ${D}${prefix}/lib/systemd/user/dbus.service
    
    rm -f ${D}${prefix}/lib/systemd/user/default.target
    ln -sf weston.target ${D}${prefix}/lib/systemd/user/default.target
}

user-session-units_files += "${prefix}/lib/systemd/user/*"
