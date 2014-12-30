#!/bin/sh -e

source /etc/tizen-platform.conf

export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"

export MODELLO_INSTALL_USER="app"
export MODELLO_COMMON_DIR="/usr/share/Modello/Common"

export PATH="${PATH}:/bin"

vconftool set -t string db/ail/ail_info "0" -f -s system::vconf_inhouse
vconftool set -t string db/menuscreen/desktop "0" -f -s system::vconf_inhouse
vconftool set -t string db/menu_widget/language "en_US.utf8" -f -s system::vconf_inhouse
chsmack -a User /usr/kdb/db/ail
chsmack -a User /usr/kdb/db/ail/ail_info
chsmack -a User /usr/kdb/db/menuscreen
chsmack -a User /usr/kdb/db/menuscreen/desktop
chsmack -a User /usr/kdb/db/menu_widget
chsmack -a User /usr/kdb/db/menu_widget/language
mkdir -p /usr/share/applications
mkdir -p /usr/share/applications
mkdir -p /usr/apps
mkdir -p /usr/dbspace
mkdir -p /usr/share/icons/default/small
chsmack -a '*' /usr/dbspace
chsmack -a '*' /usr/apps
chsmack -a '*' /usr/share/applications
chsmack -a '*' /usr/share/applications
chsmack -a '*' /usr/share/icons
chsmack -a '*' /usr/share/icons/default
chsmack -a '*' /usr/share/icons/default/small/
chmod g+w /usr/share/applications
chmod g+w /usr/share/applications
chown tizenglobalapp:root /usr/share/applications
chown tizenglobalapp:root /usr/share/applications
chown tizenglobalapp:root /usr/apps
chown tizenglobalapp:root /usr/dbspace
chown tizenglobalapp:root /usr/dbspace
chown tizenglobalapp:root -R /usr/share/icons

ail_initdb

pkg_initdb

chown ${MODELLO_INSTALL_USER}:users -R /home/${MODELLO_INSTALL_USER}

for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
do
#XWalk requires you not be root to install files
    echo "Installing $list"
    su ${MODELLO_INSTALL_USER} -c "pkgcmd -q -i -t wgt -p $list"
done

for list2 in $(ls -d $TZ_SYS_HOME/${MODELLO_INSTALL_USER}/apps_rw/xwalk-service/applications/*/)
do
    echo list2 $
    su - ${MODELLO_INSTALL_USER} -c "mkdir -p '$list2/css'"
    su - ${MODELLO_INSTALL_USER} -c "mkdir -p '$list2/js'"
    su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/js/services '$list2/js/'"
    su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/css/* '$list2/css/'"
    su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/icons '$list2/'"


done

rm /lib/systemd/system/multi-user.target.wants/modello-installer-postinst.service