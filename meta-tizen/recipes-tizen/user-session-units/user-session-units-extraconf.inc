FILESEXTRAPATHS_append := "${THISDIR}/user-session-units"

inherit pkgconfig

do_install_append() {
    rm -f ${D}/lib/systemd/user/dbus.socket

    mkdir -p ${D}/lib/systemd/system/graphical.target.wants
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5000.service
    

    echo "[Unit]" > ${D}/lib/systemd/user/default.target
    echo "Description=User session default target" >> ${D}/lib/systemd/user/default.target

    mkdir -p ${D}/lib/systemd/user/default.target.wants
    ln -sf ../dbus.service ${D}/lib/systemd/user/default.target.wants/dbus.service
    rm ${D}/lib/systemd/user/dbus.service
    
    rm -f ${D}/lib/systemd/user/default.target
    ln -sf weston.target ${D}/lib/systemd/user/default.target
    
}

user-session-units_files += "/lib/systemd/user/*"
