#!/bin/sh -e

source /etc/tizen-platform.conf
export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"

export MODELLO_INSTALL_USER="app"
export MODELLO_COMMON_DIR="/usr/share/Modello/Common"

export PATH="${PATH}:/bin"

for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
do
#XWalk requires you not be root to install files
        echo "Installing $list"
        su ${MODELLO_INSTALL_USER} -c "xwalkctl -i $list"
done

for list2 in $(ls -d $TZ_SYS_HOME/${MODELLO_INSTALL_USER}/.config/xwalk-service/applications/*/)
do      
        echo list2 $
        su - ${MODELLO_INSTALL_USER} -c "mkdir -p '$list2/css'"
        su - ${MODELLO_INSTALL_USER} -c "mkdir -p '$list2/js'"
        su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/js/services '$list2/js/'"
        su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/css/* '$list2/css/'"
        su - ${MODELLO_INSTALL_USER} -c "cp -fr ${MODELLO_COMMON_DIR}/icons '$list2/'"
        
        
done

