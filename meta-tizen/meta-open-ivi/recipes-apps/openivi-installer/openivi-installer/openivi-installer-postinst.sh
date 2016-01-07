#!/bin/sh -e

source /etc/tizen-platform.conf

USERID=`id -u`
export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/$USERID/dbus/user_bus_socket"

export OPENIVI_INSTALL_USER="openivi"
export OPENIVI_COMMON_DIR="/usr/share/openivi/Common"

export PATH="${PATH}:/bin"

vconftool set -t string db/ail/ail_info "0" -f -s system::vconf_inhouse
vconftool set -t string db/menuscreen/desktop "0" -f -s system::vconf_inhouse
vconftool set -t string db/menu_widget/language "en_US.utf8" -f -s system::vconf_inhouse
mkdir -p /usr/share/applications
mkdir -p /usr/share/applications
mkdir -p /usr/apps
mkdir -p /usr/dbspace
mkdir -p /usr/share/icons/default/small

mkdir -p ${OPENIVI_COMMON_DIR}/js/services 
mkdir -p ${OPENIVI_COMMON_DIR}/css                                                      
mkdir -p ${OPENIVI_COMMON_DIR}/icons

chmod g+w /usr/share/applications
chmod g+w /usr/share/applications

if grep smackfs /proc/filesystems ; then
	chsmack -a User /usr/kdb/db/ail                                                        
	chsmack -a User /usr/kdb/db/ail/ail_info                                               
	chsmack -a User /usr/kdb/db/menuscreen                                                 
	chsmack -a User /usr/kdb/db/menuscreen/desktop                                         
	chsmack -a User /usr/kdb/db/menu_widget                                                
	chsmack -a User /usr/kdb/db/menu_widget/language  
	chsmack -a '*' /usr/dbspace
	chsmack -a '*' /usr/apps
	chsmack -a '*' /usr/share/applications
	chsmack -a '*' /usr/share/applications
	chsmack -a '*' /usr/share/icons
	chsmack -a '*' /usr/share/icons/default
	chsmack -a '*' /usr/share/icons/default/small/

	chown tizenglobalapp:root /usr/share/applications
	chown tizenglobalapp:root /usr/share/applications
	chown tizenglobalapp:root /usr/apps
	chown tizenglobalapp:root /usr/dbspace
	chown tizenglobalapp:root /usr/dbspace
	chown tizenglobalapp:root -R /usr/share/icons

	ail_initdb

	pkg_initdb

fi

chown ${OPENIVI_INSTALL_USER}:users -R /home/${OPENIVI_INSTALL_USER}

for list in $(find $TZ_SYS_APP_PREINSTALL -name "openivi*")
do
#XWalk requires you not be root to install files
    echo "Installing $list"
    su ${OPENIVI_INSTALL_USER} -c "pkgcmd -q -i -t wgt -p $list"
done

for list2 in $(ls -d $TZ_SYS_HOME/${OPENIVI_INSTALL_USER}/apps_rw/xwalk-service/applications/*/)
do
    echo $list2
    su - ${OPENIVI_INSTALL_USER} -c "mkdir -p '$list2/css'"
    su - ${OPENIVI_INSTALL_USER} -c "mkdir -p '$list2/js'"
    su - ${OPENIVI_INSTALL_USER} -c "cp -fr ${OPENIVI_COMMON_DIR}/ '$list2/DNA_common'"
done

rm -f /lib/systemd/system/multi-user.target.wants/openivi-installer-postinst.service
