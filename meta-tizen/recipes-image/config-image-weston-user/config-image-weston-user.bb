SUMMARY = "Add the user app to the image"
DESCRIPTION = "This is a modified version of meta-skeleton/recipes-skeleton/useradd/useradd-example.bb"
SECTION = "user"
PR = "r1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = "file://weston.ini \
           file://BackGround.jpg \
           file://terminal.png \
           "

S = "${WORKDIR}"

PACKAGES = "${PN}"

PROVIDES = "config-image-weston-user"
RDEPENDS_${PN} = "weston"

inherit useradd

# You must set USERADD_PACKAGES when you inherit useradd. This
# lists which output packages will include the user/group
# creation code.
USERADD_PACKAGES = "${PN}"

# You must also set USERADD_PARAM and/or GROUPADD_PARAM when
# you inherit useradd.

# GROUPADD_PARAM works the same way, which you set to the options
# you'd normally pass to the groupadd command. This will create
# group gopencpn and weston-launch:

GROUPADD_PARAM_${PN} = "-g 5000 app; weston-launch; -g 20 dialout ; -g 29 audio ; -g 44 video ; -g 100 users ; -g 6001 db_alarm ; -g 6002 db_browser ; -g 6003 db_calendar ; -g 6004 db_cc_list ; -g 6005 db_contact ; -g 6006 db_email_service ; -g 6007 db_java_runtime ; -g 6008 db_logs ; -g 6009 db_memo ; -g 6010 db_menu ; -g 6011 db_msg_service ; -g 6012 db_mtp ; -g 6013 db_spkmgr ; -g 6014 db_t9buffer ; -g 6015 db_worldclock ; -g 6016 db_sns ; -g 6017 db_filemanager  ; -g 6019 db_always ; -g 6020 db_media_browser ; -g 6021 db_music ; -g 6022 db_drm ; -g 6023 db_lbs_landmark ; -g 6024 db_comm ; -g 6025 db_quickpanel ; -g 6026 db_wrt ; -g 6501 camera ; -g 6502 message ; -g 6503 myfiles ; -g 6505 pulse-access ; -g 6506 pulse-rt ; -g 6509 app_logging ; -g 6527 sys_logging ; -g 6510 hwcodec ; -g 6508 recording ; -g 6511 java ; -g 6512 radio ; -g 6513 installer ; -g 6517 nfc-manager ; -g 6524 use_cert ; -g 6525 usb_device ; -g 6526 keytone ; -g 6528 video_tel ; -g 6514 vconf_setting ; -g 6515 vconf_hib ; -g 6516 vconf_seven ; -g 6518 vconf_sndprof ; -g 6519 vconf_wifi ; -g 6520 vconf_bt ; -g 6521 vconf_callstate ; -g 6522 vconf_idlelock ; -g 6523 vconf_sync ; -g 6601 ss_drmkey ; -g 6602 ss_ssaccount ; -g 6603 ss_activesync ; -g 6604 ss_privatekey ; -g 6701 system_time ; -g 6702 system_bklight ; -g 6703 system_torch ; -g 6801 lbs ; -g 6802 alarm ; -g 6803 dnet_use ; -g 6804 dnet_setting ; -g 6805 tel_call ; -g 6806 tel_call_info ; -g 6807 tel_msg ; -g 6808 tel_msg_info ; -g 6809 tel_net ; -g 6810 tel_net_info ; -g 6811 tel_gprs ; -g 6812 tel_gprs_info ; -g 6813 tel_sim ; -g 6814 tel_sim_info ; -g 6815 tel_sap ; -g 6816 tel_ss ; -g 6817 tel_ss_info ; -g 6826 tel_sat ; -g 6818 task_mgr ; -g 6819 power_mgr ; -g 6820 permanent ; -g 6821 oom_adj ; -g 6822 soundpath ; -g 6823 asm ; -g 6824 message_sync ; -g 6825 message_lbs ; -g 6827 bt_use ; -g 6828 crash ;"
#GROUPADD_PARAM_${PN} += "; -g 6018 db_daily_briefing"




