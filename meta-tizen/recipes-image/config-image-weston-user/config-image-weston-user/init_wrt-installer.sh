echo include /etc/ld.so.conf.d/\*.conf > /etc/ld.so.conf
ldconfig
#ail 
touch /opt/dbspace/.app_info.db
mkdir -p /usr/share/applications
cat > /usr/share/applications/minibrowser.desktop <<EOF
[Desktop Entry]
Encoding=UTF-8
Type=Application
Name=Ephoto
Name[Name]=Ephoto
Name[eo]=EFoto
Name[fr]=EPhoto
Comment=Enlightened Photo Viewer
Comment[eo]=Foto-vidigilo de Enlightenment
Comment[fr]=Visionneuse photo pour Enlightenment
Icon=ephoto
Exec=ephoto
Terminal=false
MimeType=inode/directory;image/png;image/jpeg;image/pjpeg;image/x-xpixmap;image/tiff;image/svg+xml;image/svg+xml-compressed;image/gif;image/x-portable-anymap;image/x-portable-bitmap;image/x-portable-graymap;image/x-portable-pixmap;image/bmp;image/x-bmp;image/x-tga;image/vnd.wap.wbmp;image/webp;image/vnd.microsoft.icon;image/ico;image/x-ico;image/x-win-bitmap;image/vnd.adobe.photoshop;image/x-psd;application/pdf;application/x-pdf;image/pdf;application/postscript;image/x-xcf;image/x-compressed-xcf;
Categories=Graphics;Viewer;
EOF
    
vconftool set -t string db/ail/ail_info "0" -f
vconftool set -t string db/menuscreen/desktop "0" -f
vconftool set -t string db/menu_widget/language "en_US.utf8" -f
CHDBGID="6010"

update_DAC_for_db_file()
{
        if [ ! -f $@ ]; then
                touch $@
        fi

        chown :$CHDBGID $@ 2>/dev/null
        if [ $? -ne 0 ]; then
                echo "Failed to change the owner of $@"
        fi
        chmod 664 $@ 2>/dev/null
        if [ $? -ne 0 ]; then
                echo "Failed to change the perms of $@"
        fi
}

ail_initdb
update_DAC_for_db_file /opt/dbspace/.app_info.db
update_DAC_for_db_file /opt/dbspace/.app_info.db-journal    
        
#pkgmgr_info:

pkg_initdb

/usr/bin/cert_svc_create_clean_db.sh

mkdir -p /opt/share/widget/system
mkdir -p /opt/share/widget/user
mkdir -p /opt/share/widget/exec
mkdir -p /opt/share/widget/data/Public
mkdir -p /usr/lib/wrt-plugins

/usr/bin/wrt_commons_create_clean_db.sh

mkdir -p /usr/etc/ace
mkdir -p /usr/apps/org.tizen.policy

mkdir -p /usr/var/lib/dbus/
dbus-uuidgen > /usr/var/lib/dbus/machine-id
dbus-uuidgen --ensure=/usr/var/lib/dbus/machine-id
        
mkdir -p /var/lib/dbus/
cp /usr/var/lib/dbus/machine-id /var/lib/dbus/

amd &
launchpad_preloading_preinitializing_daemon &
/usr/bin/wrt_launchpad_daemon "                                                                                                                                                                                                         " & 

/usr/bin/wrt_security_create_clean_db.sh       

rm -fr /opt/usr/apps/tmp


mkdir -p /opt/usr/dbspace
/usr/bin/wrt_commons_reset_db.sh
wrt_reset_all.sh

mkdir -p /opt/share/packages


systemctl restart wrt-security-daemon.service
systemctl restart vconf-setup.service
systemctl restart ac.service
systemctl restart security-server.service


dlogctrl set platformlog 1




