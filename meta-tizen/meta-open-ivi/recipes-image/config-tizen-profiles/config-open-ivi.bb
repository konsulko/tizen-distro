LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = ""
ALLOW_EMPTY_${PN} = "1"

inherit allarch useradd

RDEPENDS_${PN} += "pulseaudio"

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 191 display; -g 100 users; -g 1004 input; -g 190 systemd-journal; -g 54 lock; --system -g 192 weston-launch"

USERADD_PARAM_${PN} = "  -d /run/display -m -u 115  -g display -G users,input,tty,display,video,weston-launch  -s /bin/sh display; "
USERADD_PARAM_${PN} += " -d /home/openivi  -m -u 5010 -g users   -G users,display,pulse,audio,cdrom         -r -s /bin/sh openivi "