# USERADD_PARAM specifies command line options to pass to the
# useradd command.
#IPQ7dO.mRBbJ. for tizen
USERADD_PARAM_${PN} = "-d /home/app -u 5000 -g app -G audio,video,sudo,weston-launch,dialout,users,db_alarm,db_browser,db_calendar,db_cc_list,db_contact,db_email_service,db_java_runtime,db_logs,db_memo,db_menu,db_msg_service,db_mtp,db_t9buffer,db_worldclock,db_sns,db_filemanager,db_always,db_media_browser,db_music,db_drm,db_lbs_landmark,db_comm,db_quickpanel,db_wrt,camera,message,myfiles,pulse-access,pulse-rt,app_logging,sys_logging,hwcodec,recording,java,radio,installer,nfc-manager,use_cert,usb_device,keytone,video_tel,vconf_setting,vconf_hib,vconf_seven,vconf_sndprof,vconf_wifi,vconf_bt,vconf_callstate,vconf_idlelock,vconf_sync,ss_drmkey,ss_ssaccount,ss_activesync,ss_privatekey,system_time,system_bklight,system_torch,lbs,alarm,dnet_use,dnet_setting,tel_call,tel_call_info,tel_msg,tel_msg_info,tel_net,tel_net_info,tel_gprs,tel_gprs_info,tel_sim,tel_sim_info,tel_sap,tel_ss,tel_ss_info,tel_sat,task_mgr,power_mgr,permanent,oom_adj,soundpath,asm,message_sync,message_lbs,bt_use,crash -r -s /bin/bash -p IPQ7dO.mRBbJ. app"

do_install () {
	install -d -m 755 ${D}/home/app/.config
	install -d -m 755 ${D}/usr/share/backgrounds/tizen/
	install -d -m 755 ${D}/usr/share/icons/tizen/32x32/
	install -d -m 755 ${D}/usr/share/webapps

	install -p -m 644 weston.ini ${D}/home/app/.config/
	install -p -m 644 BackGround.jpg ${D}/usr/share/backgrounds/tizen/BackGround.jpg

	install -p -m 644 terminal.png  ${D}/usr/share/icons/tizen/32x32/terminal.png
	install -p -m 644 web-browser.png  ${D}/usr/share/icons/tizen/32x32/web-browser.png
	install -p -m 644 go.png ${D}/usr/share/icons/tizen/32x32/go.png

	install -p -m 644 webapps-go.wgt ${D}/usr/share/webapps/webapps-go.wgt

	install -p -m 744 init_wrt-installer.sh ${D}/usr/share/webapps/init_wrt-installer.sh

	# The new user and group are created before the do_install
	# step, so you are now free to make use of them:
	chown -R app:app ${D}/home/app

	mkdir -p ${D}/etc/profile.d

	cat > ${D}/etc/profile.d/webkit.sh <<EOF
export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/5000/dbus/user_bus_socket
export XDG_RUNTIME_DIR=/run/user/5000
export ELM_ENGINE=wayland_egl
export ECORE_EVAS_ENGINE=wayland_egl
EOF

}

FILES_${PN} = "/usr/share/backgrounds/tizen/BackGround.jpg  \
               /home/app/.config/weston.ini \
               /usr/lib/systemd/system/graphical.target.wants/user-session@5000.service \
               /usr/share/icons/tizen/32x32/terminal.png \
               /etc/profile.d/webkit.sh \
               /etc/sysconfig \
               /etc/profile.d/user-dbus.sh \
               /usr/lib/systemd/user/default.target \
               /etc/udev/rules.d/99-dri.rules \
               /usr/share/webapps/init_wrt-installer.sh \
	       "

# Prevents do_package failures with:
# debugsources.list: No such file or directory:
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

pkg_postinst_${PN} () {
# base-weston-default.post
mkdir -p ${D}/usr/lib/systemd/system/graphical.target.wants
ln -sf ../user-session@.service ${D}/usr/lib/systemd/system/graphical.target.wants/user-session@5000.service
mkdir -p ${D}/usr/lib/systemd/user
ln -sf weston.target  ${D}/usr/lib/systemd/user/default.target

mkdir -p ${D}/etc/sysconfig

# Add over-riding environment to enable the web runtime to
# run on an IVI image as a different user then the tizen user
cat > ${D}/etc/sysconfig/wrt <<EOF
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/5000/dbus/user_bus_socket
XDG_RUNTIME_DIR=/run/user/5000
ELM_ENGINE=wayland_egl
ECORE_EVAS_ENGINE=wayland_egl
EOF

# Use the same over-rides for the native prelaunch daemon
cp ${D}/etc/sysconfig/wrt ${D}/etc/sysconfig/launchpad

# Add a rule to ensure the app user has permissions to
# open the graphics device
mkdir -p ${D}/etc/udev/rules.d
cat > ${D}/etc/udev/rules.d/99-dri.rules <<EOF
SUBSYSTEM=="drm", MODE="0666"
EOF

# sdx: set DBUS env inside weston shell (login shell)
cat >${D}/etc/profile.d/user-dbus.sh <<EOF
export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/$UID/dbus/user_bus_socket
EOF

chmod u+w $D/etc/sudoers
sed -e 's@# \%sudo@\%sudo@' -i $D/etc/sudoers
chmod u-w $D/etc/sudoers


}
