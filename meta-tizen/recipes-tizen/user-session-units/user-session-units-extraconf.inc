FILESEXTRAPATHS_append := "${THISDIR}/user-session-units"

SRC_URI += "file://0001-Modify-user-session-.service-for-the-yocto-build.patch"

do_install_append() {
    rm -f ${D}/lib/systemd/user/dbus.socket

    mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
    
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5001.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5002.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5003.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-9999.service

    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5001.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5002.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5003.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@9999.service

    echo "[Unit]" > ${D}/lib/systemd/user/default.target
    echo "Description=User session default target" >> ${D}/lib/systemd/user/default.target

    mkdir -p ${D}/lib/systemd/user/default.target.wants
    ln -sf ../dbus.service ${D}/lib/systemd/user/default.target.wants/dbus.service
    rm ${D}/lib/systemd/user/dbus.service
}

user-session-units_files += "/lib/systemd/user/*"
