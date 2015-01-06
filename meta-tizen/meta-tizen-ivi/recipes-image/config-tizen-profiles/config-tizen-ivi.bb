LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = ""
ALLOW_EMPTY_${PN} = "1"

inherit allarch useradd

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 100 users; -g 5000 app; -g 54 lock; -g 190 systemd-journal; --system -g 192 weston-launch "

GROUPADD_PARAM_${PN} += "; --system -g 6001 db_alarm "
GROUPADD_PARAM_${PN} += "; --system -g 6002 db_browser "
GROUPADD_PARAM_${PN} += "; --system -g 6003 db_calendar "
GROUPADD_PARAM_${PN} += "; --system -g 6004 db_cc_list "
GROUPADD_PARAM_${PN} += "; --system -g 6005 db_contact "
GROUPADD_PARAM_${PN} += "; --system -g 6006 db_email_service "
GROUPADD_PARAM_${PN} += "; --system -g 6007 db_java_runtime "
GROUPADD_PARAM_${PN} += "; --system -g 6008 db_logs "
GROUPADD_PARAM_${PN} += "; --system -g 6009 db_memo "
GROUPADD_PARAM_${PN} += "; --system -g 6010 db_menu "
GROUPADD_PARAM_${PN} += "; --system -g 6011 db_msg_service "
GROUPADD_PARAM_${PN} += "; --system -g 6012 db_mtp "
GROUPADD_PARAM_${PN} += "; --system -g 6013 db_spkmgr "
GROUPADD_PARAM_${PN} += "; --system -g 6014 db_t9buffer "
GROUPADD_PARAM_${PN} += "; --system -g 6015 db_worldclock "
GROUPADD_PARAM_${PN} += "; --system -g 6016 db_sns "
GROUPADD_PARAM_${PN} += "; --system -g 6017 db_filemanager "
GROUPADD_PARAM_${PN} += "; --system -g 6018 db_daily_briefing "
GROUPADD_PARAM_${PN} += "; --system -g 6019 db_always "
GROUPADD_PARAM_${PN} += "; --system -g 6020 db_media_browser "
GROUPADD_PARAM_${PN} += "; --system -g 6021 db_music "
GROUPADD_PARAM_${PN} += "; --system -g 6022 db_drm "
GROUPADD_PARAM_${PN} += "; --system -g 6023 db_lbs_landmark "
GROUPADD_PARAM_${PN} += "; --system -g 6024 db_comm "
GROUPADD_PARAM_${PN} += "; --system -g 6025 db_quickpanel "
GROUPADD_PARAM_${PN} += "; --system -g 6026 db_wrt "



USERADD_PARAM_${PN} += "   -u 116 -d /home/genivi -m -g users -G users,input,tty,video,weston-launch -r -s /bin/sh genivi  "
USERADD_PARAM_${PN} += ";  -u 5000 -d /home/app    -m -g users -G users,weston-launch,tty -r -s /bin/sh app  "
USERADD_PARAM_${PN} += ";          -d /usr/apps -m -g root  --system  -s /bin/false tizenglobalapp "
