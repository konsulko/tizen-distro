LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = ""
ALLOW_EMPTY_${PN} = "1"

inherit allarch useradd

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 191 display; -g 100 users; -g 1004 input; -g 190 systemd-journal; -g 54 lock; --system -g 192 weston-launch"

USERADD_PARAM_${PN} = "  -d /run/display -m -u 115  -g display -G users,input,tty,display,video,weston-launch  -s /bin/sh display; "
USERADD_PARAM_${PN} += " -d /home/alice  -m -u 5001 -g users   -G users,display         -r -s /bin/sh alice; "
USERADD_PARAM_${PN} += " -d /home/bob    -m -u 5002 -g users   -G users,display         -r -s /bin/sh bob; "
USERADD_PARAM_${PN} += " -d /home/carol  -m -u 5003 -g users   -G users,display         -r -s /bin/sh carol; "
USERADD_PARAM_${PN} += " -d /home/guest  -m -u 9999 -g users   -G users,display         -r -s /bin/sh guest "
