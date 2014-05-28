do_install_append() {
    rm -f ${D}/lib/systemd/user/dbus.socket

    mkdir -p ${D}/lib/systemd/system/multi-user-target.wants
    
    ln -sf ${D}/lib/systemd/system/user-session-launch@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session-launch@5001.service
    ln -sf ${D}/lib/systemd/system/user-session-launch@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session-launch@5002.service
    ln -sf ${D}/lib/systemd/system/user-session-launch@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session-launch@5003.service
    ln -sf ${D}/lib/systemd/system/user-session-launch@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session-launch@9999.service

    ln -sf ${D}/lib/systemd/system/user-session@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session@5001.service
    ln -sf ${D}/lib/systemd/system/user-session@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session@5002.service
    ln -sf ${D}/lib/systemd/system/user-session@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session@5003.service
    ln -sf ${D}/lib/systemd/system/user-session@.service ${D}/lib/systemd/system/multi-user-target.wants/user-session@9999.service

    mkdir -p ${D}/lib/systemd/user/default.target.wants

    echo "[Unit]" > ${D}/lib/systemd/user/default.target
    echo "Description=User session default target" >> ${D}/lib/systemd/user/default.target

    ln -sf ${D}/lib/systemd/user/weston-user.service ${D}/lib/systemd/user/default.target.wants/weston-user.service

    ln -sf ${D}/lib/systemd/user/dbus.service ${D}/lib/systemd/user/default.target.wants/dbus.service
}

user-session-units_files += "/lib/systemd/user/*"
