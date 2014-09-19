#!/bin/sh -e

source /etc/tizen-platform.conf
export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"

for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
do
    #XWalk requires you not be root to install files
    echo "Installing $list"
    /bin/su app -c "xwalkctl -i $list"
done

for list2 in $(ls -d $TZ_SYS_HOME/app/.config/xwalk-service/applications/*/)
do
    /bin/su app -c "mkdir -p '$list2/css'"
    /bin/su app -c "mkdir -p '$list2/js'"
    /bin/su app -c "cp -r /opt/usr/apps/_common/js/services '$list2/js/'"
    /bin/su app -c "cp -r /opt/usr/apps/_common/css/* '$list2/css/'"
    /bin/su app -c "cp -r /opt/usr/apps/_common/icons '$list2/'"
done
